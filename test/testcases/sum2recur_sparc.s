	.file	"sum2recur.c"
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
	mov	10, %o1
	mov	%g1, %o0
	call	sum2recur, 0
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
	.global sum2recur
	.type	sum2recur, #function
	.proc	04
sum2recur:
	save	%sp, -96, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %g1
	cmp	%g1, 0
	bge	.L4
	 nop
	ld	[%fp+72], %g1
	cmp	%g1, 0
	bge	.L4
	 nop
	mov	1, %g1
	b	.L5
	 nop
.L4:
	ld	[%fp+68], %g1
	add	%g1, -1, %g2
	ld	[%fp+72], %g1
	add	%g1, -2, %g1
	mov	%g1, %o1
	mov	%g2, %o0
	call	sum2recur, 0
	 nop
	mov	%o0, %g1
	add	%g1, 3, %g1
.L5:
	mov	%g1, %i0
	restore
	jmp	%o7+8
	 nop
	.size	sum2recur, .-sum2recur
	.ident	"GCC: (crosstool-NG 1.21.0) 5.1.0"
	.section	.note.GNU-stack,"",@progbits
