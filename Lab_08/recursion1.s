	.data

str:	.asciiz "\nPlease enter a integer:\n" 

        .text
main: 		addi	$sp, $sp, -4	# Moving stack pointer to make room for storing local variables (push the stack frame)
		
		li	$v0, 4
		la	$a0, str
		syscall
		
		
		li	$v0, 5
		syscall
		
		add	$a0, $v0, $0 # $a0 used as input argument 
		
		jal	recursion	# Call recursion(x)
		
		
		sw	$v0, 0($sp)
		li	$v0, 1
		lw	$a0, 0($sp)
		syscall
		
		j	end		# Jump to end of program


# Implementing recursion
recursion:	addi	$sp, $sp, -12	# Push stack frame for local storage
		#storage created for 3 values

		sw	$ra, 0($sp) 
		
		#these 2 lines below correspond to the lines in C: the first if statment 
		
		bne	$a0, 10, not_ten
		
		li	$v0, 2
		
		j	end_recur
			
not_ten:	
		bne	$a0, 11, not_eleven # checking to see if m/$a0 is 0

		li	$v0, 1
		
		j	end_recur		

not_eleven:	sw	$a0, 4($sp) 	
		#(Prepare new input argument, i.e. m + 2)
		addi	$a0, $a0, 2 # bc in C: "m + 2"
		
		jal	recursion	# Call recursion(m + 2)
		
		sw	$v0, 8($sp)
		
		lw	$a0, 4($sp)
		addi	$a0, $a0, 1
		
		jal	recursion	# Call recursion(m + 1)
		
		lw	$s0, 8($sp) #laod $v0 into $s0 because we need to use $v0
		lw 	$a0, 4($sp) 
		
		add	$v0, $v0, $s0
		add	$v0, $v0, $a0
		
		j	end_recur
		

# End of recursion function	
end_recur:	lw	$ra, 0($sp)	

		addi	$sp, $sp, 12	# Pop stack frame 
		jr	$ra

# Terminating the program
end:		addi	$sp, $sp 4	# Moving stack pointer back (pop the stack frame)
		li	$v0, 10 
		syscall
