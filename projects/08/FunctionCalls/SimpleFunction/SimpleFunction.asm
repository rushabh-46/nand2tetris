// sym1 : function
// function SimpleFunction.test 2
// Symbol1 present at line : 7
(SimpleFunction.test)
@2
D=A
(LOOPSimpleFunction_0)
@FLabelSimpleFunction_0
D;JEQ
@SP
A=M
M=0
@SP
M=M+1
D=D-1
@LOOPSimpleFunction_0
0;JMP
(FLabelSimpleFunction_0)
// sym1 : push
// push local 0
// Symbol1 present at line : 8
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
// push local 1
// Symbol1 present at line : 9
@LCL
D=M
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
// Symbol1 present at line : 10
@SP
AM=M-1
D=M
A=A-1
M=M+D
// sym1 : not
// not
// Symbol1 present at line : 11
@SP
A=M-1
M=!M
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
// sym1 : add
// add
// Symbol1 present at line : 13
@SP
AM=M-1
D=M
A=A-1
M=M+D
// sym1 : push
// push argument 1
// Symbol1 present at line : 14
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
// Symbol1 present at line : 15
@SP
AM=M-1
D=M
A=A-1
M=M-D
// sym1 : return
// return
// Symbol1 present at line : 16
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
