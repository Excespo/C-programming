#include<stdio.h>
#include<stdlib.h>

void bomb1(void);
void bomb2(void);
void bomb3(void);
void bomb4(void);
void bomb5(void);
void bomb6(void);
void secret(void);


int main(void){
    /*
    Of course no support/h or else, the assignment requires you to guess what's in these .h
    */
   bomb1();
   bomb2();
   bomb3();
   bomb4();
   bomb5();
   bomb6();
   secret();
   return 0;
}
void bomb1(){
    /*
    Look function <phase_1>, the couple `sub $0x8, %rsp` and `add $0x8,%rsp` corresponds clearly to the stack allocation and free.

    then it move $0x402400 to register %esi, call <strings_not_equal>, use its return value in %rax to test if it's 0. if 0, jump over the <explode_bomb>. That's what we expect.

    Then look <strigns_not_equal> at 401338. We notice that two params in %rdi and %rsi are moved into %rbx and %rbp, that's probably the string input and the comparison. So we guess content at $0x402400 is the password.

    with `gdb ./bomb` -> `print (char*)0x402400` or `x /s 0x402400` we get:
    "Border relations with Canada have never been better."
    */
   printf("Password for phase1:\n");
   printf("Border relations with Canada have never been better.\n");
}

void bomb2(void){
    /* 
    it allocates a space of 40 bytes(0x28), then jump to func <read_six_numbers>. To justify what it will do, we track the most-seemingly input sentence, that is `mov $0x4025c3,%esi`, with `print (char*)0x4025c3` we get "%d %d %d %d %d %d". That corresponds to our imagination.

    Then to find the six numbers.
    Search in <phase_2>, first it compares $0x1 and (%rsp), (maybe rsp is callee-saved?)

    if not jump to 400f30, it explode. so first input is 0x1.

    Only safe traack is 400f30->400f17->400f25->400f17(a recursion)/->400f3c(stop condition, free the stack)

    if undergoing the recursion at 400f17, it compares %eax with (%rbx) with %eax = 2*((%rbx)-0x4), that is twice the previous number of %rbx. Or to say, it's a geometric sequence!

    and the final stop condition is compare %rbp with %rbx. %rbx is always the next number in the sequence, while %rbp get value from %rsp+0x18, that's the 7th element.(Is that a over boundary operation??)
    After all, 1 2 4 8 16 32 is the right password.
     *
     *
    */   
   printf("Password for phase2:\n");
   printf("%d %d %d %d %d %d\n",1,2,4,8,16,32);
}

void bomb3(void){
    /*
    Similarly, by looking 0x4025cf, we can know that we get in 2 int. Likely stored in %rdx, %rcx

    So much jmp-related command, guess it's a switch jump table.Finally at 400fbe we get through if %eax = %rsp+0xc. Above these are cases that give %eax a value. %rsp+0xc relates to %rcx

    400f75, jump to 8*%rax+402470, which shows that %rax is the index and jump to the case corresponded.(else, %eax is limited between 1 and 7)

    and more, %eax get first value from %rdx(1st arg), then in each case it gets 2nd value. Jump to 400fbe compare its value with %rcx(2nd arg)

    Only to search one case. For example `print *(0x402470+7*0x8)` give in hex 400fa6, %eax get value 0x147.

    As for input order, later one get lower addres by %rsp. that's to say %rsp+0xc is the later input.
    */
   printf("Password for phase3(Possible one):\n");
   printf("%d %d\n",7,327);
}

void bomb4(void){
    /*
    2 int input, 1st in %rdx and 2nd in %rcx(total 24bytes)

    condition to explode. return value of <func4> in %eax not 0, or 2nd arg not 0. 2nd arg<=0xe

    <func4> get in args %edx=0xe, %esi=0x0,%edi=1st arg
    the most simple case is arg1 = 0
    */
   printf("Password for phase4(Possible one):\n");
   printf("%d %d\n",0,0);
}

void bomb5(void){
    /*
    Notice <string_length> should return 6, and <strings_not_equal> with $0x40245e in %esi, "flyers" compared with %rdi=%rsp+0x10

    How to get "flyers"? from 40108b to 4010ac we get a cycle with ending condition is %rax give 0x6, and iteration ascend %rax by 1, initial value of %rax is 0 in 4010d2

    inside the iteration,40108b show that we take strings at %rbx with index %rax and take only low 4 digits, then 4010a0 input 6 values with %rax being the index of the array at 0x4024b0. 

    after the iteration, strings locate at %rsp+0x10 to %rsp+0x16(which is a zero flag).
    
    the procedure is not clear but we can guess that char in "flyers" is got from lower 4 digits of input string.

    */
   printf("Password for phase5(Possible one):\n");
   printf("IONEFG\n");
}

void bomb6(void){
   printf("Password for phase6:\n");
   printf("%d %d %d %d %d %d\n",4,3,2,1,6,5);
}

void secret(void){
    /*
    secret phase can be found in the func <phase_defused>, so every bomb there is an access.

    */
    ;
}