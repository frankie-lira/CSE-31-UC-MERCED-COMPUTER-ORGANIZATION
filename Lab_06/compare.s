.data
       #Q1
   # <,>,<=,>= using slt, beq, bne
   
   
   #Q2
   n: .word 25
   
   #Q3
   str1: .asciiz "Less than\n"
   str2: .asciiz "Less than or equal to\n"
   str3: .asciiz "Greater than\n"
   str4: .asciiz "Greater than or equal to\n"
   prompt: .asciiz "Enter a number: "
       
   .text
   
main:
#display prompt for input
li $v0,4
la $a0, prompt
syscall

#load "25"
la $t0, n
lw $t0, 0($t0)

#gets input and store
li $v0, 5
syscall
move $t1, $v0

#LessThan & GreaterOrEqual
#slt $t2, $t1, $t0
#beq $t2, 1, less_than

#j greater_or_equal

#less_than:
#li $v0, 4
#la $a0, strl
#syscall

#li $v0, 10
#syscall

#greater_or_equal:
#li $v0, 4
#la $a0, str4
#syscall

#li $v0, 10
#syscall

#GreaterThan & LessOrEqual

beq $t1, $t0, less_or_equal
slt $t2, $t1, $t0
beq $t2, 1, less_or_equal

j greater_than

greater_than:
li $v0, 4
la $a0, str3
syscall
li $v0, 10
syscall

less_or_equal:
li $v0, 4
la $a0, str2
syscall
li $v0, 10
syscall

