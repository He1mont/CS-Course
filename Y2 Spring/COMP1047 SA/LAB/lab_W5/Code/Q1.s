    .data

input: .asciiz "Please input a number: "
printodd: .asciiz "It is odd!" 
printeven: .asciiz "It is even!" 

    .text
    .globl main

main:
    # print "Please input a number: "
    la $a0, input
    li $v0, 4
    syscall

    # read input
    li $v0 5
    syscall
    move $t0, $v0

    andi $t1, $t0, 1
    beq $t1, $0, even
    bne $t1, $0, odd

even:
    la $a0, printeven
    li $v0, 4
    syscall
    j exit

odd:
    la $a0, printodd
    li $v0, 4
    syscall
    j exit

exit:
    li $v0, 10
    syscall