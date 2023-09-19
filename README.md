# DAFuzz
DAFuzz: data-aware fuzzing of in-memory data stores


## Install
Similiar to Superion. 
Should get fuzzer binary like afl-fuzz-redis.

## Run
Command like:
    USE_RAW_FORMAT=1 LD_PRELOAD=/<pathto>/desockmulti.so LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/<pathtothefuzzer>/tree_mutation/redis/:./  /<pathtothefuzzer>/afl-fuzz-redis -D -F redis_command.json -G redis_command_related.json -d -m 1G -x redis_zeng2.dict -i testcase_dir -o findings_dir_me_d -- ./redis-server --dbfilename zeng2.rdb  --bind 127.0.0.1 