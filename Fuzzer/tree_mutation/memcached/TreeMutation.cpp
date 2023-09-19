#include <cstdio>
#include <fstream>  
#include <cstring>
#include <random>
#include <sys/time.h>
#include <ctime>


#include "antlr4-runtime.h"
#include "MemcachedLexer.h"
#include "MemcachedParser.h"
#include "MemcachedBaseVisitor.h"
#include "MemcachedCustomBaseVisitor.h"

#include "nlohmann/json.hpp"

using namespace antlr4;
using namespace std;
// for convenience
using json = nlohmann::json;

extern "C" int init(char* cmd_json_file, char* cmd_related_json_file);
extern "C" int generate(size_t wanted_seed_num, size_t avg_command_num);
extern "C" int parse(char* target, size_t len, char* second, size_t lenS);
extern "C" void fuzz(int index, char** ret, size_t * retlen);

extern "C"  void preprocess(std::string & args, std::vector<std::string >&preprossed);

#define MAXSAMPLES 10000
#define MAXTEXT 200

//https://stackoverflow.com/questions/7114043/random-number-generation-in-c11-how-to-generate-how-does-it-work
typedef std::mt19937 MyRNG;  // the Mersenne Twister with a popular choice of parameters
//uint32_t seed_val = 2323;           // populate somehow
MyRNG rng;                   // e.g. keep one global instance (per thread)

static string ret[MAXSAMPLES + 2];

json commandjs;
json command_related_js;
std::map<std::string, int> cmd_to_js_index_map;
std::map<std::string, int> cmd_to_related_js_index_map;
std::map<std::string, std::vector<std::string>> cmd_to_preprossed_map;
// Save the map from like "key" to concrete values like "key1" "key2"
std::map<std::string, std::vector<std::string>> placeholder_to_concrete_map;

std::uniform_int_distribution<uint32_t> uint_dist10000(0, 10000); // range [0,10000]


//https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
bool replace(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}

//https://stackoverflow.com/questions/53849/how-do-i-tokenize-a-string-in-c
vector<string> split(const char* str, char c = ' ')
{
	vector<string> result;

	do
	{
		const char* begin = str;

		while (*str != c && *str)
			str++;

		result.push_back(string(begin, str));
	} while (0 != *str++);

	return result;
}

// https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
std::string gen_random_string(const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string tmp_s;
	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i) {
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	return tmp_s;
}

// Internal
void preprocess(std::string& args, std::vector<std::string >& preprossed)
{
	// Retain blank args as one item to distinguish two conditions like: ACL CAT [categoryname], 
	// which should contains ACL CAT, ACL CAT categoryname 
	/*
	if (args.length() <= 0) {
		return;
	}*/

	auto index = args.find('[');
	if (index == string::npos)
	{   // No [] things
		auto orIndex = args.find('|');
		if (orIndex == string::npos)
		{   // No | things
			// TODO: add more items for "..."
			replaceAll(args, "...", " ");

			preprossed.push_back(args);
		}
		else
		{
			// From the first '|', find the first blank space (or string end).
			auto endIndex = args.find(' ', orIndex);
			// The end char of a|b|c, i.e., index of c
			int endCharIndex = (endIndex == string::npos) ? args.size() - 1 : endIndex - 1;
			auto beginIndex = args.rfind(' ', orIndex);
			int beginCharIndex = (beginIndex == string::npos) ? 0 : beginIndex + 1;

			std::vector<std::string> options = split(args.substr(beginCharIndex, 
				endCharIndex - beginCharIndex + 1).c_str(), '|');
			for (int i = 0; i < options.size(); i++)
			{
				std::string newarg(args);
				newarg.replace(beginCharIndex, endCharIndex - beginCharIndex + 1, options[i]);
				preprocess(newarg, preprossed);
			}
		}
	}
	else 
	{
		// Find the left match ']' position
		int curExtraLeftOpenBrace = 0;
		int matchRightBraceIndex = -1;
		for (int i = index + 1; i < args.size(); i++)
		{
			if (args[i] == ']') {
				if (curExtraLeftOpenBrace == 0) {
					matchRightBraceIndex = i;
					break;
				}
				else {
					--curExtraLeftOpenBrace;
				}
			}
			else if (args[i] == '[')
			{
				++curExtraLeftOpenBrace;
			}
		}
		// Generage two kinds of subcase for a [b] c: 
		//   (1) a b c
		//   (2) a c
		std::string first(args);
		first.replace(index, 1, " ");
		first.replace(matchRightBraceIndex, 1, " ");
		preprocess(first, preprossed);

		std::string second(args);
		second.erase(index, matchRightBraceIndex - index + 1);
		preprocess(second, preprossed);

	}
}

// Internel method
void init_data()
{
	// https://github.com/memcached/memcached/blob/master/doc/protocol.txt
	placeholder_to_concrete_map = {
		{"flags",{"0", "1", "-1", "1", "2",  "10", "65536",
		"4294967296"}},   //32-bit

		{"exptime", {"-5","-2", "-1", "0", "1", "128", "32", "5", "1000"}},

		{"bytes", { "-1", "0", "1", "2", "10", "128", "32", "5", "100"}},

		{"casunique", {"-5","-2", "-1",  "0", "1", "3", "10", "129", "1000"}}, //64-bit

		{"value", {"-5","-2", "-1",  "0", "1", "3", "10", "129", "1000", "a", "alongstring"}},

		{"microseconds", {"0", "1", "2.5","100","1000"}},

		{"verbositylevel", {"-1", "0", "1", "2", "3", "4", "5", "3300"}},

	};

	// For "key"
	std::vector<std::string> keys;
	std::vector<std::string> prefix = {"key"};
	for (int i = 0; i < prefix.size(); i++) {
		for (int j = 0; j < 5; j++) {
			std::string a(prefix[i]+ std::to_string(j));
			keys.push_back(a);
		}
	}
	placeholder_to_concrete_map.emplace("key", keys);


	// For start end  offset index
	std::vector<std::string> values = placeholder_to_concrete_map["bytes"];
	placeholder_to_concrete_map.emplace("datalen", values);
	placeholder_to_concrete_map.emplace("32u", values);
	placeholder_to_concrete_map.emplace("megabytes", values); 

	// For seconds  milliseconds
	placeholder_to_concrete_map.insert({ "delay", placeholder_to_concrete_map["exptime"] });


	
}

/* Get unix time in milliseconds */

static uint64_t get_cur_time(void) {

	struct timeval tv;
	struct timezone tz;

	gettimeofday(&tv, &tz);

	return (tv.tv_sec * 1000ULL) + (tv.tv_usec / 1000);

}

int init(char* cmd_json_file, char* cmd_related_json_file)
{
	//rng.seed(seed_val);
	rng.seed(get_cur_time());

	// read JSON files
	std::ifstream is(cmd_json_file);
	is >> commandjs;
	//std::ifstream is2(cmd_related_json_file);
	//is2 >> command_related_js;

	if (commandjs.empty()) {
		cout << "No commands! Please check the cmd_json_file:" << cmd_json_file << endl;
	}
	/*if (command_related_js.empty()) {
		cout << "No related-commands! Please check the cmd_related_json_file:" << cmd_related_json_file << endl;
	}*/

	for (int i = 0; i < commandjs.size(); i++)
	{
		std::string cmdName = commandjs[i]["command"].get<std::string>();
		cmd_to_js_index_map.insert({cmdName, i});
		std::string args = commandjs[i]["args"].get<std::string>();
		std::vector<std::string> preposed;
		preprocess(args, preposed);
		cmd_to_preprossed_map.insert({ cmdName, preposed });
		//cout << "\"" << cmdName << "\"" << endl;
	}

	/*for (int i = 0; i < command_related_js.size(); i++)
	{
		std::string cmdName = command_related_js[i]["command"].get<std::string>();
		cmd_to_related_js_index_map.insert({ cmdName, i });
	}*/

	init_data();

	return 0;
}

// Internal method
std::string generate_one_command(json& cmd)
{
	std::string a;
	std::string cmd_name = cmd["command"];
	std::string cmd_args = cmd["args"];
	int need_extra_block = 0; // For memcached's <data block>\r\n, which is only needed for special cmds.
	int need_block_len = 0;
	if (cmd_to_preprossed_map.find(cmd_name) != cmd_to_preprossed_map.end())
	{
		std::vector<std::string > processed = cmd_to_preprossed_map[cmd_name];
		if (processed.size() > 0) {
			int select = uint_dist10000(rng) % processed.size();
			cmd_args = processed[select];
		}
	}
	//cout << "cmd:" << cmd_name << " args:" << cmd_args << endl;
	a.append(cmd_name);
	a.append(" ");

	if (cmd_args.size() >= 0)
	{
		vector<std::string> tokens = split(cmd_args.c_str());
		for (int i = 0; i < tokens.size(); i++)
		{
			std::string t = tokens[i];
			if (std::islower(t[0]))
			{
				if (placeholder_to_concrete_map.find(t) != placeholder_to_concrete_map.end())
				{
					// If found, it's placeholder like "key", replace it
					vector<std::string> values = placeholder_to_concrete_map[t];
					int select = uint_dist10000(rng) % values.size();
					a.append(values[select]);
					a.append(" ");
					if (t == "bytes" || t == "datalen") {
						need_extra_block = 1;
						need_block_len = std::stoi(values[select]);
					}
					continue;
				}
			}

			// Ordinary string
			a.append(t);
			a.append(" ");
		}
	}

	a.append("\r\n");

	if (need_extra_block)
	{
		std::string str = gen_random_string(std::min(std::max(1, need_block_len), 100));
		a.append(str);
		a.append("\r\n");
	}

	return a;
}

int generate(size_t wanted_seed_num, size_t avg_command_num) {
	int num_of_smaples = 0;
	std::normal_distribution<double> normal_dist(0, 2);       // N(mean, stddeviation)
	std::uniform_int_distribution<uint32_t> uint_dist(0, commandjs.size()-1); // range [0,commandjs.size()-1]
	for (int i = 0; i < wanted_seed_num; i++)
	{
		std::string s;
		int cmd_num = 0;
		while (cmd_num <= 0) {
			cmd_num = std::ceil(normal_dist(rng) + avg_command_num);
		}
		json main_cmd = commandjs[uint_dist(rng)];
		//cout << "choose main cmd:" << main_cmd["command"] <<" total cmd_num "<< cmd_num<< endl;
		//std::string cmdname = main_cmd["command"];
		//json related = command_related_js[cmd_to_related_js_index_map[cmdname]];
		//json related_list = related["related command"];
		//std::uniform_int_distribution<uint32_t> uint_dist_rel(0, related_list.size() - 1);
		json next_cmd = main_cmd;
		for (int j = 0; j < cmd_num; j++)
		{
			std::string one = generate_one_command(next_cmd);
			s.append(one);
			next_cmd = commandjs[uint_dist(rng)];
			/*int sel_index = uint_dist_rel(rng);
			std::string name = related_list[sel_index].get<std::string>();
			if (cmd_to_js_index_map.find(name) != cmd_to_js_index_map.end()) {
				int next_index = cmd_to_js_index_map[name];
				next_cmd = commandjs[next_index];
			}*/
		}
		//cout << "generated seed " << i <<": "<< s << endl;
		ret[num_of_smaples++] = s;
		if (num_of_smaples >= MAXSAMPLES)break;
	}
	return num_of_smaples;
}



int parse(char* target, size_t len, char* second, size_t lenS) {
	vector<misc::Interval> intervals;
	intervals.clear();
	vector<string> texts;
	texts.clear();
	int num_of_smaples = 0;
	//parse the target
	string targetString;
	try {
		targetString = string(target, len);
		ANTLRInputStream input(targetString);
		MemcachedLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		TokenStreamRewriter rewriter(&tokens);
		MemcachedParser parser(&tokens);
		tree::ParseTree* tree = parser.commands();
		if (parser.getNumberOfSyntaxErrors() > 0) {
			//std::cerr<<"NumberOfSyntaxErrors:"<<parser.getNumberOfSyntaxErrors()<<endl;
			return 0;
		}
		MemcachedCustomBaseVisitor* visitor = new MemcachedCustomBaseVisitor(tokens);
		visitor->visit(tree);
		int interval_size = visitor->intervals.size();
		for (int i = 0; i < interval_size; i++) {
			if (find(intervals.begin(), intervals.end(), visitor->intervals[i]) != intervals.end()) {
			}
			else if (visitor->intervals[i].a <= visitor->intervals[i].b) {
				intervals.push_back(visitor->intervals[i]);
			}
		}
		int texts_size = visitor->texts.size();
		for (int i = 0; i < texts_size; i++) {
			if (find(texts.begin(), texts.end(), visitor->texts[i]) != texts.end()) {
			}
			else if (visitor->texts[i].length() > MAXTEXT) {
			}
			else {
				texts.push_back(visitor->texts[i]);
			}
		}
		delete visitor;

        //parse sencond
        string secondString;
        try {
            secondString = string(second, lenS);
            //cout<<targetString<<endl;
            //cout<<secondString<<endl;

            ANTLRInputStream inputS(secondString);
			MemcachedLexer lexerS(&inputS);
            CommonTokenStream tokensS(&lexerS);
			MemcachedParser parserS(&tokensS);
            tree::ParseTree* treeS = parserS.commands();

            if (parserS.getNumberOfSyntaxErrors() > 0) {
                //std::cerr<<"NumberOfSyntaxErrors S:"<<parserS.getNumberOfSyntaxErrors()<<endl;
            }
            else {
				MemcachedCustomBaseVisitor* visitorS = new MemcachedCustomBaseVisitor(tokensS);
                visitorS->visit(treeS);
                texts_size = visitorS->texts.size();
                for (int i = 0; i < texts_size; i++) {
                    if (find(texts.begin(), texts.end(), visitorS->texts[i]) != texts.end()) {
                    }
                    else if (visitorS->texts[i].length() > MAXTEXT) {
                    }
                    else {
                        texts.push_back(visitorS->texts[i]);
                    }
                }
                delete visitorS;
            }

            interval_size = intervals.size();
            sort(texts.begin(), texts.end());
            texts_size = texts.size();


            for (int i = 0; i < interval_size; i++) {
                for (int j = 0; j < texts_size; j++) {
                    rewriter.replace(intervals[i].a, intervals[i].b, texts[j]);
                    ret[num_of_smaples++] = rewriter.getText();
                    if (num_of_smaples >= MAXSAMPLES)break;
                }
                if (num_of_smaples >= MAXSAMPLES)break;
            }

            //std::cout << tree->toStringTree(&parserS) << std::endl << std::endl;
        }
        catch (range_error e) {
            //std::cerr<<"range_error"<<second<<endl;
        }
		catch (...) {
			// include std::invalid_argument
		}
	}
	catch (range_error e) {
		//std::cerr<<"range_error:"<<target<<endl;
	}
	catch (...) {
		// include std::invalid_argument
	}

	return num_of_smaples;
}


void fuzz(int index, char** result, size_t* retlen) {
	*retlen = ret[index].length();
	*result = strdup(ret[index].c_str());
}