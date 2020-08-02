// sym1 : function
// function Sys.init 0
// Symbol1 present at line : 11
@256
D=A
@SP
M=D
@LCL
M=D
@ARG
M=D
@CLabel_0
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@SP
D=M
@0
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Sys.init
0;JMP
(CLabel_0)
// sym1 : push
// push constant 4
// Symbol1 present at line : 12
@4
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : call
// call Main.fibonacci 1   // computes the 4'th fibonacci element
// Symbol1 present at line : 13
@CLabelSys_0
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@SP
D=M
@1
D=D-A
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Main.fibonacci
0;JMP
(CLabelSys_0)
// sym1 : label
// label WHILE
// Symbol1 present at line : 14
(WHILE)
// sym1 : goto
// goto WHILE              // loops infinitely
// Symbol1 present at line : 15
@WHILE
0;JMP
(ENDD)
@ENDD
0;JMP
