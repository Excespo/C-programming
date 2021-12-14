
lab5O0.o:     file format elf64-x86-64


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
    1020:	ff 35 82 2f 00 00    	pushq  0x2f82(%rip)        # 3fa8 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 83 2f 00 00 	bnd jmpq *0x2f83(%rip)        # 3fb0 <_GLOBAL_OFFSET_TABLE_+0x10>
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

Disassembly of section .plt.got:

0000000000001070 <__cxa_finalize@plt>:
    1070:	f3 0f 1e fa          	endbr64 
    1074:	f2 ff 25 7d 2f 00 00 	bnd jmpq *0x2f7d(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001080 <putchar@plt>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	f2 ff 25 2d 2f 00 00 	bnd jmpq *0x2f2d(%rip)        # 3fb8 <putchar@GLIBC_2.2.5>
    108b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001090 <printf@plt>:
    1090:	f3 0f 1e fa          	endbr64 
    1094:	f2 ff 25 25 2f 00 00 	bnd jmpq *0x2f25(%rip)        # 3fc0 <printf@GLIBC_2.2.5>
    109b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010a0 <malloc@plt>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	f2 ff 25 1d 2f 00 00 	bnd jmpq *0x2f1d(%rip)        # 3fc8 <malloc@GLIBC_2.2.5>
    10ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010b0 <__isoc99_scanf@plt>:
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	f2 ff 25 15 2f 00 00 	bnd jmpq *0x2f15(%rip)        # 3fd0 <__isoc99_scanf@GLIBC_2.7>
    10bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000010c0 <_start>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	31 ed                	xor    %ebp,%ebp
    10c6:	49 89 d1             	mov    %rdx,%r9
    10c9:	5e                   	pop    %rsi
    10ca:	48 89 e2             	mov    %rsp,%rdx
    10cd:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10d1:	50                   	push   %rax
    10d2:	54                   	push   %rsp
    10d3:	4c 8d 05 c6 02 00 00 	lea    0x2c6(%rip),%r8        # 13a0 <__libc_csu_fini>
    10da:	48 8d 0d 4f 02 00 00 	lea    0x24f(%rip),%rcx        # 1330 <__libc_csu_init>
    10e1:	48 8d 3d db 01 00 00 	lea    0x1db(%rip),%rdi        # 12c3 <main>
    10e8:	ff 15 f2 2e 00 00    	callq  *0x2ef2(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    10ee:	f4                   	hlt    
    10ef:	90                   	nop

00000000000010f0 <deregister_tm_clones>:
    10f0:	48 8d 3d 19 2f 00 00 	lea    0x2f19(%rip),%rdi        # 4010 <__TMC_END__>
    10f7:	48 8d 05 12 2f 00 00 	lea    0x2f12(%rip),%rax        # 4010 <__TMC_END__>
    10fe:	48 39 f8             	cmp    %rdi,%rax
    1101:	74 15                	je     1118 <deregister_tm_clones+0x28>
    1103:	48 8b 05 ce 2e 00 00 	mov    0x2ece(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    110a:	48 85 c0             	test   %rax,%rax
    110d:	74 09                	je     1118 <deregister_tm_clones+0x28>
    110f:	ff e0                	jmpq   *%rax
    1111:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1118:	c3                   	retq   
    1119:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001120 <register_tm_clones>:
    1120:	48 8d 3d e9 2e 00 00 	lea    0x2ee9(%rip),%rdi        # 4010 <__TMC_END__>
    1127:	48 8d 35 e2 2e 00 00 	lea    0x2ee2(%rip),%rsi        # 4010 <__TMC_END__>
    112e:	48 29 fe             	sub    %rdi,%rsi
    1131:	48 89 f0             	mov    %rsi,%rax
    1134:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1138:	48 c1 f8 03          	sar    $0x3,%rax
    113c:	48 01 c6             	add    %rax,%rsi
    113f:	48 d1 fe             	sar    %rsi
    1142:	74 14                	je     1158 <register_tm_clones+0x38>
    1144:	48 8b 05 a5 2e 00 00 	mov    0x2ea5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    114b:	48 85 c0             	test   %rax,%rax
    114e:	74 08                	je     1158 <register_tm_clones+0x38>
    1150:	ff e0                	jmpq   *%rax
    1152:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1158:	c3                   	retq   
    1159:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001160 <__do_global_dtors_aux>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	80 3d a5 2e 00 00 00 	cmpb   $0x0,0x2ea5(%rip)        # 4010 <__TMC_END__>
    116b:	75 2b                	jne    1198 <__do_global_dtors_aux+0x38>
    116d:	55                   	push   %rbp
    116e:	48 83 3d 82 2e 00 00 	cmpq   $0x0,0x2e82(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1175:	00 
    1176:	48 89 e5             	mov    %rsp,%rbp
    1179:	74 0c                	je     1187 <__do_global_dtors_aux+0x27>
    117b:	48 8b 3d 86 2e 00 00 	mov    0x2e86(%rip),%rdi        # 4008 <__dso_handle>
    1182:	e8 e9 fe ff ff       	callq  1070 <__cxa_finalize@plt>
    1187:	e8 64 ff ff ff       	callq  10f0 <deregister_tm_clones>
    118c:	c6 05 7d 2e 00 00 01 	movb   $0x1,0x2e7d(%rip)        # 4010 <__TMC_END__>
    1193:	5d                   	pop    %rbp
    1194:	c3                   	retq   
    1195:	0f 1f 00             	nopl   (%rax)
    1198:	c3                   	retq   
    1199:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011a0 <frame_dummy>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	e9 77 ff ff ff       	jmpq   1120 <register_tm_clones>

00000000000011a9 <addpersons>:
    11a9:	f3 0f 1e fa          	endbr64 
    11ad:	55                   	push   %rbp
    11ae:	48 89 e5             	mov    %rsp,%rbp
    11b1:	48 83 ec 20          	sub    $0x20,%rsp
    11b5:	89 7d ec             	mov    %edi,-0x14(%rbp)
    11b8:	8b 45 ec             	mov    -0x14(%rbp),%eax
    11bb:	48 63 d0             	movslq %eax,%rdx
    11be:	48 89 d0             	mov    %rdx,%rax
    11c1:	48 c1 e0 02          	shl    $0x2,%rax
    11c5:	48 01 d0             	add    %rdx,%rax
    11c8:	48 c1 e0 02          	shl    $0x2,%rax
    11cc:	48 89 c7             	mov    %rax,%rdi
    11cf:	e8 cc fe ff ff       	callq  10a0 <malloc@plt>
    11d4:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    11d8:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%rbp)
    11df:	e9 9e 00 00 00       	jmpq   1282 <addpersons+0xd9>
    11e4:	48 8d 3d 1d 0e 00 00 	lea    0xe1d(%rip),%rdi        # 2008 <_IO_stdin_used+0x8>
    11eb:	b8 00 00 00 00       	mov    $0x0,%eax
    11f0:	e8 9b fe ff ff       	callq  1090 <printf@plt>
    11f5:	8b 45 f0             	mov    -0x10(%rbp),%eax
    11f8:	48 63 d0             	movslq %eax,%rdx
    11fb:	48 89 d0             	mov    %rdx,%rax
    11fe:	48 c1 e0 02          	shl    $0x2,%rax
    1202:	48 01 d0             	add    %rdx,%rax
    1205:	48 c1 e0 02          	shl    $0x2,%rax
    1209:	48 89 c2             	mov    %rax,%rdx
    120c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1210:	48 01 d0             	add    %rdx,%rax
    1213:	48 89 c6             	mov    %rax,%rsi
    1216:	48 8d 3d 0d 0e 00 00 	lea    0xe0d(%rip),%rdi        # 202a <_IO_stdin_used+0x2a>
    121d:	b8 00 00 00 00       	mov    $0x0,%eax
    1222:	e8 89 fe ff ff       	callq  10b0 <__isoc99_scanf@plt>
    1227:	89 45 f4             	mov    %eax,-0xc(%rbp)
    122a:	48 8d 3d ff 0d 00 00 	lea    0xdff(%rip),%rdi        # 2030 <_IO_stdin_used+0x30>
    1231:	b8 00 00 00 00       	mov    $0x0,%eax
    1236:	e8 55 fe ff ff       	callq  1090 <printf@plt>
    123b:	8b 45 f0             	mov    -0x10(%rbp),%eax
    123e:	48 63 d0             	movslq %eax,%rdx
    1241:	48 89 d0             	mov    %rdx,%rax
    1244:	48 c1 e0 02          	shl    $0x2,%rax
    1248:	48 01 d0             	add    %rdx,%rax
    124b:	48 c1 e0 02          	shl    $0x2,%rax
    124f:	48 89 c2             	mov    %rax,%rdx
    1252:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1256:	48 01 d0             	add    %rdx,%rax
    1259:	48 83 c0 0c          	add    $0xc,%rax
    125d:	48 89 c6             	mov    %rax,%rsi
    1260:	48 8d 3d ea 0d 00 00 	lea    0xdea(%rip),%rdi        # 2051 <_IO_stdin_used+0x51>
    1267:	b8 00 00 00 00       	mov    $0x0,%eax
    126c:	e8 3f fe ff ff       	callq  10b0 <__isoc99_scanf@plt>
    1271:	89 45 f4             	mov    %eax,-0xc(%rbp)
    1274:	bf 0a 00 00 00       	mov    $0xa,%edi
    1279:	e8 02 fe ff ff       	callq  1080 <putchar@plt>
    127e:	83 45 f0 01          	addl   $0x1,-0x10(%rbp)
    1282:	8b 45 f0             	mov    -0x10(%rbp),%eax
    1285:	3b 45 ec             	cmp    -0x14(%rbp),%eax
    1288:	0f 8c 56 ff ff ff    	jl     11e4 <addpersons+0x3b>
    128e:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1292:	c9                   	leaveq 
    1293:	c3                   	retq   

0000000000001294 <printperson>:
    1294:	f3 0f 1e fa          	endbr64 
    1298:	55                   	push   %rbp
    1299:	48 89 e5             	mov    %rsp,%rbp
    129c:	8b 45 1c             	mov    0x1c(%rbp),%eax
    129f:	89 c2                	mov    %eax,%edx
    12a1:	48 8d 75 10          	lea    0x10(%rbp),%rsi
    12a5:	48 8d 3d ac 0d 00 00 	lea    0xdac(%rip),%rdi        # 2058 <_IO_stdin_used+0x58>
    12ac:	b8 00 00 00 00       	mov    $0x0,%eax
    12b1:	e8 da fd ff ff       	callq  1090 <printf@plt>
    12b6:	bf 0a 00 00 00       	mov    $0xa,%edi
    12bb:	e8 c0 fd ff ff       	callq  1080 <putchar@plt>
    12c0:	90                   	nop
    12c1:	5d                   	pop    %rbp
    12c2:	c3                   	retq   

00000000000012c3 <main>:
    12c3:	f3 0f 1e fa          	endbr64 
    12c7:	55                   	push   %rbp
    12c8:	48 89 e5             	mov    %rsp,%rbp
    12cb:	48 83 ec 10          	sub    $0x10,%rsp
    12cf:	be 14 00 00 00       	mov    $0x14,%esi
    12d4:	48 8d 3d 9e 0d 00 00 	lea    0xd9e(%rip),%rdi        # 2079 <_IO_stdin_used+0x79>
    12db:	b8 00 00 00 00       	mov    $0x0,%eax
    12e0:	e8 ab fd ff ff       	callq  1090 <printf@plt>
    12e5:	bf 01 00 00 00       	mov    $0x1,%edi
    12ea:	e8 ba fe ff ff       	callq  11a9 <addpersons>
    12ef:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    12f3:	48 83 ec 08          	sub    $0x8,%rsp
    12f7:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
    12fb:	48 83 ec 18          	sub    $0x18,%rsp
    12ff:	48 89 e6             	mov    %rsp,%rsi
    1302:	48 8b 01             	mov    (%rcx),%rax
    1305:	48 8b 51 08          	mov    0x8(%rcx),%rdx
    1309:	48 89 06             	mov    %rax,(%rsi)
    130c:	48 89 56 08          	mov    %rdx,0x8(%rsi)
    1310:	8b 41 10             	mov    0x10(%rcx),%eax
    1313:	89 46 10             	mov    %eax,0x10(%rsi)
    1316:	e8 79 ff ff ff       	callq  1294 <printperson>
    131b:	48 83 c4 20          	add    $0x20,%rsp
    131f:	b8 00 00 00 00       	mov    $0x0,%eax
    1324:	c9                   	leaveq 
    1325:	c3                   	retq   
    1326:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    132d:	00 00 00 

0000000000001330 <__libc_csu_init>:
    1330:	f3 0f 1e fa          	endbr64 
    1334:	41 57                	push   %r15
    1336:	4c 8d 3d 63 2a 00 00 	lea    0x2a63(%rip),%r15        # 3da0 <__frame_dummy_init_array_entry>
    133d:	41 56                	push   %r14
    133f:	49 89 d6             	mov    %rdx,%r14
    1342:	41 55                	push   %r13
    1344:	49 89 f5             	mov    %rsi,%r13
    1347:	41 54                	push   %r12
    1349:	41 89 fc             	mov    %edi,%r12d
    134c:	55                   	push   %rbp
    134d:	48 8d 2d 54 2a 00 00 	lea    0x2a54(%rip),%rbp        # 3da8 <__do_global_dtors_aux_fini_array_entry>
    1354:	53                   	push   %rbx
    1355:	4c 29 fd             	sub    %r15,%rbp
    1358:	48 83 ec 08          	sub    $0x8,%rsp
    135c:	e8 9f fc ff ff       	callq  1000 <_init>
    1361:	48 c1 fd 03          	sar    $0x3,%rbp
    1365:	74 1f                	je     1386 <__libc_csu_init+0x56>
    1367:	31 db                	xor    %ebx,%ebx
    1369:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1370:	4c 89 f2             	mov    %r14,%rdx
    1373:	4c 89 ee             	mov    %r13,%rsi
    1376:	44 89 e7             	mov    %r12d,%edi
    1379:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    137d:	48 83 c3 01          	add    $0x1,%rbx
    1381:	48 39 dd             	cmp    %rbx,%rbp
    1384:	75 ea                	jne    1370 <__libc_csu_init+0x40>
    1386:	48 83 c4 08          	add    $0x8,%rsp
    138a:	5b                   	pop    %rbx
    138b:	5d                   	pop    %rbp
    138c:	41 5c                	pop    %r12
    138e:	41 5d                	pop    %r13
    1390:	41 5e                	pop    %r14
    1392:	41 5f                	pop    %r15
    1394:	c3                   	retq   
    1395:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    139c:	00 00 00 00 

00000000000013a0 <__libc_csu_fini>:
    13a0:	f3 0f 1e fa          	endbr64 
    13a4:	c3                   	retq   

Disassembly of section .fini:

00000000000013a8 <_fini>:
    13a8:	f3 0f 1e fa          	endbr64 
    13ac:	48 83 ec 08          	sub    $0x8,%rsp
    13b0:	48 83 c4 08          	add    $0x8,%rsp
    13b4:	c3                   	retq   
