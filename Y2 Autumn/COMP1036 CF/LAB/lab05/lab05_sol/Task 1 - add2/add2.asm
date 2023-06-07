// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/add2.asm

// Add R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.
@0
D=M // D = RAM[0]

@1
D=D+M // D = D + RAM[1]

@2
M=D // RAM[2] = D

@6
0;JMP //end



