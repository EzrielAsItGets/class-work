.data
	PI: .float 3.14
.text
	li $v0,2 # 2 for cloat
	lwc1 $f12,PI #load WORD into coprocessor 1
		# (special for this purpose)
	syscall