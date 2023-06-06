    .data
array:
    .word 0x41240000 0xA3009999 

    .text
    .globl main

main:
    # read the array
    la $t0, array

    # 存浮点数的时候尽量用偶数寄存器
    # 不然在存double值的时候之前的float可能会被覆盖掉
    lwc1 $f2, 0($t0)
    lwc1 $f4, 4($t0)

    # print element 1
    mov.s $f12, $f2
    li $v0, 2
    syscall

    # to print a new line
    la $a0, nl
    li $v0, 4
    syscall

    # print element 2
    mov.s $f12, $f4
    li $v0, 2
    syscall

exit: 
    li $v0, 10
    syscall