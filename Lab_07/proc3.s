.data

x:    .word 5
y:    .word 10

.text

MAIN:
la    $t0, x        #initializing
lw     $s0, 0($t0) # loading x into $s0

la    $t0, y       #initializing
lw    $s1, 0($t0)  # loading y into $s1

addi    $a0, $s0, 0
addi    $a1, $s1, 0

jal    SUM

add     $v0, $v0, $s0
add     $v0, $v0, $s1

addi    $a0, $v0, 0
li    $v0, 1
syscall

j END

SUM:

addi    $sp, $sp, -20

sw    $ra, 0($sp)
sw    $s0, 4($sp)
sw    $s1, 8($sp)

#a. main():x→$s0,y→$s1
#b. sum():p→$s0,q→$s1
#a. sum():m→$a0,n→$a1
#b. sub():a→$a0,b→$a1

sw    $a0, 12($sp)
sw    $a1, 16($sp)

lw    $a0, 12($sp)
lw    $a1, 16($sp)

#load n and m into temp variable
addi    $t1, $a0, 0
addi    $a0, $a1, 1
addi    $a1, $t1, 1

jal    SUB

add     $s0, $v0, 0

lw    $a0, 12($sp)
lw    $a1, 16($sp)

addi    $a0, $a0, -1
addi    $a1, $a1, -1

jal    SUB

add    $s1, $v0, 0

add    $v0, $s0, $s1

lw    $a1, 16($sp)
lw    $a0, 12($sp)
lw    $s1, 8($sp)
lw    $s0, 4($sp)
lw    $ra, 0($sp)

addi    $sp, $sp, 20

jr    $ra
 
SUB:

addi    $sp, $sp, -20

sw    $ra, 0($sp)
sw    $s0, 4($sp)
sw    $s1, 8($sp)
sw    $a0, 12($sp)
sw    $a1, 16($sp)

sub    $v0, $a1, $a0

lw    $a1, 16($sp)
lw    $a0, 12($sp)
lw    $s1, 8($sp)
lw    $s0, 4($sp)
lw    $ra, 0($sp)

addi    $sp, $sp, 20

jr    $ra      #return

END:
li    $v0, 10
syscall
