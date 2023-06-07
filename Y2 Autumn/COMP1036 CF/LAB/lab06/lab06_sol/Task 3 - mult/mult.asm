// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

	// I'm going to implement multiplication as adding R0
	// to itself R1 times.

	// @times will be counting down from R1; when it
	// reaches 0, we jump to the end
	@R1
	D=M //copy R1 into D
	@times
	M=D // and now M[times] = R1

	// @sum will be the cumulative sum of the R0's; at end
	// of program, it's copied into R2 -> may as well always
	// live in R2
	@R2
	M=0 //initialize sum to 0

(LOOP)
	// within the loop, if times = 0, need to break out
	@times
	D=M //d = times
	@END
	D; JEQ // if times = 0, break 

	// if we're still looping, need to decrement times
	// and increment sum
	@R1
	D=D-A //d = times - 1
	@times
	M=D // and now, times = times-1

	@R2
	D=M
	@R0
	D=D+M // d = R0 + SUM
	@R2
	M=D //and, now sum = sum+R0

	@LOOP
	0;JMP

(END)  // and, the infinite loop that ends a hack program
       @END
       0; JMP