# GCD in C language
# int gcd(int n1, int n2) {
#     if (n2 != 0)
#         return gcd(n2, n1 % n2);
#     else
#        return n1;
# }

.globl main
main:

.data

wrongMsg: .asciiz "Input can not be 0 !\n"

.text

initInput:
li $v0, 5    
syscall 
move $s1, $v0 # s1 = n1

beq $s1, $zero, wrongInput # Input can not be 0!

li $v0, 5    
syscall 
move $s2, $v0

beq $s2, $zero, wrongInput # Input can not be 0!

j cal_GCD

wrongInput:
la $a0, wrongMsg
li $v0, 4  
syscall 

j initInput

cal_GCD:
add $a0, $s1, $zero # a0 = s1
add $a1, $s2, $zero # a1 = s2
jal GCD 
add $t0, $v0, $zero #t0 = ans

abs_check:
bgez $t0, print_ans # if t0 >= 0
negu $t0, $t0    # -ans -> ans

print_ans:
move $a0, $t0   # print the answer
li $v0, 1   
syscall  

addi $v0, $zero, 10     #end of program
syscall                

GCD:
add $t1, $a0, $zero   # t1 = n1
add $t2, $a1, $zero   # t2 = n2

beq $t2, $zero, n2is0   #if n2 == 0

add $t3, $t2, $zero   
div $t1, $t2   # t1 / t2
mfhi $a1 # a1 = t1 % t2
move $a0, $t3   
j GCD

n2is0:   
move $v0, $t1
jr $ra

