# calculate the minimum of x y and z
    .data

    .text
    .globl main

main:
    # t0 = x
    li $v0, 5
    syscall
    move $t0, $v0

    # t1 = y
    li $v0, 5
    syscall
    move $t1, $v0

    # t2 = z
    li $v0, 5
    syscall
    move $t2, $v0

    # m = t3
    move $t3, $t0

    # if (y < m) then m = y
    slt $t4, $t1, $t3
    li $t5, 1
    bne $t4, $t5, J1
    move $t3, $t1

J1:
    # if (z < m) then m = z
    slt $t4, $t2, $t3
    bne $t4, $t5, J2
    move $t3, $t2

J2:
    move $a0, $t3
    li $v0, 1
    syscall

exit: 
    li $v0, 10
    syscall
