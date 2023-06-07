// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/sgn.asm

// implement the following function
// sgn(x) = -1 if x<0
// sgn(x) = 0 if x=0
// sgn(x) = 1 if x>0
// You may assume that x is stored in RAM[0], and the returned value of function sgn(x) is stored in RAM[1].

// Put your code here.

     @R0
     D=M //D = RAM[0]

     @NEGATIVE
     D;JLT //x<0, jump to 8

     @ZERO
     D;JEQ //x==0, jump to 12

     @POSITIVE
     D;JGT //x>0, jump to 16

(NEGATIVE)	
     @1
     M=-1
     @END
     0;JMP //jump to end

(ZERO)
     @1
     M=0
     @END
     0;JMP //jump to end

(POSITIVE)
     @1
     M=1

(END)
     @18
     0;JMP //end
