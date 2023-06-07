//Translate the following VM code to Hack Assembly
// push local 0
// push local 1
// add
// pop local 2

// Hack Assembly code:

// addr = LCL
@LCL
D=M
@addr
M=D
// *SP = *addr
@addr
A=M
D=M
@SP
A=M
M=D
// SP++
@SP
M=M+1

// addr = LCL + 1
@1
D=A
@LCL
D=D+M
@addr
M=D
// *SP = *addr
@addr
A=M
D=M
@SP
A=M
M=D
// SP++
@SP
M=M+1

// SP--
@SP
M=M-1
// D = *SP
@SP
A=M
D=M
// SP--
@SP
M=M-1
// *SP = *SP + D
@SP
A=M
M=D+M
// SP++
@SP
M=M+1

// addr = LCL + 2
@2
D=A
@LCL
D=D+M
@addr
M=D
// SP--
@SP
M=M-1
// *addr = *SP
@SP
A=M
D=M
@addr
A=M
M=D