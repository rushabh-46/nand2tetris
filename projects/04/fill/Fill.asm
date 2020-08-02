// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

	
(LOOP)
	@KBD
	D=M

	@Dark
	D;JNE
	@White
	0;JMP

(Dark)
	@R0
	M=-1
	@fill
	0;JMP

(White)
	@R0
	M=0
	@fill
	0;JMP

(fill)
	@8192
	D=A
	@R2
	M=D

	@R1
	M=0	

(again)
	@R1
	D=M
	@position
	M=D
	@SCREEN
	D=A
	@position
	M=M+D
	@R0
	D=M
	@position
        A=M
	M=D

 	@R1
 	D=M+1
	@R1
	M=D
	@R2
	D=M-1
	M=D
	@again
	D;JGT

	@LOOP
	0;JMP
	









