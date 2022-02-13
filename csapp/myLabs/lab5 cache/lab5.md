# Cache lab

## Part A

目标是写入`csim.c`,使得我们的模拟内存输出和给定的`csim-ref`结果相同.`csim-ref`给出的结果可以在handout文件夹下用指令·`unix >./csim-ref -v -s 4 -E 1 -b 4 -t traces/yi.trace`查看.其中-v是verbose模式,可以去掉

### Rules

内存替换使用的是LRU(least recent use)策略

traces中以I开头的instruction都不需要考虑,特别地,I前没有空格.

### 命令行解析


## Part B