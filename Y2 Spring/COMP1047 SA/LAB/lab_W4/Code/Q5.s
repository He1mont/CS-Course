    .data

array:
    .word 32729

    .text
    .globl main

main:
    # $t0 = x
    li $v0, 5
    syscall
    move $t0, $v0

    # $t1 = y
    li $v0, 5
    syscall
    sll $t1, $v0, 1

    # $t3 = 32769
    la $t2, array
    lw $t3, 0($t2)

    # addition
    add $t4, $t0, $t1       # t4 = t0 + t1
    add $t5, $t3, $t4       # t5 = t3 + t4

    # print
    move $a0, $t5
    li $v0, 1
    syscall

exit:
    li $v0, 10
    syscall