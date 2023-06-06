    .data
prompt1: .asciiz "Please type a string no more than 99 chars: "
prompt2: .asciiz "The reverse string is: "
buffer:  .space 100     # space to store the string, 1 extra byte to store null

    .text
    .globl main

main:
    # print prompt1
    la $a0, prompt1
    li $v0, 4
    syscall

    # input string
    la $a0, buffer      # set arguments
    li $a1, 100
    li $v0, 8
    syscall

    # print prompt2
    la $a0, prompt2
    li $v0, 4
    syscall

    # store the address of string into $s0
    # which means $s0 is a poingter pointing to the string
    la $s0, buffer

    # python pseudo code
    # i = 0
    # while str[i] != 0{
    #     i++;
    # }
    # i--;

    # find the last character of the string
loop:
    lb $t0, 0($s0)      # use $t0 to obtain each character of the string
    addi $s0, $s0, 1
    bne $t0, $0, loop
    addi $s0, $s0, -1   # let $t0 be the last character of the string

    la $s1, buffer
    addi $s1, $s1, -1

loop2:
    addi $s0, $s0, -1
    lb $a0, 0($s0)
    beq $s0, $s1, exit  # s0 and s1 are both pointers storing addresses
    li $v0, 11
    syscall
    j loop2

exit:
    li $v0, 10
    syscall


