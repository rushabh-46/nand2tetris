// sym1 : push
// push argument 1
// Symbol1 present at line : 11
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
// sym1 : pop
// pop pointer 1           // that = argument[1]
// Symbol1 present at line : 12
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
// push constant 0
// Symbol1 present at line : 14
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop that 0              // first element in the series = 0
// Symbol1 present at line : 15
@THAT
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
// push constant 1
// Symbol1 present at line : 16
@1
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop that 1              // second element in the series = 1
// Symbol1 present at line : 17
@THAT
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
// push argument 0
// Symbol1 present at line : 19
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
// Symbol1 present at line : 20
@2
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : sub
// sub
// Symbol1 present at line : 21
@SP
AM=M-1
D=M
A=A-1
M=M-D
// sym1 : pop
// pop argument 0          // num_of_elements -= 2 (first 2 elements are set)
// Symbol1 present at line : 22
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
// sym1 : label
// label MAIN_LOOP_START
// Symbol1 present at line : 24
(MAIN_LOOP_START)
// sym1 : push
// push argument 0
// Symbol1 present at line : 26
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
// if-goto COMPUTE_ELEMENT // if num_of_elements > 0, goto COMPUTE_ELEMENT
// Symbol1 present at line : 27
@SP
AM=M-1
D=M
@COMPUTE_ELEMENT
D;JNE
// sym1 : goto
// goto END_PROGRAM        // otherwise, goto END_PROGRAM
// Symbol1 present at line : 28
@END_PROGRAM
0;JMP
// sym1 : label
// label COMPUTE_ELEMENT
// Symbol1 present at line : 30
(COMPUTE_ELEMENT)
// sym1 : push
// push that 0
// Symbol1 present at line : 32
@THAT
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
// push that 1
// Symbol1 present at line : 33
@THAT
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
// Symbol1 present at line : 34
@SP
AM=M-1
D=M
A=A-1
M=M+D
// sym1 : pop
// pop that 2              // that[2] = that[0] + that[1]
// Symbol1 present at line : 35
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
// push pointer 1
// Symbol1 present at line : 37
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
// sym1 : push
// push constant 1
// Symbol1 present at line : 38
@1
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : add
// add
// Symbol1 present at line : 39
@SP
AM=M-1
D=M
A=A-1
M=M+D
// sym1 : pop
// pop pointer 1           // that += 1
// Symbol1 present at line : 40
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
// push argument 0
// Symbol1 present at line : 42
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
// Symbol1 present at line : 43
@1
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : sub
// sub
// Symbol1 present at line : 44
@SP
AM=M-1
D=M
A=A-1
M=M-D
// sym1 : pop
// pop argument 0          // num_of_elements--
// Symbol1 present at line : 45
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
// sym1 : goto
// goto MAIN_LOOP_START
// Symbol1 present at line : 47
@MAIN_LOOP_START
0;JMP
// sym1 : label
// label END_PROGRAM
// Symbol1 present at line : 49
(END_PROGRAM)
(ENDD)
@ENDD
0;JMP
