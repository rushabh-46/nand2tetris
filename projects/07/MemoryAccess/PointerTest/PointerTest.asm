// sym1 : push
// push constant 3030
// Symbol1 present at line : 8
@3030
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop pointer 0
// Symbol1 present at line : 9
@3
D=A
@0
D=D+A
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
// push constant 3040
// Symbol1 present at line : 10
@3040
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop pointer 1
// Symbol1 present at line : 11
@3
D=A
@1
D=D+A
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
// push constant 32
// Symbol1 present at line : 12
@32
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop this 2
// Symbol1 present at line : 13
@THIS
D=M
@2
D=D+A
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
// push constant 46
// Symbol1 present at line : 14
@46
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop that 6
// Symbol1 present at line : 15
@THAT
D=M
@6
D=D+A
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
// push pointer 0
// Symbol1 present at line : 16
@3
D=A
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : push
// push pointer 1
// Symbol1 present at line : 17
@3
D=A
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : add
// add
// Symbol1 present at line : 18
@SP
AM=M-1
D=M
A=A-1
M=M+D
// sym1 : push
// push this 2
// Symbol1 present at line : 19
@THIS
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : sub
// sub
// Symbol1 present at line : 20
@SP
AM=M-1
D=M
A=A-1
M=M-D
// sym1 : push
// push that 6
// Symbol1 present at line : 21
@THAT
D=M
@6
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : add
// add
// Symbol1 present at line : 22
@SP
AM=M-1
D=M
A=A-1
M=M+D
(ENDD)
@ENDD
0;JMP
