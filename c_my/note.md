# notebook for my C programming lesson

- [notebook for my C programming lesson](#notebook-for-my-c-programming-lesson)
  - [code standards](#code-standards)
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
  - [do while0 for macro protection](#do-while0-for-macro-protection)
  - [macro extention rules](#macro-extention-rules)
  - [scope](#scope)

## code standards

[HUAWEI standard](https://zhuanlan.zhihu.com/p/346160926)

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

Detailed process of ```gcc```: 

.c -> .i (pre-processing, ```gcc -E```)

.i -> .s (compiling, ```gcc -S```)

.s -> .o (assembling, ```gcc -C```)

.o -> .exe/.out (windows or linux) (linking, ```gcc -o```)

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

```argc``` signify the total amount of parameters in command line

```argv``` signify the content in command line, ```argv[0]```, particularly the name of the programme

[argc argv example](support-notemd/argc_argv.c), usage: 
```bash
./a.out xu neng shi sha bi
```

## header guard

use ```#define```, ```#ifdef```, ```#ifndef```, ```#endif``` to prevent the case of multi-include

[header guard example](support-notemd/header_guard/main.c)

## do while0 for macro protection

To avoid incorrect macro extension in some cases.

[reference: explain fonction of do while0](https://www.jianshu.com/p/99efda8dfec9)

## macro extention rules

[reference: explain rules of macro](https://zhuanlan.zhihu.com/p/125062325)

[example for macro extention(prescaning)](support-notemd/macro_extension.c)

## scope

static: [example for static](support-notemd/action_scope/static.c)
- As for variables,they are by default local to the scope, therefore within function variables are freed after the function is executed. ```static``` is used to retain values, make the variable legal to be visited within the code file.
- As for functions, ```static``` reduce the scope of function to the file containing it.

global

opposite to ```static```, extend the scope to outside the file

extern

- ```extern``` (```global``` not) is a keyword in C, showing that the variable isn't define in this file. Compared to ```global``` which refer to the scope, ```extern``` act as a link to a definition elsewhere. Generally, a global argument is defined in source file ```.c```, in order to just include ```.h```, we add ```extern int arg``` in ```.h```.
- As for functions, ```extern``` implys that the function is defined elsewhere.
- Difference between declaration and definition: for variables, ```type name``` is always a definition and can be exceuted only once. A single ```extern``` act as a link(declaration to pass preprocess, but detailed definition can be located elsewhere); for functions, ```int func(int arg);``` without ```{}```, with comma ```;```,  is a declaration. Therefore ```extern``` can be omitted in this case.

[reference extern, global, static](https://www.runoob.com/w3cnote/extern-head-h-different.html)