.data
NeedNum:    .word 39	# you can change the number
result:     .word 0

.text
main:
    la  $s0, NeedNum     # N
    la  $s1, result		 # result
    lw  $t0, 0($s0)      # get N

    li  $t1, 0           # f(n-1)
    li  $t2, 1           # f(n-2)
    lw  $t3, 0($s1)      # f(n)

    li  $t4, 0           # count
    li  $t6, 1           # const for <= 1

fib:
    slt $t5, $t4, $t0    # if(count < n)
    beq $t5, $0, exit 
    ble $t4, $t6, printN # if(count <= 1)
    
    lw  $t1, -4($s1) # f(n-1)
    lw  $t2, -8($s1) # f(n-2)
    add $t3, $t1, $t2    # f(n) = f(n-1) + f(n-2)

    # print number
    sw  $t3, 0($s1) # store f(n)
    move $t1, $t2        # t1 = t2
    move $t2, $t3        # t2 = t3
    addi $t4, $t4, 1     # count++
    addi $s1, $s1, 4     # move to next location in result array
    j fib

printN:
    # if count <= 1 will run here
    sw  $t4, 0($s1) # store count 0...1...
    addi $s1, $s1, 4     # move to next location in result array
    addi $t4, $t4, 1	 #count++
    j fib

exit:
    li  $v0, 10          # end of program
    syscall
