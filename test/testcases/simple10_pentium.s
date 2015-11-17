	.file	"simple10.c"
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
	subl	$64, %esp
	leal	52(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	leal	56(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	movl	56(%esp), %edx
	movl	52(%esp), %eax
	movl	$8, 36(%esp)
	movl	$7, 32(%esp)
	movl	$6, 28(%esp)
	movl	$5, 24(%esp)
	movl	$4, 20(%esp)
	movl	$3, 16(%esp)
	movl	$2, 12(%esp)
	movl	$1, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	add10
	movl	%eax, 60(%esp)
	movl	60(%esp), %eax
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
	movl	20(%ebp), %eax
	movl	16(%ebp), %edx
	addl	%eax, %edx
	movl	24(%ebp), %eax
	addl	%eax, %edx
	movl	28(%ebp), %eax
	addl	%eax, %edx
	movl	32(%ebp), %eax
	addl	%eax, %edx
	movl	36(%ebp), %eax
	addl	%eax, %edx
	movl	40(%ebp), %eax
	addl	%eax, %edx
	movl	44(%ebp), %eax
	addl	%eax, %edx
	movl	12(%ebp), %eax
	addl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	add10, .-add10
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
