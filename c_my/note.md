
**NOTEBOOK FOR MY LEARNING ON C**

- [1. Code standards](#1-code-standards)
- [2. Tools](#2-tools)
  - [2.1. vim](#21-vim)
  - [2.2. code-runner](#22-code-runner)
- [3. C in command line](#3-c-in-command-line)
  - [3.1. check environment](#31-check-environment)
  - [3.2. compile and run code](#32-compile-and-run-code)
- [4. Basic grammar for C](#4-basic-grammar-for-c)
  - [4.1. basic structure for c code](#41-basic-structure-for-c-code)
  - [4.2. basic data type for c](#42-basic-data-type-for-c)
  - [4.3. variables for c](#43-variables-for-c)
  - [4.4. constants for c](#44-constants-for-c)
  - [4.5. printf](#45-printf)
  - [4.6. usage of argc& argv](#46-usage-of-argc-argv)
  - [4.7. scope](#47-scope)
- [5. Pointer in C](#5-pointer-in-c)
  - [5.1. pointer arithmetics](#51-pointer-arithmetics)
  - [5.2. pointer and array](#52-pointer-and-array)
  - [5.3. struct](#53-struct)
    - [5.3.1. two types to define a structure](#531-two-types-to-define-a-structure)
    - [5.3.2. size of struct](#532-size-of-struct)
    - [5.3.3. pointer in struct](#533-pointer-in-struct)
    - [5.3.4. function in struct(function pointer)](#534-function-in-structfunction-pointer)
  - [5.4. linked list](#54-linked-list)
  - [5.5. size of pointer in 64-bit system](#55-size-of-pointer-in-64-bit-system)
- [6. Advanced character](#6-advanced-character)
  - [6.1. header guard](#61-header-guard)
  - [6.2. do while0 for macro protection](#62-do-while0-for-macro-protection)
  - [6.3. macro extention rules](#63-macro-extention-rules)
  - [6.4. typeof](#64-typeof)


# 1. Code standards

[HUAWEI standard](https://zhuanlan.zhihu.com/p/346160926)

# 2. Tools

## 2.1. vim

vim newfile

i - insert mode

ECS - back to command mode

w - write/save

z - exit

*zz/shift+zz* - forced save+exit(**useful!**)

## 2.2. code-runner

default config for c: 
```js
"c": "cd $dir && gcc $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
```

change with
```js
"c": "cd $dir && gcc $fileName -o $fileNameWithoutExt.o && $dir$fileNameWithoutExt.o"
```

# 3. C in command line

## 3.1. check environment

gcc -v: check the installation for gnu compiler collection

##  3.2. compile and run code

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

#  4. Basic grammar for C 

## 4.1. basic structure for c code

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

## 4.2. basic data type for c
| type | size  | range                                          |
| ---- | ----- | ---------------------------------------------- |
| int  | 1byte | -32,768to32,767or-2,147,483,648to2,147,483,647 |
| char | 1byte | -128to127or0to255                              |

datasize for example, [datasize.c](./support-notemd/datasize.c)

## 4.3. variables for c

## 4.4. constants for c
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

## 4.5. printf

[ref](http://c.biancheng.net/cpp/html/33.html)

in brief,
| character  | correponding type  |
|---|---|
|  %d | int  |
| %o | oct |
| %x | hex |
| %u | unsigned int |
| %f | float or double |
| %s | string |
| %p | pointer |

## 4.6. usage of argc& argv

```argc``` signify the total amount of parameters in command line

```argv``` signify the content in command line, ```argv[0]```, particularly the name of the programme

[argc argv example](support-notemd/argc_argv.c), usage: 
```bash
./a.out xu neng shi sha bi
```

## 4.7. scope

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

# 5. Pointer in C

## 5.1. pointer arithmetics

just look at [this](support-notemd/pointers/arithmetic.c), pointer is clever to determine the size of pointer so ```pointer+=n``` just mean n step move

further usage like n-dim pointer to array ```*(*(p+1)+1)``` means 1 step in 2nd-dim and 1 step in 1st-dim

## 5.2. pointer and array

**manipulate an array by a pointer**, for example we have a 2-dimensional array ```arr[m][n]```

```int (*p)[n] = arr``` imply that :

- p is a pointer because of ```(*p)```
- the data type of p is ```int [n]```, which is exactly the size of each row of ```arr```
- by operator ```sizeof``` we can verify the statement above
- therefore ```p``` is linked to the memory adress of row 0 of ```arr```, and ```(p+1)``` is the row 1 

## 5.3. struct

### 5.3.1. two types to define a structure

```c
struct point{
  int x;
  int y
};

struct point p;
```

equals to:

```c
typedef struct point{
  int x;
  int y;
}p;
```
### 5.3.2. size of struct

first, rule of [alignment of memory](https://zhuanlan.zhihu.com/p/30007037)

[size of list node struct](https://blog.csdn.net/ALexander_Monster/article/details/106178159), but there is a mismatch with ```malloc()``` allocate 32bit and my node struct is of size 24bit

[mismatch code](support-notemd/pointers/linked_list.c), run and see 24!=32

reason why ```malloc()``` doesn't allocate a corresponding size to ```size_t``` is [that](https://blog.csdn.net/weixin_44732817/article/details/88530993) and [that(part2)](https://blog.csdn.net/weixin_44732817/article/details/88566962)

### 5.3.3. pointer in struct

as for ```struct *node```
```c
(*node).value
```

equals to
```c
node -> value
```

### 5.3.4. function in struct(function pointer)

can use it to make struct like a class object, [explain here](https://blog.csdn.net/wujiangguizhen/article/details/17153495), other usage not yet clear

## 5.4. linked list

## 5.5. size of pointer in 64-bit system

1 hex number = 4 binary number

1 byte = 8 bit = 2 hex number

64 bit = 8 byte = 16 hex number

but in fact, 16/64 are left and unused, so length of a pointer printed by ```printf("%p",&n)``` is 0x+12digits

besides, print with ```%x``` or ```%ls``` will lead to wrong output because of the mismatching of length.

[ref](https://zhuanlan.zhihu.com/p/216745184)

# 6. Advanced character

## 6.1. header guard

use ```#define```, ```#ifdef```, ```#ifndef```, ```#endif``` to prevent the case of multi-include

[header guard example](support-notemd/header_guard/main.c)

## 6.2. do while0 for macro protection

To avoid incorrect macro extension in some cases.

[reference: explain fonction of do while0](https://www.jianshu.com/p/99efda8dfec9)

## 6.3. macro extention rules

[reference: explain rules of macro](https://zhuanlan.zhihu.com/p/125062325)

[example for macro extention(prescaning)](support-notemd/macro_extension.c)


## 6.4. typeof

[reference 还没看懂](https://blog.csdn.net/zhanshen2015/article/details/51495273)
