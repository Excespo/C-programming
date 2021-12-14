#include<stdio.h>
#include<stdlib.h>

/* INSTRUCTIOJNS of attack lab
 * 1. Set the executability of hex2raw, ctarget and rtarget with `chmod -R 777 file`
 * 2. Run with -q to avoid `FAILED: Initialization error: Running on an illegal host`
 * 3. 简而言之，attack1的原理就是利用函数getbuf中对于buffer长度没有限制的漏洞，将攻击代码注入可执行文件中
 * 4. Phase 1 switch the return adress of test() from 0x1 to touch1()
 * getbuf() shows that it allows an input string of length 0x28(40), and return at 4017bd. So our goal is to overwrite the stack lower than 0x28.
 * touch1() is at 4017c0, to invade the part of test(), input with 40 arbitary bytes and c0 17 40 00 (remind the endian order, and return adress of getbuf() is pointed by %rsp, which is just at the end of the function)
 * 5. Phase 2 wants to switch to touch2(), and in the same time input a val==cookie, stored in %edi
 * So we recover the buffer space and append our attack string. We wrote the assembly code and then dissemble to get the machine code
 * 6. Phase 3 require a structure of injection: %rdi->touch3()->
 * 
 *
*/




int main(void){

    return 0;
}