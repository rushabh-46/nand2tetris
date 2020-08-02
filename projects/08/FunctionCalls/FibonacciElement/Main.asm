// sym1 : function
// function Main.fibonacci 0
// Symbol1 present at line : 11
(Main.fibonacci)
@0
D=A
(LOOPMain_0)
@FLabelMain_0
D;JEQ
@SP
A=M
M=0
@SP
M=M+1
D=D-1
@LOOPMain_0
0;JMP
(FLabelMain_0)
// sym1 : push
// push argument 0
// Symbol1 present at line : 12
@ARG
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
// push constant 2
// Symbol1 present at line : 13
@2
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : lt
// lt                     // checks if n<2
// Symbol1 present at line : 14
@SP
A=M-1
D=M
A=A-1
D=M-D
@ALabel_0
D;JLT
D=0
@ALabel_1
0;JMP
(ALabel_0)
D=-1
(ALabel_1)
@SP
M=M-1
A=M
A=A-1
M=D
// sym1 : if-goto
// if-goto IF_TRUE
// Symbol1 present at line : 15
@SP
AM=M-1
D=M
@IF_TRUE
D;JNE
// sym1 : goto
// goto IF_FALSE
// Symbol1 present at line : 16
@IF_FALSE
0;JMP
// sym1 : label
// label IF_TRUE          // if n<2, return n
// Symbol1 present at line : 17
(IF_TRUE)
// sym1 : push
// push argument 0        
// Symbol1 present at line : 18
@ARG
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : return
// return
// Symbol1 present at line : 19
@LCL
D=M
@R13
M=D
@5
A=D-A
D=M
@R14
M=D
@SP
A=M-1
D=M
@ARG
A=M
M=D
@ARG
D=M+1
@SP
M=D
@R13
A=M-1
D=M
@THAT
M=D
@R13
D=M
@2
A=D-A
D=M
@THIS
M=D
@R13
D=M
@3
A=D-A
D=M
@ARG
M=D
@R13
D=M
@4
A=D-A
D=M
@LCL
M=D
@R14
A=M
0;JMP
// sym1 : label
// label IF_FALSE         // if n>=2, returns fib(n-2)+fib(n-1)
// Symbol1 present at line : 20
(IF_FALSE)
// sym1 : push
// push argument 0
// Symbol1 present at line : 21
@ARG
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
// push constant 2
// Symbol1 present at line : 22
@2
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : sub
// sub
// Symbol1 present at line : 23
@SP
AM=M-1
D=M
A=A-1
M=M-D
// sym1 : call
// call Main.fibonacci 1  // computes fib(n-2)
// Symbol1 present at line : 24
@CLabelMain_2
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
(CLabelMain_2)
// sym1 : push
// push argument 0
// Symbol1 present at line : 25
@ARG
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
// push constant 1
// Symbol1 present at line : 26
@1
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : sub
// sub
// Symbol1 present at line : 27
@SP
AM=M-1
D=M
A=A-1
M=M-D
// sym1 : call
// call Main.fibonacci 1  // computes fib(n-1)
// Symbol1 present at line : 28
@CLabelMain_3
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
(CLabelMain_3)
// sym1 : add
// add                    // returns fib(n-1) + fib(n-2)
// Symbol1 present at line : 29
@SP
AM=M-1
D=M
A=A-1
M=M+D
// sym1 : return
// return
// Symbol1 present at line : 30
@LCL
D=M
@R13
M=D
@5
A=D-A
D=M
@R14
M=D
@SP
A=M-1
D=M
@ARG
A=M
M=D
@ARG
D=M+1
@SP
M=D
@R13
A=M-1
D=M
@THAT
M=D
@R13
D=M
@2
A=D-A
D=M
@THIS
M=D
@R13
D=M
@3
A=D-A
D=M
@ARG
M=D
@R13
D=M
@4
A=D-A
D=M
@LCL
M=D
@R14
A=M
0;JMP
(ENDD)
@ENDD
0;JMP
