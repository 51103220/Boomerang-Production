	.file	"fiborecur.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"Fibonacci series"
.LC2:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$0, 24(%esp)
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	movl	$.LC1, (%esp)
	call	puts
	movl	$1, 28(%esp)
	jmp	.L2
.L3:
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	Fibonacci
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	addl	$1, 24(%esp)
	addl	$1, 28(%esp)
.L2:
	movl	20(%esp), %eax
	cmpl	%eax, 28(%esp)
	jle	.L3
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	Fibonacci
	.type	Fibonacci, @function
Fibonacci:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	cmpl	$0, 8(%ebp)
	jne	.L6
	movl	$0, %eax
	jmp	.L7
.L6:
	cmpl	$1, 8(%ebp)
	jne	.L8
	movl	$1, %eax
	jmp	.L7
.L8:
	movl	8(%ebp), %eax
	subl	$1, %eax
	movl	%eax, (%esp)
	call	Fibonacci
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	subl	$2, %eax
	movl	%eax, (%esp)
	call	Fibonacci
	addl	%ebx, %eax
.L7:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	Fibonacci, .-Fibonacci
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
