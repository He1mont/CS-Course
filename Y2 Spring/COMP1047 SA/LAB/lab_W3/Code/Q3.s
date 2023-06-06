    .data
array:
    .word 0x0000002D 0xFFFFFF7E     # 0x: interpreted as hex
nl:
    .asciiz "\n"

    .text
    .globl main
main:
    # read the array
    la $t0, array       # load the base address into t0
    lw $s0, 0($t0)      # load the first element into $s0
    lw $s1, 4($t0)      # load the second element into $s1

    # print the first element
    move $a0, $s0
    li $v0, 1
    syscall
    
    # to print a new line
    la $a0, nl
    li $v0, 4
    syscall

    # print the second element
    move $a0, $s1
    li $v0, 1
    syscall

    # to exit the program
exit:
    li $v0, 10
    syscall