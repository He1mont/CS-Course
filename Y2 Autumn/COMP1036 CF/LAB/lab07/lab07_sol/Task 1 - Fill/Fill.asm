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

// run an infinite loop to listen to the keyboard
(LOOP)
	// this code write the whole screen to black or white
	// the whole screen contains 8192 16-bit memory, e.g. end at KBD.
	// initialize i = 0; n = 8192
	@SCREEN
	D = A
	@i
	M = D // i = SCREEN

(LOOPSCREEN)
	// check keyboard
	@KBD
	D = M //get keyboard input

	// if KBD == 0 clear screen
	@b_or_w
	M = 0 // b_or_w = 0, set pixel to white

	@DRAWSCREEN
	D;JEQ

	// if KBD != 0, black the screen
	@b_or_w
	M = -1 // b_or_w = -1, set pixel to black.

(DRAWSCREEN)
	// if i == KBD, goto LOOP
	@i
	D = M
	@KBD
	D = D - A
	@LOOP
	D;JEQ

	//else 
	@b_or_w
	D = M
	@i
	A = M
	M = D

	// i++
	@i
	M = M + 1 // i++

	@LOOPSCREEN
	0;JMP // goto LOOPSCREEN

	@LOOP
	0;JMP // an infinite loop.

(END)
	@END
	0;JMP //end