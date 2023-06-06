    .data
nl:
    .ascii "\n"

    .text
    .globl main
main:

    # enter a value for x and store it into s0
    li $v0, 5
    syscall
    move $s0, $v0

    # enter a value for y and store it into s1
    li $v0, 5
    syscall
    move $s1, $v0

    # y = y * 2
    sll $s1, $s1, 1

    # s2 = x - 2*y
    sub $s2, $s0, $s1

    # s3 = x - 2*y -40
    addi $a0, $s2, -40

    # print the results
    li $v0, 1
    syscall
    

exit:
    li $v0, 10
    syscall