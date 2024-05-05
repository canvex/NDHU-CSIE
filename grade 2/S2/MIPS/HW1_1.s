.data
space:  .asciiz " "

.text
main:
    li $v0, 5           # input from console
    syscall
    
    move $t0, $v0       # input n
    li $t1, 0           # f(n-1)
    li $t2, 1           # f(n-2)
    li $t3, 0           # f(n)
    li $t4, 0           # count
    li $t6, 1           # const for <= 1

fib:
    slt $t5, $t4, $t0   # if(count < n)
    beq $t5, $0, exit 
    ble $t4, $t6, printN   # if(count <= 1)
    add $t3, $t1, $t2   # f(n) = f(n-1) + f(n-2)

    li $v0, 1           # print number
    move $a0, $t3
    syscall
    
    li $v0, 4           # print space
    la $a0, space
    syscall

    move $t1, $t2       # t1 = t2
    move $t2, $t3       # t2 = t3
    addi $t4, $t4, 1    # count++
    j fib

printN:
    # if count <= 1 will run here
    li $v0, 1           # print 0...1...
    move $a0, $t4
    syscall
    
    li $v0, 4           # print space
    la $a0, space
    syscall
    
    addi $t4, $t4, 1    # count++
    j fib

exit:
    li $v0, 10          # end of program
    syscall