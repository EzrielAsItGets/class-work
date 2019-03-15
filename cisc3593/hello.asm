.data
	myMessage: .asciiz "Hello MIPS World!\n"
		#start with. See the chouces
		#Choose asciiz. null terminated string

.text
	li $v0, 4 #set up return value (ignore for now)
	la $a0, myMessage #load the message into a0
	syscall #do it!