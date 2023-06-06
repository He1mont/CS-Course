    .data
printg: .asciiz "Please input the value of g: "
printh: .asciiz "Please input the value of h: "
printi: .asciiz "Please input the value of i: "
printj: .asciiz "Please input the value of j: "
result: .asciiz "The result is: "

    .text
    .globl main

leaf:
    sub $v0, $a0, $a1
    jr $ra

non_leaf:
    # restore the value of $ra
    addi $sp, $sp, -4
    sw $ra, 0($sp)

    add $a0, $a0, $a1
    add $a1, $a2, $a3

    jal leaf        # 这一步骤，leaf函数的$ra会被non_leaf覆盖掉，所以需要提前储存$ra

    # store the value of $ra
    lw $ra, 0($sp)
    addi $sp, $sp, 4

    jr $ra

main:
    # read the value of g
    la $a0, printg
    li $v0, 4
    syscall
    li $v0, 5
    syscall
    move $s0, $v0

    # read the value of h
    la $a0, printh
    li $v0, 4
    syscall
    li $v0, 5
    syscall
    move $s1, $v0

    # read the value of i
    la $a0, printi
    li $v0, 4
    syscall
    li $v0, 5
    syscall
    move $s2, $v0

    # read the value of j
    la $a0, printj
    li $v0, 4
    syscall
    li $v0, 5
    syscall
    move $s3, $v0

    # print the result string
    la $a0, result
    li $v0, 4
    syscall

    # pass the argument to the function
    move $a0, $s0
    move $a1, $s1
    move $a2, $s2
    move $a3, $s3

    # call the function
    jal non_leaf

    # print the result value
    move $a0, $v0
    li $v0, 1
    syscall

exit: 
    li $v0, 10
    syscall
