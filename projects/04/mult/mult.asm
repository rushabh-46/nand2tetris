// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

	@i
	M=0
	@sum
	M=0
	@2
	M=0
(LOOP)
	@i
	D=M
	
	@1
	D=D-M
	@END
	D;JGE
	
	@0
	D=M
	@sum
	M=D+M
	@i
	M=M+1
	@LOOP
	0;JMP
(END)
	@sum
	D=M
	@2
	M=D
(LOOP2)
	@LOOP2
	0;JMP