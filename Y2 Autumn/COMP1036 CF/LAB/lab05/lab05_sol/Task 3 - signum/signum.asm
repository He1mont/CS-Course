// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/signum.asm

//Implement signum.asm to achieve the following function.
// Computes:
// if RAM[0]>0
// RAM[1]=1
// else
// RAM[1]=0
// Usage: put a value in RAM[0],
// run and inspect RAM[1].

// Put your code here.
@0
D=M // D = RAM[0]
@8
D;JGT // If R0>0 goto 8
@R1
M=0 // RAM[1]=0
@10
0;JMP // goto end
@1
M=1 // RAM[1]=1
@10 // end
0;JMP



