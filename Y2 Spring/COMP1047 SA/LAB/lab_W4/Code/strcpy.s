# x is the base address of 1st array, contained in $a0
# y is the base address of 2nd array, contained in $a1
# copy the content of x into y    

    .data

    .text
    .globl main

main:




exit:
    li $v0, 10
    syscall