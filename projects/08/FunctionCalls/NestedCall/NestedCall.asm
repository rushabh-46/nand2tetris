// sym1 : function
// function Sys.init 0
// Symbol1 present at line : 8
(Sys.init)
@0
D=A
(LOOPSys_0)
@FLabelSys_0
D;JEQ
@SP
A=M
M=0
@SP
M=M+1
D=D-1
@LOOPSys_0
0;JMP
(FLabelSys_0)
// sym1 : push
// push constant 4000	// test THIS and THAT context save
// Symbol1 present at line : 9
@4000	//
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop pointer 0
// Symbol1 present at line : 10
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
// push constant 5000
// Symbol1 present at line : 11
@5000
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop pointer 1
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
// sym1 : call
// call Sys.main 0
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
@Sys.main
0;JMP
(CLabelSys_0)
// sym1 : pop
// pop temp 1
// Symbol1 present at line : 14
@5
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
// sym1 : label
// label LOOP
// Symbol1 present at line : 15
(LOOP)
// sym1 : goto
// goto LOOP
// Symbol1 present at line : 16
@LOOP
0;JMP
// sym1 : function
// function Sys.main 5
// Symbol1 present at line : 26
(Sys.main)
@5
D=A
(LOOPSys_1)
@FLabelSys_1
D;JEQ
@SP
A=M
M=0
@SP
M=M+1
D=D-1
@LOOPSys_1
0;JMP
(FLabelSys_1)
// sym1 : push
// push constant 4001
// Symbol1 present at line : 27
@4001
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop pointer 0
// Symbol1 present at line : 28
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
// push constant 5001
// Symbol1 present at line : 29
@5001
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop pointer 1
// Symbol1 present at line : 30
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
// push constant 200
// Symbol1 present at line : 31
@200
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop local 1
// Symbol1 present at line : 32
@LCL
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
// push constant 40
// Symbol1 present at line : 33
@40
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop local 2
// Symbol1 present at line : 34
@LCL
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
// push constant 6
// Symbol1 present at line : 35
@6
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop local 3
// Symbol1 present at line : 36
@LCL
D=M
@3
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
// push constant 123
// Symbol1 present at line : 37
@123
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : call
// call Sys.add12 1
// Symbol1 present at line : 38
@CLabelSys_1
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
@Sys.add12
0;JMP
(CLabelSys_1)
// sym1 : pop
// pop temp 0
// Symbol1 present at line : 39
@5
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
// push local 0
// Symbol1 present at line : 40
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
// Symbol1 present at line : 41
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
// sym1 : push
// push local 2
// Symbol1 present at line : 42
@LCL
D=M
@2
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : push
// push local 3
// Symbol1 present at line : 43
@LCL
D=M
@3
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : push
// push local 4
// Symbol1 present at line : 44
@LCL
D=M
@4
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
// sym1 : add
// add
// Symbol1 present at line : 45
@SP
AM=M-1
D=M
A=A-1
M=M+D
// sym1 : add
// add
// Symbol1 present at line : 46
@SP
AM=M-1
D=M
A=A-1
M=M+D
// sym1 : add
// add
// Symbol1 present at line : 47
@SP
AM=M-1
D=M
A=A-1
M=M+D
// sym1 : add
// add
// Symbol1 present at line : 48
@SP
AM=M-1
D=M
A=A-1
M=M+D
// sym1 : return
// return
// Symbol1 present at line : 49
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
// sym1 : function
// function Sys.add12 0
// Symbol1 present at line : 55
(Sys.add12)
@0
D=A
(LOOPSys_2)
@FLabelSys_2
D;JEQ
@SP
A=M
M=0
@SP
M=M+1
D=D-1
@LOOPSys_2
0;JMP
(FLabelSys_2)
// sym1 : push
// push constant 4002
// Symbol1 present at line : 56
@4002
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop pointer 0
// Symbol1 present at line : 57
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
// push constant 5002
// Symbol1 present at line : 58
@5002
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : pop
// pop pointer 1
// Symbol1 present at line : 59
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
// Symbol1 present at line : 60
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
// push constant 12
// Symbol1 present at line : 61
@12
D=A
@SP
A=M
M=D
@SP
M=M+1
// sym1 : add
// add
// Symbol1 present at line : 62
@SP
AM=M-1
D=M
A=A-1
M=M+D
// sym1 : return
// return
// Symbol1 present at line : 63
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
