# notebook for my C programming lesson


- [notebook for my C programming lesson](#notebook-for-my-c-programming-lesson)
  - [vim(linux)](#vimlinux)
  - [check env for c](#check-env-for-c)
  - [basic structure for c code](#basic-structure-for-c-code)
  - [compile and run code](#compile-and-run-code)
  - [basic grammar for c](#basic-grammar-for-c)
  - [basic data type for c](#basic-data-type-for-c)
  - [variables for c](#variables-for-c)
  - [constants for c](#constants-for-c)
  - [usage of argc& argv](#usage-of-argc-argv)
  - [header guard](#header-guard)


## vim(linux)

vim newfile

i - insert mode

ECS - back to command mode

w - write/save

z - exit

*zz/shift+zz* - forced save+exit(**useful!**)

## check env for c

gcc -v: check the installation for gnu compiler collection

## basic structure for c code

example: [hello.c](support-notemd/hello.c
)
```c
#include <stdio.h>
 
int main()
{
   /* 我的第一个 C 程序 */
   printf("Hello, World! \n");
 
   return 0;
}
```

## compile and run code

For a single source code file:
```bash
$ gcc hello.c
$ ./a.out
```
For many:
```bash
$ gcc test1.c test2.c -o main.out
$ ./main.out
```

Or simply run in vscode with code runner plugin

## basic grammar for c
- ATTENTION: semi-colon ;
- comment: ```//``` for single-line, ```/* */```for multi-lines


## basic data type for c
| type  |  size | range|
|---|---|---|
|int |1byte |-32,768to32,767or-2,147,483,648to2,147,483,647|
|char |1byte |-128to127or0to255|

datasize for example, [datasize.c](./support-notemd/datasize.c)

## variables for c

## constants for c
integer constant can be 8-base, 10-base or 16-base,

prefix ```0``` for octal, ```0x``` for hexa,

suffix ```U/u``` for unsigned, ```L/l``` for long
```c
212         /* 合法的 */
215u        /* 合法的 */
0xFeeL      /* 合法的 */
078         /* 非法的：8 不是八进制的数字 */
032UU       /* 非法的：不能重复后缀 */
```

## usage of argc& argv

## header guard

use ```#define```, ```#ifdef```, ```#ifndef```, ```#endif``` to prevent the case of multi-include

[header guard example](support-notemd/header_guard/main.c)