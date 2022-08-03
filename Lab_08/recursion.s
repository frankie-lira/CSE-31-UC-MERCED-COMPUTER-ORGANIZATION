        .data

# TPS 2 #3 (statement to be displayed)
str:    .asciiz "\nPlease enter a integer:\n"

        .text
main: 		addi $sp, $sp, -4	# Moving stack pointer to make room for storing local variables (push the stack frame)
		# TPS 2 #3 (display statement)
        li    $v0, 4
        la    $a0, str
        syscall

		
		# TPS 2 #4 (read user input)
        li    $v0, 5
        syscall

        add    $a0, $v0, $0 # $a0 used as inout argument

		jal recursion	# Call recursion(x)
		
		# TPS 2 #6 (read user input)
        sw    $v0, 0($sp)
        li    $v0, 1
        lw    $a0, 0($sp)
        syscall

		j end		# Jump to end of program


# Implementing recursion
recursion:	addi $sp, $sp, -12	# Push stack frame for local storage

		# TPS 2 #7 
		
        sw    $ra, 0($sp)

        #the line below correspond to the line in C: the first if statment

        bne $a0, -1 , not_minus_one

		
		#addi $t0, $a0, 1
		#bne $t0, $zero, not_minus_one
		
		# TPS 2 #8 (update returned value)
        li    $v0, 1

       
		j end_recur
			
not_minus_one:	bne $a0, 0, not_zero

		# TPS 2 #9 (update returned value)
		
        li    $v0, 3

		j end_recur		

not_zero:	sw $a0, 4($sp) 	
		# TPS 2 #11 (Prepare new input argument, i.e. m - 2)
		addi    $a0, $a0, -2   # bc in C: "m-2"

		jal recursion	# Call recursion(m - 2)
		
		# TPS 2 #12 
        sw    $v0, 8($sp)

		
		
		# TPS 2 #13 (Prepare new input argument, i.e. m - 1)
        lw    $a0, 4($sp)
        addi    $a0, $a0, -1

		
		jal recursion	# Call recursion(m - 1)
		
		# TPS 2 #14 (update returned value)
        lw    $s0, 8($sp)
        add    $v0, $v0, $s0
        lw    $a0, 4($sp)


		j end_recur
		

# End of recursion function	
end_recur:  lw    $ra, 0($sp)# TPS 2 #15

		addi $sp, $sp, 12	# Pop stack frame 
		jr $ra

# Terminating the program
end:	addi $sp, $sp 4	# Moving stack pointer back (pop the stack frame)
		li $v0, 10 
		syscall
