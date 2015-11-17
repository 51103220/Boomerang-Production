	.file	"plusandminus.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
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
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	plusandminus
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
	.globl	plusandminus
	.type	plusandminus, @function
plusandminus:
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
	jg	.L4
	movl	$0, %eax
	jmp	.L5
.L4:
	cmpl	$100, 8(%ebp)
	jle	.L6
	movl	$100, %eax
	jmp	.L5
.L6:
	movl	8(%ebp), %eax
	subl	$1, %eax
	movl	%eax, (%esp)
	call	plusandminus
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$2, %eax
	movl	%eax, (%esp)
	call	plusandminus
	addl	%ebx, %eax
.L5:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	plusandminus, .-plusandminus
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
