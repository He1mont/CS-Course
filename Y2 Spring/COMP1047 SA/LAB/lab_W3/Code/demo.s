    .data
prompt:
    # normally we use .asciiz to store a string
    .asciiz "Please enter an integer: "
    
array:
    .word 3 5 10 2      # 数组被存在内存里的特定区域里

    .text
    .globl main
main:
    # Display the prompt
    la $a0, prompt
    li $v0, 4
    syscall

    # Read input value and save it to s0
    li $v0, 5
    syscall
    move $s0, $v0

    # write this value into memory
    la $t7, array       # 此时t7里存的只是数组的地址，而不是第一个数字3
    sw $s0, 0($t7)      # 将t7里的值（即数组的地址）存到s0里面去

exit:
    li $v0, 10
    syscall
    