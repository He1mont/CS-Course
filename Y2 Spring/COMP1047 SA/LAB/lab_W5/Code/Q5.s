    .data
A:  .word 4 6 12 -8 5
B:  .word 3 2 1 4 0
nline: .asciiz "\n"

# Update B[0]= 2*A[3]+B[4] and then print out all elements in B.

    .text
    .globl main

main:
    la $s0, A            
    lw $t0, 12($s0)     # t0 = A[3]
    la $s1, B
    lw $t1, 16($s1)     # t1 = B[4]

    sll $t0, $t0, 1     # t0 = 2*A[3]
    add $t0, $t0, $t1
    sw $t0, 0($s1)

    li $s2, 5           # s2 = length(B)
    la $s3, nline

loop:
    lw $a0, ($s1)       # print an integer
    li $v0, 1
    syscall

    la $a0, nline
    li $v0, 4
    syscall             

    addi $s2, $s2, -1   
    addi $s1, $s1, 4

    bne $s2, $zero, loop

exit:
    li $v0, 10
    syscall