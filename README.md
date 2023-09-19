# DAFuzz
DAFuzz: data-aware fuzzing of in-memory data stores


## Install
The process is similar to Superion (https://github.com/zhunki/Superion), but we changed to a newer version of ANTLR. 
After installation, you should get fuzzer binaries including afl-fuzz-redis, and afl-fuzz-memcached.

## Run
Command like:
```
USE_RAW_FORMAT=1 LD_PRELOAD=/<pathto>/desockmulti.so LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/<pathtothefuzzer>/tree_mutation/redis/:./  /<pathtothefuzzer>/afl-fuzz-redis -D -F redis_command.json -G redis_command_related.json -d -m 1G -x redis_zeng2.dict -i testcase_dir -o findings_dir_me_d -- ./redis-server --dbfilename zeng2.rdb  --bind 127.0.0.1 
```

## Citation
Please cite our paper if you use it in research.

Zeng Y, Zhu F, Zhang S, Yang Y, Yi S, Pan Y, Xie G, Wu T. 2023. DAFuzz: data-aware fuzzing of in-memory data stores. PeerJ Computer Science 9:e1592 https://doi.org/10.7717/peerj-cs.1592
