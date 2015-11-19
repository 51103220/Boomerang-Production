	.file	"float2.c"
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
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	movl	20(%esp), %eax
	movl	24(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	add2
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
	.globl	add2
	.type	add2, @function
add2:
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
	fstps	-4(%ebp)
	flds	-4(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	add2, .-add2
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
