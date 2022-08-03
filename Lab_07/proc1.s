.data
m:         .word 10
n:         .word 5

.text
MAIN:    la $t0, m            # Load address of m
lw $a0, 0($t0)        # a0 = m
la $t0, n        # Load address of n
lw $a1, 0($t0)        # a1 = n

#addi $ra,$zero, 4194344    # Replace 0 with a correct return address
jal SUM


li $v0, 1
addi $a0, $v1, 0     # Print out result
syscall

j END

SUM:    add $v1, $a0, $a1
jr $ra


END:
