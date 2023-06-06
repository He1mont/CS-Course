    .data
prompt1: .asciiz "Please type a string no more than 99 chars: "
prompt2: .asciiz "The modified string is: "
buffer:  .space 100

    .text
    .globl main

main:
    # print prompt1
    la $a0, prompt1
    li $v0, 4
    syscall

    # input the string
    la $a0, buffer      # set arguments
    li $a1, 100
    li $v0, 8
    syscall

    # print prompt2
    la $a0, prompt2
    li $v0, 4
    syscall

    # obtain the third character of the string
    la $s0, buffer
    lb $t0, 2($s0)
    addi, $t0, $t0, -32
    sb $t0, 2($s0)

    # print the final string
    la $a0, buffer
    li $v0, 4
    syscall


exit:
    li $v0, 10
    syscall