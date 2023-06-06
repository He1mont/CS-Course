    .data 0x10010010
msg: 
    .asciiz "Hello World!\n"
    .text
    .globl main

main:
    la $a0, msg     # load label msg
    li $v0, 4       # load immediate
    syscall         # print it
    li $v0, 10
    syscall         # exit