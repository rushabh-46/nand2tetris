// sym1 : push
// push constant 0    
// Symbol1 present at line : 9
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop local 0         // initializes sum = 0
// Symbol1 present at line : 10
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
// sym1 : label
// label LOOP_START
// Symbol1 present at line : 11
(LOOP_START)
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
// push local 0
// Symbol1 present at line : 13
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
// sym1 : add
// add
// Symbol1 present at line : 14
@SP
AM=M-1
D=M
A=A-1
M=M+D
// sym1 : pop
// pop local 0	        // sum = sum + counter
// Symbol1 present at line : 15
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
// push argument 0
// Symbol1 present at line : 16
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
// Symbol1 present at line : 17
@1
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : sub
// sub
// Symbol1 present at line : 18
@SP
AM=M-1
D=M
A=A-1
M=M-D
// sym1 : pop
// pop argument 0      // counter--
// Symbol1 present at line : 19
@ARG
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
// push argument 0
// Symbol1 present at line : 20
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
// sym1 : if-goto
// if-goto LOOP_START  // If counter > 0, goto LOOP_START
// Symbol1 present at line : 21
@SP
AM=M-1
D=M
@LOOP_START
D;JNE
// sym1 : push
// push local 0
// Symbol1 present at line : 22
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
(ENDD)
@ENDD
0;JMP
