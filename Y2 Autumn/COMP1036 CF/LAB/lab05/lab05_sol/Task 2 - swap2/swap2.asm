// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/swap2.asm

// Set RAM[0] = 50, RAM[1] = 100, then swap the value of RAM[0] and RAM[1]. You may use RAM[16] as the temporary variable.

// Put your code here.
@50
D = A //D = 50
@0
M=D // RAM[0] = 50
@100
D = A //D = 100
@1
M=D // RAM[0] = 100
@0
D=M
@16
M=D //RAM[16]=RAM[0]
@1
D=M
@0
M=D //RAM[0]=RAM[1]
@16
D=M
@1
M=D //RAM[1]=RAM[16]
@20
0;JMP //end



