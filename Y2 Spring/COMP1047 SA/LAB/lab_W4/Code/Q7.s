# read two integer numbers A and B
# and indicate if one of these numbers is multiple of the other one

    .data

input1: .asciiz "Please give two integer numbers for A and B: \n"
print1: .asciiz "x is a multiple of y."
print2: .asciiz "y is a multiple of x."
print3: .asciiz "Neither of them is a multiple of the other."

    .text
    .globl main

main:
    # print the string
    la $a0, input1
    li $v0, 4
    syscall

    # read the value for A and B
    li $v0, 5
    syscall
    move $t0, $v0   # t0 = x
    li $v0, 5
    syscall
    move $t1, $v0   # t1 = y

    # t2 = x mod y
    div $t0, $t1
    mfhi $t2

    # t3 = y mod x
    div $t1, $t0
    mfhi $t3

    # if t2 == 0 then                     # case 1
    #     print 'x is a multiple of y'    
    # else if t3 == 0 then                # case 2
    #     print 'y is a multiple of x'    
    # else                                # case 3
    #     print 'Neither x nor y is a multiple of the other.'
    # end if

    beq $t2, $0, case1
    beq $t3, $0, case2
    j, case3

case1:
    la $a0, print1
    li $v0, 4
    syscall
    j, exit

case2:
    la $a0, print2
    li $v0, 4
    syscall
    j, exit

case3:
    la $a0, print3
    li $v0, 4
    syscall
    j, exit

exit:
    li $v0, 10
    syscall
