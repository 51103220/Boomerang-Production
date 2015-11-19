	.file	"float10.c"
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
	subl	$96, %esp
	leal	52(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	movl	52(%esp), %eax
	movl	88(%esp), %edx
	movl	%edx, 36(%esp)
	movl	84(%esp), %edx
	movl	%edx, 32(%esp)
	movl	80(%esp), %edx
	movl	%edx, 28(%esp)
	movl	76(%esp), %edx
	movl	%edx, 24(%esp)
	movl	72(%esp), %edx
	movl	%edx, 20(%esp)
	movl	68(%esp), %edx
	movl	%edx, 16(%esp)
	movl	64(%esp), %edx
	movl	%edx, 12(%esp)
	movl	60(%esp), %edx
	movl	%edx, 8(%esp)
	movl	56(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	add10
	fstps	92(%esp)
	flds	92(%esp)
	fstpl	4(%esp)
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
	.globl	add10
	.type	add10, @function
add10:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	flds	8(%ebp)
	flds	12(%ebp)
	faddp	%st, %st(1)
	fildl	16(%ebp)
	fstps	-4(%ebp)
	flds	-4(%ebp)
	faddp	%st, %st(1)
	fildl	20(%ebp)
	fstps	-4(%ebp)
	flds	-4(%ebp)
	faddp	%st, %st(1)
	flds	24(%ebp)
	faddp	%st, %st(1)
	flds	28(%ebp)
	faddp	%st, %st(1)
	fildl	32(%ebp)
	fstps	-4(%ebp)
	flds	-4(%ebp)
	faddp	%st, %st(1)
	fildl	36(%ebp)
	fstps	-4(%ebp)
	flds	-4(%ebp)
	faddp	%st, %st(1)
	flds	40(%ebp)
	faddp	%st, %st(1)
	flds	44(%ebp)
	faddp	%st, %st(1)
	fstps	-4(%ebp)
	flds	-4(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	add10, .-add10
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
