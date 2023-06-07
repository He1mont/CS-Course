// Computes RAM[2] = max(RAM[0],RAM[1])

   @R0
   D=M           // D = RAM[0]
   @R1
   D=D-M         // D = RAM[0] - RAM[1]
   @OUTPUT_RAM0
   D;JGT         // if D>0 goto output RAM[0]

   // Output RAM[1]
   @R1
   D=M              
   @R2
   M=D           // RAM[2] = RAM[1]
   @END
   0;JMP

(OUTPUT_RAM0)
   @R0
   D=M
   @R2
   M=D           // RAM[2] = RAM[0]   

(END)
   @END
   0;JMP