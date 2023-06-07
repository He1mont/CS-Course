// Compute RAM[1] = 1+2+ ... +n
// Usage: put a number (n) in RAM[0]

   @R0
   D=M
   @n
   M=D   // n = R0

   @i   
   M=1   // i = 1
                                        
   @sum  
   M=0   // sum = 0

(LOOP)
   @i
   D=M // D = i
   @n
   D=D-M // D = i - n
   @STOP    
   D;JGT  // if i > n goto STOP

   @i
   D=M // D = i
   @sum
   M=D+M // sum = sum + i

   @i
   M=M+1  // i = i + 1

   @LOOP
   0;JMP // goto to LOOP

(STOP)
   @sum
   D=M // D = sum
   @R1
   M=D    // RAM[1] = sum

(END)
   @END 
   0;JMP // end 