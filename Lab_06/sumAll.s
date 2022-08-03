.data # Section where data is stored in memory (allocated in RAM), similar to variables in higher-level languages
    Enter : .asciiz "\nPlease enter a number: "
    pos_sum : .asciiz "\nSum of positive numbers is: "
    neg_sum : .asciiz "\nSum of negative numbers is: "

.text #Section that contains instructions and program logic
    
     li $s0,0 #this shows the positive number sum
     li $s1,0 #this shows the negative number sum

loop:

     li $v0,4
     la $a0,Enter #This will print out, "Please enter a number:"
     syscall

     li $v0,5
     syscall #This will ask the user for an input
     move $t0,$v0 #this moves registars

     beqz $t0,done # Branches when $t0 == 0

     #if less than zero it is negative number; bltz = Branches when $t0 < 0
     bltz $t0,negative_Num
     
    #else positive number
    add $s0,$s0,$t0 #add to pos_sum
     j skip # this will make the program jump to skip
     
negative_Num:

     add $s1,$s1,$t0 #add to neg_sum
skip:

     j loop #this will jump back to the loop
     
done:

li $v0,4
la $a0, pos_sum #This will print prompt
syscall

move $a0,$s0
li $v0,1
syscall #This will allow to print the immediate value of the sum of positive numbers

li $v0,4
la $a0,neg_sum #This will print the prompt
syscall

move $a0,$s1
li $v0,1
syscall#This will allow to print the immediate value of the sum of negative numbers
