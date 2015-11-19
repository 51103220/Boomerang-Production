	.file	"float12.c"
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
	subl	$32, %esp
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	add1
	fstps	28(%esp)
	flds	28(%esp)
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
	.globl	add1
	.type	add1, @function
add1:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	flds	8(%ebp)
	fld1
	fsubrp	%st, %st(1)
	fstps	-12(%ebp)
	flds	-12(%ebp)
	flds	8(%ebp)
	fld1
	faddp	%st, %st(1)
	fstps	-12(%ebp)
	flds	-12(%ebp)
	fxch	%st(1)
	fstps	4(%esp)
	fstps	(%esp)
	call	add2
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	add1, .-add1
	.globl	add2
	.type	add2, @function
add2:
.LFB2:
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
	fstps	-4(%ebp)
	flds	-4(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	add2, .-add2
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
