## MIPS Programming 2

### MIPS Decision Making and Branching

##### 1. Branching and Control flow

-   Branch instruction affect the Program Counter and hence control the flow of the program
-   **Conditional branch** instructions
-   **Unconditional branch** instructions



##### 2. Branch Instructions

-   `beq a, b, L		# branch on equal`
    -   go to label L if a == b

-   `bne a, b, L		# branch on equal`
    -   go to label L if a != b

-   `j L		        # unconditional jump`
    -   unconditional jump to label L

-   `jr $s0          # jump regiter`
    -   jump into the location stored in the register



##### 3. Inequality in MIPS

-   set on Less Than
    -   `slt rd, rs, rt				# if (rs < rt) then rd = 1; else rd = 0;`
    -   `slti rt, rs, constant      # if (rs < constant) then rt = 1; else rt = 0`



##### 4. Signed vs. Unsigned 'slt'

-   Signed comparison: `slt, slti`
-   Unsigned comparison: `sltu, sltui`



### MIPS Arrays

##### 5. Another way to load the array head

-   Give the base address: 0x12348000	(address of the first array element)

-   Use **lui + ori** to load 32-bit base address into a register

-   **lui** (load upper immediate)

    -   `lui $s0, 0x1234			# $s0 = 0x12340000`

-   **ori** (or immediate)

    -   `ori $s0, $s0, 0x8000 	# $s0 = 0x12348000`

-   Difference

    -   If the constant would fit 16 bits, use `li`

    -   If the constant needs `(16,32]` bits, use `lui + ori`



### MIPS Procedures

##### 6. Procedures

-   Procedures are portion of code, within a larger program, which runs frequently
-   It helps to
    -   reduce code duplication
    -   improve code re-usability
    -   decompose complex programs into manageable parts
-   Other names
    -   Methods - java and other OO languages
    -   Functions - C, C++, Haskell
    -   Routines, subroutines



##### 7. Procedure Calling Conventions

-   Caller:
    -   passes arguments to callee
-   Callee:
    -   **must not overwrite** registers or memory needed by the caller
    -   returns to the point of call
    -   returns the result to caller

-   MIPS conventions
    -   Call procedure: jump and link `(jal)`
    -   Return from procedure: jump register `(jr)`
    -   Argument value: `$a0 - $a3`
    -   Return value: `$v0, ($v1 for 64-bit double)`

-   One example:
    -   `jal`: jumps to `simple` and saves PC+4 to the return address register `($ra)`
    -   `jr $ra`: jumps to address in `$ra`, in this case, `$ra = 0x00400204`

<img src="assets/Screenshot 2023-03-17 at 17.00.25.png" alt="Screenshot 2023-03-17 at 17.00.25" style="zoom:50%;" />



##### 8. Another example

-   C Programming Code

    ```c
    int main()
    {
        int y;
        y = diffofsums(2,3,4,5);	// 4 arguments
       	...
    }
    int diffofsums(int f, int g, int h, int i)
    {
        int result;
        result = (f+g) - (h+i);
        return result;
    }
    ```

-   MIPS assembly code

    ```assembly
    main:
    	addi $a0, $0, 2		# a0 = 2
    	addi $a1, $0, 3		# a1 = 3
    	addi $a2, $0, 4		# a2 = 4
    	addi $a3, $0, 5		# a3 = 5
    	jal diffofsums		# call procedure
    	add $s0, $v0, $0	# y = returned value
    	
    # $s0 = result
    diffofsums:
    	add $s2, $a0, $a1	# s2 = f + g
    	add $s1, $a2, $a3	# s1 = h + i
    	sub $s0, $s2, $s1   # result = (f+g) - (h+i)
    	add $v0, $s0, $0	# put return value in $v0
    	jr $ra				# return to caller
    ```

    -   `diffofsums` **overwrite** 3 registers: `$s0, $s1, $s2`
    -   `diffofsums` can use **stack** to temporarily store registers

    

-   **Use Stack to Protect Caller Values**

    <img src="assets/IMG_0858EE0DEB62-1.jpeg" alt="IMG_0858EE0DEB62-1" style="zoom: 25%;" />

    ```assembly
    diffofsums:
    	addi $sp, $sp, -12	# make space on stack to store 3 registers
    	sw $s0, 8($sp)		# save $s0 on stack
    	sw $s1, 4($sp)		# save $s1 on stack
    	sw $s2, 0($sp)		# save $s2 on stack
    	
    	add $s2, $a0, $a1	# s2 = f + g
    	add $s1, $a2, $a3	# s1 = h + i
    	sub $s0, $s2, $s1   # result = (f+g) - (h+i)
    	add $v0, $s0, $0	# put return value in $v0
    	
    	lw $s2, 0($sp)		# restore $s2 from stack
    	lw $s1, 4($sp)		# restore $s1 from stack
    	lw $s0, 8($sp)		# restore $s0 from stack
    	addi $sp, $sp, 12	# deallocate stack space
    	
    	jr $ra				# return to caller
    ```


-   MIPS registers are divided into two types: 

    <img src="assets/Screenshot 2023-03-17 at 17.51.08.png" alt="Screenshot 2023-03-17 at 17.51.08" style="zoom:50%;" />



