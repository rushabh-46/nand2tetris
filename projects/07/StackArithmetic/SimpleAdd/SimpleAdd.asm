// sym1 : push
// push constant 7
// Symbol1 present at line : 7
@7
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : push
// push constant 8
// Symbol1 present at line : 8
@8
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : add
// add
// Symbol1 present at line : 9
@SP
AM=M-1
D=M
A=A-1
M=M+D
(ENDD)
@ENDD
0;JMP
