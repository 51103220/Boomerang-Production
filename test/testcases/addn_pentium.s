	.file	"addn.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"Sum = %ld\n"
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
	subl	$432, %esp
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	movl	$0, 24(%esp)
	jmp	.L2
.L3:
	leal	32(%esp), %eax
	movl	24(%esp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	addl	$1, 24(%esp)
.L2:
	movl	20(%esp), %eax
	cmpl	%eax, 24(%esp)
	jl	.L3
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	leal	32(%esp), %eax
	movl	%eax, (%esp)
	call	calculateSum
	movl	%eax, 28(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	calculateSum
	.type	calculateSum, @function
calculateSum:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	.L6
	movl	sum.1599, %eax
	jmp	.L7
.L6:
	movl	12(%ebp), %eax
	addl	$1073741823, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	sum.1599, %eax
	addl	%edx, %eax
	movl	%eax, sum.1599
	subl	$1, 12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	calculateSum
.L7:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	calculateSum, .-calculateSum
	.local	sum.1599
	.comm	sum.1599,4,4
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
