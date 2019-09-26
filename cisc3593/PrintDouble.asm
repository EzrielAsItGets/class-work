.data
	PIDouble: .double 3.1415926535 # more digits

.text
	ldc1 $f2, PIDouble #load Double into coprocessor 1, reg f2
	ldc1 $f4, PIDouble # another copy
	add.d $f12,$f2,$f4
	li $v0,3
	syscall # do it!