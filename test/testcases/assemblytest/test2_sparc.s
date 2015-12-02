	.file	"simple1.c"
	.section	".rodata"
	.align 8
.LC0:
	.asciz	"%d"
	.align 8
.LC1:
	.asciz	"Sum = %ld\n"
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	04
main:
	save	%sp, -104, %sp
	add	%fp, -8, %g1
	mov	%g1, %o1
	sethi	%hi(.LC0), %g1
	or	%g1, %lo(.LC0), %o0
	call	__isoc99_scanf, 0
	 nop
	ld	[%fp-8], %g1
	mov	%g1, %o0
	mov 2, %g1
	add %g1, 8, %g1
	st %g1, [%fp - 12]
	ld [%fp - 12], %g2
	mov %g2, %o1
	add %o1, 2 , %o1
	mov %o1, %o2
	st %02, [%fp - 12]
	ld [%fp - 12], %o1
	add %o1, 2 , %o1
	mov %o1, %o2
	st %02, [%fp - 12]
	ld [%fp - 12], %o1
	add %o1, 2 , %o1
	mov %o1, %o2
	st %02, [%fp - 12]
	ld [%fp - 12], %o1
	add %o1, 2 , %o1
	mov %o1, %o2
	st %02, [%fp - 12]
	ld [%fp - 12], %o1
	add %o1, 2 , %o1
	mov %o1, %o2
	call	add1, 0
	 nop
	st	%o0, [%fp-4]
	ld	[%fp-4], %o1
	sethi	%hi(.LC1), %g1
	or	%g1, %lo(.LC1), %o0
	call	printf, 0
	 nop
	mov	0, %g1
	mov	%g1, %i0
	restore
	jmp	%o7+8
	 nop
	.size	main, .-main
	.align 4
	.global add1
	.type	add1, #function
	.proc	04
add1:
	save	%sp, -96, %sp
	st	%i0, [%fp+68]
	ld	[%fp+68], %g1
	add	%g1, 1, %g1
	add %g1, %i1, %g1
	mov	%g1, %i0
	restore
	jmp	%o7+8
	 nop
	.size	add1, .-add1
	.ident	"GCC: (crosstool-NG 1.21.0) 5.1.0"
	.section	.note.GNU-stack,"",@progbits
