	.file	"addsum.c"
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
	subl	$832, %esp
	leal	16(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	movl	$0, 20(%esp)
	jmp	.L2
.L3:
	leal	32(%esp), %eax
	movl	20(%esp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	addl	$1, 20(%esp)
.L2:
	movl	16(%esp), %eax
	cmpl	%eax, 20(%esp)
	jl	.L3
	movl	16(%esp), %eax
	movl	24(%esp), %edx
	movl	%edx, 12(%esp)
	leal	432(%esp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	32(%esp), %eax
	movl	%eax, (%esp)
	call	sumarray
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
	.globl	sumarray
	.type	sumarray, @function
sumarray:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -8(%ebp)
	jmp	.L6
.L7:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	sum.1605, %eax
	addl	%edx, %eax
	movl	%eax, sum.1605
	addl	$1, -8(%ebp)
.L6:
	movl	-8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	.L7
	movl	$0, -4(%ebp)
	jmp	.L8
.L9:
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	sum2.1606, %eax
	addl	%edx, %eax
	movl	%eax, sum2.1606
	addl	$1, -4(%ebp)
.L8:
	movl	-4(%ebp), %eax
	cmpl	20(%ebp), %eax
	jl	.L9
	movl	sum.1605, %edx
	movl	sum2.1606, %eax
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	sumarray, .-sumarray
	.local	sum.1605
	.comm	sum.1605,4,4
	.local	sum2.1606
	.comm	sum2.1606,4,4
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
