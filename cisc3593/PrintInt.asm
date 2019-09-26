.data
	decIndep: .word 1776

.text
	li $v0,1 # 1 is for integer
	lw $a0, decIndep #load WORD
	syscall # do it!