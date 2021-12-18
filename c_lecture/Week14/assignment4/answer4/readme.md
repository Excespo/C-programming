compile answer4 with:

# 1
```bash
$ cd /assignment4/answer4
$ gcc -c llist.c answer4.c
$ gcc -o a.out llist.o answer4.o
$ ./a.out
$ valgrind --leak-check=full --show-leak-kinds=all ./a.out
```

# 2 static lib(.a)
```bash
$ ar -crv libllist.a llist.o
$ gcc answer4.c -L. -lllist -o ans4static.out
$ ./ans4static.out
```
-L search path, -l static lib name

# 3 dynamic lib(.dll)
```bash
$ gcc -c llist.c -fpic -o llist_d.o
$ gcc -shared llist_d.o -fpic -o libllist_d.so
$ gcc answer4.c -L. -lllist -o ans4dyn.out
$ ./ans4dyn.out
```
