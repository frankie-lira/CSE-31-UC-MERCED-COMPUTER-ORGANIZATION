.data

original_list: .space 100
sorted_list: .space 100

str0: .asciiz "Enter size of list (between 1 and 25): "
str1: .asciiz "Enter one list element: \n"
str2: .asciiz "Content of original list: "
str3: .asciiz "Enter a key to search for: "
str4: .asciiz "Content of sorted list: "
strYes: .asciiz "Key found!"
strNo: .asciiz "Key not found!"



.text

#This is the main program.
#It first asks user to enter the size of a list.
#It then asks user to input the elements of the list, one at a time.
#It then calls printList to print out content of the list.
#It then calls inSort to perform insertion sort
#It then asks user to enter a search key and calls bSearch on the sorted list.
#It then prints out search result based on return value of bSearch
main:
    addi $sp, $sp -8
    sw $ra, 0($sp)
    li $v0, 4
    la $a0, str0
    syscall
    li $v0, 5    #read size of list from user
    syscall
    move $s0, $v0
    move $t0, $0
    la $s1, original_list
loop_in:
    li $v0, 4
    la $a0, str1
    syscall
    sll $t1, $t0, 2
    add $t1, $t1, $s1
    li $v0, 5    #read elements from user
    syscall
    sw $v0, 0($t1)
    addi $t0, $t0, 1
    bne $t0, $s0, loop_in
    move $a0, $s1
    move $a1, $s0
        
           jal inSort    #Call inSort to perform insertion sort in original list
    
    sw $v0, 4($sp)
    li $v0, 4
    la $a0, str2
    syscall
    la $a0, original_list
    move $a1, $s0
    jal printList    #Print original list
    li $v0, 4
    la $a0, str4
    syscall
    lw $a0, 4($sp)
    jal printList    #Print sorted list
    
    li $v0, 4
    la $a0, str3
    syscall
    li $v0, 5    #read search key from user
    syscall
    move $a3, $v0
    lw $a0, 4($sp)
    jal bSearch    #call bSearch to perform binary search
    
    beq $v0, $0, notFound
    li $v0, 4
    la $a0, strYes
    syscall
    j end
        
notFound:
    li $v0, 4
    la $a0, strNo
    syscall
end:
    lw $ra, 0($sp)
    addi $sp, $sp 8
    li $v0, 10
    syscall
        
        
#printList takes in a list and its size as arguments.
#It prints all the elements in one line.
printList:
        #Your implementation of printList here
        move $t1, $a0 # Initializing A[0]
        li $s0, 0 # Initializing i = 0
        
forLoop:
        slt $t0, $s0, $a1  # checking i < n and setting $t1 = 0 if false
        beq $t0, $zero, break # i is bigger than n so we break out of the loop
        
        lw $a0, 0($t1) # $a0 = $t1
        li $v0, 1
        syscall
        
        li $a0, 32 # this is the space in ASCII
        li $v0, 11
        syscall
        
        addi $t1, $t1, 4 # increment a0 by 4 to get to next element
        addi $s0, $s0, 1 # i += 1
        j forLoop
        
break:
        li $v0, 4
        la $a0, original_list
        jr $ra
        
#inSort takes in a list and it size as arguments.
#It performs INSERTION sort in ascending order and returns a new sorted list
#You may use the pre-defined sorted_list to store the result
inSort:
        #Your implementation of inSort here
        li $t1, 1 # Initializing i = 1
        li $t2, 0 # other i for transfer
        la $t8, original_list # transfer array index
        la $t9, sorted_list #Get address of sorted list
    # t9 will be copy array
     
TransferLoop:
        bgt $t1, $a1, resett # iterate
        lw $t5, ($t8) #Get the data from original_list
        sw $t5, ($t9) #Store the data from original_list to sorted_list
        addi $t8, $t8, 4 #Move the address one over
        addi $t9, $t9, 4 #Move the address one over
        addi $t1, $t1, 1 # i++
        j TransferLoop
        
        
resett:
        la $t9, sorted_list

sortLoop:
        bge $t2, $a1, forEnd # iterate and if i > n exit the loop
        move $t3, $t2 # set another j = i
        
NestedWhile:
        mul $t5, $t3, 4 # 4 * i
        add $t0, $t9, $t5 # assigning A[4 * i]
        
        ble $t3, 0, WhileEnd # as long as #t3 > 0 while will run
        
        lw $t7, 0($t0) # $t7 = A[i]
        lw $t6, -4($t0)# $t6 = A[j-1]
        
        bge $t7, $t6, WhileEnd # as long as arr[i] < arr[j-i]
        
        lw $t4, 0($t0) # $t4 = A[j]
        sw $t6, 0($t0)
        sw $t4, -4($t0) # $t4 = A[j-1]
        
        subi $t3, $t3, 1
        j NestedWhile
        
WhileEnd:
        addi $t2, $t2, 1
        j sortLoop

forEnd:
        la $v0, sorted_list
        jr $ra

#bSearch takes in a list, its size, and a search key as arguments.
#It performs binary search RECURSIVELY to look for the search key.
#It will return a 1 if the key is found, or a 0 otherwise.
#Note: you MUST NOT use iterative approach in this function.
bSearch:
        #a0 is the sorted list
        #a3 is the value being searched for
        #a1 is the size
        
        addi $sp, $sp, -4
        sw $ra, 0($sp) #Store the return addresss
        
        bne $s3, $zero, SkipAddressChange1
        add $s0, $zero, $zero #Is the Lo(Start) of the array
        addi $s3, $zero, 1
        
SkipAddressChange1:
        bgt $s0, $a1, SetVtoZero #The lower bound is greater than the upper meaning the search is over
        addi $t3, $zero, 4 #Get number 4
        add $t1, $a1, $s0 #adds Lo + High
        sra $t1, $t1, 1 #(Lo + High) /2 = Mid
        mul $t3, $t3, $t1 #  Mid number * 4
        add $t0, $t3, $a0
        lw $t2, 0($t0)
        
        beq $t2, $a3, foundNumber #If the middle number is equal to the key value
        
        bgt $t2, $a3, binary_lower_half # middle < key. Check lower half move Hi
        
binary_lower_half:
        addi $a1, $t1, -1 #High = Mid - 1
        j bSearch #Recursively call bsearch on the lower half
                
binary_upper_half:
        addi $s0, $t1, 1 #Low = Mid + 1
        j bSearch #Recursively call bsearch on the upper half
        
foundNumber:
        addi $v0, $zero, 1 #This Retuns 1
        j binaryReturn
        
SetVtoZero:
        add $v0, $zero, $zero #This line Returns 0
        
binaryReturn:
        sw $ra, 0($sp)
        addi $sp, $sp, 4 #This is Clearing the Stack
        jr $ra
