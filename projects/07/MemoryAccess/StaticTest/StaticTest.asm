// sym1 : push
// push constant 111
// Symbol1 present at line : 7
@111
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : push
// push constant 333
// Symbol1 present at line : 8
@333
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : push
// push constant 888
// Symbol1 present at line : 9
@888
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop static 8
// Symbol1 present at line : 10
@StaticTest_8
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1
// sym1 : pop
// pop static 3
// Symbol1 present at line : 11
@StaticTest_3
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1
// sym1 : pop
// pop static 1
// Symbol1 present at line : 12
@StaticTest_1
D=A
@R13
M=D
@SP
A=M-1
D=M
@R13
A=M
M=D
@SP
M=M-1
// sym1 : push
// push static 3
// Symbol1 present at line : 13
@StaticTest_3
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : push
// push static 1
// Symbol1 present at line : 14
@StaticTest_1
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : sub
// sub
// Symbol1 present at line : 15
@SP
AM=M-1
D=M
A=A-1
M=M-D
// sym1 : push
// push static 8
// Symbol1 present at line : 16
@StaticTest_8
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : add
// add
// Symbol1 present at line : 17
@SP
AM=M-1
D=M
A=A-1
M=M+D
(ENDD)
@ENDD
0;JMP
