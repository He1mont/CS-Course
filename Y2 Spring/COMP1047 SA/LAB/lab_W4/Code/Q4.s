    .data
array:
    .float 10.25 -128.6

    .text
    .globl main

main:
    la $t0, array
    lwc1 $f2, 0($t0)
    lwc1 $f4, 4($t0)

    # print addition
    add.s $f6, $f2, $f4
    mov.s $f12, $f6
    li $v0, 2
    syscall

    # to print a new line
    la $a0, nl
    li $v0, 4
    syscall

    # print multiplication
    mul.s $f8, $f2, $f4
    mov.s $f12, $f8
    li $v0, 2
    syscall

exit: 
    li $v0, 10
    syscall