Info for CS:APP

# Websites

[CSAPP CMU homepage](http://www.cs.cmu.edu/afs/cs/academic/class/15213-f15/www/index.html)

[Lecture videos on Bilibili](https://www.bilibili.com/video/BV1iW411d7hd?p=1)

[Lab from NJU](https://nju-projectn.github.io/ics-pa-gitbook/ics2019/)

# Books

Refer to the book list [here](../README.md)

# (anti) assembly

```bash
gcc (-Og) -S -o hello.s hello.c
```

```bash
gcc -c -o hello.o hello.c
objdump -s -d hello.o > hello.o.txt
```