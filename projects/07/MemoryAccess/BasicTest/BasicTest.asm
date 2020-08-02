// sym1 : 
// 
// sym1 : 
// 
// sym1 : 
// 
// sym1 : 
// 
// sym1 : 
// 
// sym1 : 
// 
// sym1 : push
// push constant 10
// Symbol1 present at line : 6
@10
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop local 0
// Symbol1 present at line : 7
@LCL
D=M
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
// push constant 21
// Symbol1 present at line : 8
@21
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : push
// push constant 22
// Symbol1 present at line : 9
@22
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop argument 2
// Symbol1 present at line : 10
@ARG
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
// sym1 : pop
// pop argument 1
// Symbol1 present at line : 11
@ARG
D=M
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
// push constant 36
// Symbol1 present at line : 12
@36
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop this 6
// Symbol1 present at line : 13
@THIS
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
// push constant 42
// Symbol1 present at line : 14
@42
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : push
// push constant 45
// Symbol1 present at line : 15
@45
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop that 5
// Symbol1 present at line : 16
@THAT
D=M
@5
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
// sym1 : pop
// pop that 2
// Symbol1 present at line : 17
@THAT
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
// push constant 510
// Symbol1 present at line : 18
@510
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop temp 6
// Symbol1 present at line : 19
@5
D=A
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
// push local 0
// Symbol1 present at line : 20
@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : push
// push that 5
// Symbol1 present at line : 21
@THAT
D=M
@5
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
// sym1 : push
// push argument 1
// Symbol1 present at line : 23
@ARG
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : sub
// sub
// Symbol1 present at line : 24
@SP
AM=M-1
D=M
A=A-1
M=M-D
// sym1 : push
// push this 6
// Symbol1 present at line : 25
@THIS
D=M
@6
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : push
// push this 6
// Symbol1 present at line : 26
@THIS
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
// Symbol1 present at line : 27
@SP
AM=M-1
D=M
A=A-1
M=M+D
// sym1 : sub
// sub
// Symbol1 present at line : 28
@SP
AM=M-1
D=M
A=A-1
M=M-D
// sym1 : push
// push temp 6
// Symbol1 present at line : 29
@5
D=A
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
// Symbol1 present at line : 30
@SP
AM=M-1
D=M
A=A-1
M=M+D
(ENDD)
@ENDD
0;JMP
