// Adapted from: http://msp430rf2500.blogspot.com/2017/03/nand2tetris-hack-assembly-language.html
// divide.asm
// Divides R0 by R1 and stores the dividend in R2 and remainder in R3
// (R0, R1, R2, R3 refer to RAM[0], RAM[1], RAM[2], and RAM[3] respectively.)

    @R2
    M = 0

    @R3
    M = 0

    @R0
    D = M

    @END
    D, JEQ

    @store
    M = D  // store to restore

(LOOP)
    @R1
    D = D - M
    @REMAINDER
    D, JLT
    
    @R2
    M = M + 1
    @EVENLY
    D, JEQ 
 
    @LOOP
    0, JMP
 
(REMAINDER)
    @R1
    D = D + M
    @R3
    M = D

(EVENLY)
    @store
    D = M
    @R0
    M = D
 
(END)
    @END
    0, JMP