// Generate fibonacci series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
// Input a number in RAM[0], the function returns the next number in the Fibonacci series in RAM[1].

// Put your code here.
   // initialization
   @PreNum   
   M=0
   @CurNum
   M=1

   // main loop to calculate fibonacci seris
(LOOP)

   // check loop condition
   @CurNum
   D=M
   @R0
   D=D-M
   @STOP    
   D;JGT

   // NexNum = CurNum + PreNum
   @PreNum
   D=M
   @CurNum
   D=D+M
   @NexNum
   M=D
   
   // PreNum = CurNum
   @CurNum
   D=M
   @PreNum
   M=D
   
   // CurNum = NexNum
   @NexNum
   D=M
   @CurNum
   M=D
   @LOOP
   0;JMP

(STOP)
   // R1 = NexNum
   @NexNum
   D=M
   @R1
   M=D

   // program end 
(END)
   @END 
   0;JMP   



