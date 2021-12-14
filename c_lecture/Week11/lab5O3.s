
lab5O3.o:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 7a 2f 00 00    	pushq  0x2f7a(%rip)        # 3fa0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 7b 2f 00 00 	bnd jmpq *0x2f7b(%rip)        # 3fa8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	pushq  $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmpq 1020 <.plt>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	pushq  $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmpq 1020 <.plt>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	pushq  $0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmpq 1020 <.plt>
    107f:	90                   	nop

Disassembly of section .plt.got:

0000000000001080 <__cxa_finalize@plt>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	f2 ff 25 6d 2f 00 00 	bnd jmpq *0x2f6d(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    108b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001090 <putchar@plt>:
    1090:	f3 0f 1e fa          	endbr64 
    1094:	f2 ff 25 15 2f 00 00 	bnd jmpq *0x2f15(%rip)        # 3fb0 <putchar@GLIBC_2.2.5>
    109b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010a0 <__stack_chk_fail@plt>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	f2 ff 25 0d 2f 00 00 	bnd jmpq *0x2f0d(%rip)        # 3fb8 <__stack_chk_fail@GLIBC_2.4>
    10ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010b0 <malloc@plt>:
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	f2 ff 25 05 2f 00 00 	bnd jmpq *0x2f05(%rip)        # 3fc0 <malloc@GLIBC_2.2.5>
    10bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010c0 <__printf_chk@plt>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	f2 ff 25 fd 2e 00 00 	bnd jmpq *0x2efd(%rip)        # 3fc8 <__printf_chk@GLIBC_2.3.4>
    10cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010d0 <__isoc99_scanf@plt>:
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	f2 ff 25 f5 2e 00 00 	bnd jmpq *0x2ef5(%rip)        # 3fd0 <__isoc99_scanf@GLIBC_2.7>
    10db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000010e0 <main>:
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	48 83 ec 48          	sub    $0x48,%rsp
    10e8:	bf 01 00 00 00       	mov    $0x1,%edi
    10ed:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    10f4:	00 00 
    10f6:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
    10fb:	31 c0                	xor    %eax,%eax
    10fd:	e8 5e 01 00 00       	callq  1260 <addpersons>
    1102:	48 89 e2             	mov    %rsp,%rdx
    1105:	bf 01 00 00 00       	mov    $0x1,%edi
    110a:	48 8d 35 47 0f 00 00 	lea    0xf47(%rip),%rsi        # 2058 <_IO_stdin_used+0x58>
    1111:	f3 0f 6f 00          	movdqu (%rax),%xmm0
    1115:	0f 29 04 24          	movaps %xmm0,(%rsp)
    1119:	f3 0f 6f 48 10       	movdqu 0x10(%rax),%xmm1
    111e:	8b 4c 24 0c          	mov    0xc(%rsp),%ecx
    1122:	0f 29 4c 24 10       	movaps %xmm1,0x10(%rsp)
    1127:	f3 0f 6f 50 20       	movdqu 0x20(%rax),%xmm2
    112c:	0f 29 54 24 20       	movaps %xmm2,0x20(%rsp)
    1131:	48 8b 40 30          	mov    0x30(%rax),%rax
    1135:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
    113a:	31 c0                	xor    %eax,%eax
    113c:	e8 7f ff ff ff       	callq  10c0 <__printf_chk@plt>
    1141:	bf 0a 00 00 00       	mov    $0xa,%edi
    1146:	e8 45 ff ff ff       	callq  1090 <putchar@plt>
    114b:	48 8b 44 24 38       	mov    0x38(%rsp),%rax
    1150:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1157:	00 00 
    1159:	75 07                	jne    1162 <main+0x82>
    115b:	31 c0                	xor    %eax,%eax
    115d:	48 83 c4 48          	add    $0x48,%rsp
    1161:	c3                   	retq   
    1162:	e8 39 ff ff ff       	callq  10a0 <__stack_chk_fail@plt>
    1167:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    116e:	00 00 

0000000000001170 <_start>:
    1170:	f3 0f 1e fa          	endbr64 
    1174:	31 ed                	xor    %ebp,%ebp
    1176:	49 89 d1             	mov    %rdx,%r9
    1179:	5e                   	pop    %rsi
    117a:	48 89 e2             	mov    %rsp,%rdx
    117d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1181:	50                   	push   %rax
    1182:	54                   	push   %rsp
    1183:	4c 8d 05 46 02 00 00 	lea    0x246(%rip),%r8        # 13d0 <__libc_csu_fini>
    118a:	48 8d 0d cf 01 00 00 	lea    0x1cf(%rip),%rcx        # 1360 <__libc_csu_init>
    1191:	48 8d 3d 48 ff ff ff 	lea    -0xb8(%rip),%rdi        # 10e0 <main>
    1198:	ff 15 42 2e 00 00    	callq  *0x2e42(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    119e:	f4                   	hlt    
    119f:	90                   	nop

00000000000011a0 <deregister_tm_clones>:
    11a0:	48 8d 3d 69 2e 00 00 	lea    0x2e69(%rip),%rdi        # 4010 <__TMC_END__>
    11a7:	48 8d 05 62 2e 00 00 	lea    0x2e62(%rip),%rax        # 4010 <__TMC_END__>
    11ae:	48 39 f8             	cmp    %rdi,%rax
    11b1:	74 15                	je     11c8 <deregister_tm_clones+0x28>
    11b3:	48 8b 05 1e 2e 00 00 	mov    0x2e1e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    11ba:	48 85 c0             	test   %rax,%rax
    11bd:	74 09                	je     11c8 <deregister_tm_clones+0x28>
    11bf:	ff e0                	jmpq   *%rax
    11c1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    11c8:	c3                   	retq   
    11c9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011d0 <register_tm_clones>:
    11d0:	48 8d 3d 39 2e 00 00 	lea    0x2e39(%rip),%rdi        # 4010 <__TMC_END__>
    11d7:	48 8d 35 32 2e 00 00 	lea    0x2e32(%rip),%rsi        # 4010 <__TMC_END__>
    11de:	48 29 fe             	sub    %rdi,%rsi
    11e1:	48 89 f0             	mov    %rsi,%rax
    11e4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    11e8:	48 c1 f8 03          	sar    $0x3,%rax
    11ec:	48 01 c6             	add    %rax,%rsi
    11ef:	48 d1 fe             	sar    %rsi
    11f2:	74 14                	je     1208 <register_tm_clones+0x38>
    11f4:	48 8b 05 f5 2d 00 00 	mov    0x2df5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    11fb:	48 85 c0             	test   %rax,%rax
    11fe:	74 08                	je     1208 <register_tm_clones+0x38>
    1200:	ff e0                	jmpq   *%rax
    1202:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1208:	c3                   	retq   
    1209:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001210 <__do_global_dtors_aux>:
    1210:	f3 0f 1e fa          	endbr64 
    1214:	80 3d f5 2d 00 00 00 	cmpb   $0x0,0x2df5(%rip)        # 4010 <__TMC_END__>
    121b:	75 2b                	jne    1248 <__do_global_dtors_aux+0x38>
    121d:	55                   	push   %rbp
    121e:	48 83 3d d2 2d 00 00 	cmpq   $0x0,0x2dd2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1225:	00 
    1226:	48 89 e5             	mov    %rsp,%rbp
    1229:	74 0c                	je     1237 <__do_global_dtors_aux+0x27>
    122b:	48 8b 3d d6 2d 00 00 	mov    0x2dd6(%rip),%rdi        # 4008 <__dso_handle>
    1232:	e8 49 fe ff ff       	callq  1080 <__cxa_finalize@plt>
    1237:	e8 64 ff ff ff       	callq  11a0 <deregister_tm_clones>
    123c:	c6 05 cd 2d 00 00 01 	movb   $0x1,0x2dcd(%rip)        # 4010 <__TMC_END__>
    1243:	5d                   	pop    %rbp
    1244:	c3                   	retq   
    1245:	0f 1f 00             	nopl   (%rax)
    1248:	c3                   	retq   
    1249:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001250 <frame_dummy>:
    1250:	f3 0f 1e fa          	endbr64 
    1254:	e9 77 ff ff ff       	jmpq   11d0 <register_tm_clones>
    1259:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001260 <addpersons>:
    1260:	f3 0f 1e fa          	endbr64 
    1264:	41 55                	push   %r13
    1266:	48 63 c7             	movslq %edi,%rax
    1269:	41 54                	push   %r12
    126b:	48 8d 3c c5 00 00 00 	lea    0x0(,%rax,8),%rdi
    1272:	00 
    1273:	55                   	push   %rbp
    1274:	48 29 c7             	sub    %rax,%rdi
    1277:	48 89 c5             	mov    %rax,%rbp
    127a:	53                   	push   %rbx
    127b:	48 c1 e7 03          	shl    $0x3,%rdi
    127f:	48 83 ec 08          	sub    $0x8,%rsp
    1283:	e8 28 fe ff ff       	callq  10b0 <malloc@plt>
    1288:	49 89 c5             	mov    %rax,%r13
    128b:	85 ed                	test   %ebp,%ebp
    128d:	7e 79                	jle    1308 <addpersons+0xa8>
    128f:	48 89 c3             	mov    %rax,%rbx
    1292:	8d 45 ff             	lea    -0x1(%rbp),%eax
    1295:	48 8d 2d 6c 0d 00 00 	lea    0xd6c(%rip),%rbp        # 2008 <_IO_stdin_used+0x8>
    129c:	48 83 c0 01          	add    $0x1,%rax
    12a0:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
    12a7:	00 
    12a8:	48 29 c2             	sub    %rax,%rdx
    12ab:	4d 8d 64 d5 00       	lea    0x0(%r13,%rdx,8),%r12
    12b0:	48 89 ee             	mov    %rbp,%rsi
    12b3:	bf 01 00 00 00       	mov    $0x1,%edi
    12b8:	31 c0                	xor    %eax,%eax
    12ba:	e8 01 fe ff ff       	callq  10c0 <__printf_chk@plt>
    12bf:	48 89 de             	mov    %rbx,%rsi
    12c2:	48 8d 3d b0 0d 00 00 	lea    0xdb0(%rip),%rdi        # 2079 <_IO_stdin_used+0x79>
    12c9:	31 c0                	xor    %eax,%eax
    12cb:	e8 00 fe ff ff       	callq  10d0 <__isoc99_scanf@plt>
    12d0:	48 8d 35 59 0d 00 00 	lea    0xd59(%rip),%rsi        # 2030 <_IO_stdin_used+0x30>
    12d7:	bf 01 00 00 00       	mov    $0x1,%edi
    12dc:	31 c0                	xor    %eax,%eax
    12de:	e8 dd fd ff ff       	callq  10c0 <__printf_chk@plt>
    12e3:	48 8d 73 0c          	lea    0xc(%rbx),%rsi
    12e7:	48 8d 3d 8e 0d 00 00 	lea    0xd8e(%rip),%rdi        # 207c <_IO_stdin_used+0x7c>
    12ee:	31 c0                	xor    %eax,%eax
    12f0:	e8 db fd ff ff       	callq  10d0 <__isoc99_scanf@plt>
    12f5:	48 83 c3 38          	add    $0x38,%rbx
    12f9:	bf 0a 00 00 00       	mov    $0xa,%edi
    12fe:	e8 8d fd ff ff       	callq  1090 <putchar@plt>
    1303:	4c 39 e3             	cmp    %r12,%rbx
    1306:	75 a8                	jne    12b0 <addpersons+0x50>
    1308:	48 83 c4 08          	add    $0x8,%rsp
    130c:	4c 89 e8             	mov    %r13,%rax
    130f:	5b                   	pop    %rbx
    1310:	5d                   	pop    %rbp
    1311:	41 5c                	pop    %r12
    1313:	41 5d                	pop    %r13
    1315:	c3                   	retq   
    1316:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    131d:	00 00 00 

0000000000001320 <printperson>:
    1320:	f3 0f 1e fa          	endbr64 
    1324:	48 83 ec 08          	sub    $0x8,%rsp
    1328:	48 8d 35 29 0d 00 00 	lea    0xd29(%rip),%rsi        # 2058 <_IO_stdin_used+0x58>
    132f:	bf 01 00 00 00       	mov    $0x1,%edi
    1334:	31 c0                	xor    %eax,%eax
    1336:	8b 4c 24 1c          	mov    0x1c(%rsp),%ecx
    133a:	48 8d 54 24 10       	lea    0x10(%rsp),%rdx
    133f:	e8 7c fd ff ff       	callq  10c0 <__printf_chk@plt>
    1344:	bf 0a 00 00 00       	mov    $0xa,%edi
    1349:	e8 42 fd ff ff       	callq  1090 <putchar@plt>
    134e:	48 83 c4 08          	add    $0x8,%rsp
    1352:	c3                   	retq   
    1353:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    135a:	00 00 00 
    135d:	0f 1f 00             	nopl   (%rax)

0000000000001360 <__libc_csu_init>:
    1360:	f3 0f 1e fa          	endbr64 
    1364:	41 57                	push   %r15
    1366:	4c 8d 3d 2b 2a 00 00 	lea    0x2a2b(%rip),%r15        # 3d98 <__frame_dummy_init_array_entry>
    136d:	41 56                	push   %r14
    136f:	49 89 d6             	mov    %rdx,%r14
    1372:	41 55                	push   %r13
    1374:	49 89 f5             	mov    %rsi,%r13
    1377:	41 54                	push   %r12
    1379:	41 89 fc             	mov    %edi,%r12d
    137c:	55                   	push   %rbp
    137d:	48 8d 2d 1c 2a 00 00 	lea    0x2a1c(%rip),%rbp        # 3da0 <__do_global_dtors_aux_fini_array_entry>
    1384:	53                   	push   %rbx
    1385:	4c 29 fd             	sub    %r15,%rbp
    1388:	48 83 ec 08          	sub    $0x8,%rsp
    138c:	e8 6f fc ff ff       	callq  1000 <_init>
    1391:	48 c1 fd 03          	sar    $0x3,%rbp
    1395:	74 1f                	je     13b6 <__libc_csu_init+0x56>
    1397:	31 db                	xor    %ebx,%ebx
    1399:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    13a0:	4c 89 f2             	mov    %r14,%rdx
    13a3:	4c 89 ee             	mov    %r13,%rsi
    13a6:	44 89 e7             	mov    %r12d,%edi
    13a9:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    13ad:	48 83 c3 01          	add    $0x1,%rbx
    13b1:	48 39 dd             	cmp    %rbx,%rbp
    13b4:	75 ea                	jne    13a0 <__libc_csu_init+0x40>
    13b6:	48 83 c4 08          	add    $0x8,%rsp
    13ba:	5b                   	pop    %rbx
    13bb:	5d                   	pop    %rbp
    13bc:	41 5c                	pop    %r12
    13be:	41 5d                	pop    %r13
    13c0:	41 5e                	pop    %r14
    13c2:	41 5f                	pop    %r15
    13c4:	c3                   	retq   
    13c5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    13cc:	00 00 00 00 

00000000000013d0 <__libc_csu_fini>:
    13d0:	f3 0f 1e fa          	endbr64 
    13d4:	c3                   	retq   

Disassembly of section .fini:

00000000000013d8 <_fini>:
    13d8:	f3 0f 1e fa          	endbr64 
    13dc:	48 83 ec 08          	sub    $0x8,%rsp
    13e0:	48 83 c4 08          	add    $0x8,%rsp
    13e4:	c3                   	retq   
