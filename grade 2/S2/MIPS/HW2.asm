# selectionSort in C language

#for (int i = 0; i < n - 1; i++) {
#    index = i;
#    small = arr[i];
#    for (int j = i + 1; j < n; j++) {
#        if (arr[j] < small) {
#            small = arr[j];
#            index = j;
#        }
#    }
#    int temp = arr[i];
#    arr[i] = arr[index];
#    arr[index] = temp;
#}

.data
arr:    .space 1000
space:  .asciiz " "

.text
main:
    la $s0, arr               # $s0 = &arr[0]
    la $s1, arr               # $s1 = &arr[0]
    jal input

input:
    li $v0, 5                  # enter the number
    syscall
    move $t9, $v0

    beq $t9, $zero, start       

    sw $t9, ($s1)              # Store input in arr[index]
    addi $s1, $s1, 4           # arr[index++]
    addi $t0, $t0, 1           # count++
    jal input                  # Call input again until input == 0        

start:
    li $t1, -1                 # $t1 = -1
    add $t2, $t2, $t0
    addi $t2, $t2, -1          # $t2 = count - 1

    jal selectionSort1

selectionSort1:
    addi $t1, $t1, 1           # i++
    move $t3, $t1              # $t3 = i
    move $a1, $t1              # $a1 = i

    li $t4, 0                  # $t4 = 0
    sll $t4, $t1, 2            # $t4 = i * 4
    add $t4, $t4, $s0          # Get address of arr[i]
    lw $t5, 0($t4)             # $t5 = arr[i]
    move $s2, $t5              # $s2 = arr[i]= small 

    blt $t1, $t2, selectionSort2  # if i < count - 1
    jal reset

selectionSort2:
    beq $a1, $t0, swap         # if j == count     

    sll $t6, $a1, 2            # $t6 = j * 4
    add $t6, $t6, $s0          # arr[j]
    lw $t7, 0($t6)             # $t7 = arr[j]

    bgt $s2, $t7, update_small    # if  small > arr[j]   

    addi $a1, $a1, 1           # j++
    jal selectionSort2

update_small:
    move $s2, $t7              # small = arr[j]
    move $t3, $a1              # index = j
    addi $a1, $a1, 1           # j++
    jal selectionSort2

swap:
    sll $t6, $t1, 2            # $t6 = i * 4
    add $t6, $t6, $s0          # arr[i]
    lw $t7, 0($t6)             # $t7 = arr[i]

    sll $t8, $t3, 2            # $t8 = index * 4
    add $t8, $t8, $s0          # arr[index]
    lw $t5, 0($t8)             # $t5 = arr[index]

    move $t4, $t5              # temp = arr[index]
    sw $t7, 0($t8)             # arr[index] = arr[i]
    sw $t4, 0($t6)             # arr[i] = temp
    jal selectionSort1

reset:
    li $t6, 0                  # $t6 = 0
    li $t7, 0                  # $t7 = 0
    jal print_ans

print_ans:
    beq $t7, $t0, exit         # if k == count  

    sll $t6, $t7, 2            # $t6 = k * 4
    add $t6, $t6, $s0          # arr[k]
    lw $a0, 0($t6)             # $a0 = arr[k]
    li $v0, 1                  # pirnt ans
    syscall
    la $a0, space              # print space
    li $v0, 4
    syscall

    addi $t7, $t7, 1           # k++
    jal print_ans

exit:
    li $v0, 10                 # End of program           
