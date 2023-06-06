# Recursive function: Factorial

# java pseudo code
# static int factorial (int n)
# {
#     if (n <= 0)
#         return 1;
#     else
#         return (n * factorial(n-1))
# }

# fact = 00400024, tmpl = 00400044, fact_return = 0040004c

.data

.text
.globl main

main:

fact: 
    addi $sp, $sp, -8               # space for two words
    sw $ra, 4($sp)                  # save return address - push
    sw $a0, 0($sp)                  # 把[1,n]里每一个值都存到stack里，最后乘起来放进
    li $v0, 1                       # initialization of $v0, since the result of factorial is stored in $v0
    ble $a0, $zero, fact_return     # if n <= 0 then goto fact_return, end loop
    addi $a0, $a0, -1               # n--
    jal fact

tmpl:
    lw $a0, 0($sp)                  
    mul $v0, $v0, $a0

fact_return:
    lw $ra 4($sp)                   # 把在stack当中的return address存入$ra
    addi $sp, $sp, 8                
    jr $ra                          # return to the caller
