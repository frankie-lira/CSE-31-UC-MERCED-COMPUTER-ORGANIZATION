        .data
#n:      .word 13
str1:    .asciiz "\nPlease enter a nember:\n"


        .text
main: 	add     $t0, $0, $zero

        li $v0, 4
        la $a0, str1
        syscall      #This is printing string

        li $v0, 5    #This is taking in the user's input
        syscall

        move    $t3, $v0 #TPS #4 put input into t3

        addi    $t1, $zero, 1
		#la      $t3, n
		#lw      $t3, 0($t3)
		
fib: 	beq     $t3, $0, finish
		add     $t2,$t1,$t0
		move    $t0, $t1
		move    $t1, $t2
		subi    $t3, $t3, 1
		j       fib
		
finish: addi    $a0, $t0, 0
		li      $v0, 1		
		syscall			
		li      $v0, 10		
		syscall			

