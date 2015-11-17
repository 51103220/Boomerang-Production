	.file	"sumarray.c"
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
	save	%sp, -512, %sp
	add	%fp, -12, %g1
	mov	%g1, %o1
	sethi	%hi(.LC0), %g1
	or	%g1, %lo(.LC0), %o0
	call	__isoc99_scanf, 0
	 nop
	st	%g0, [%fp-4]
	b	.L2
	 nop
.L3:
	add	%fp, -412, %g2
	ld	[%fp-4], %g1
	sll	%g1, 2, %g1
	add	%g2, %g1, %g1
	mov	%g1, %o1
	sethi	%hi(.LC0), %g1
	or	%g1, %lo(.LC0), %o0
	call	__isoc99_scanf, 0
	 nop
	ld	[%fp-4], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-4]
.L2:
	ld	[%fp-12], %g1
	ld	[%fp-4], %g2
	cmp	%g2, %g1
	bl	.L3
	 nop
	ld	[%fp-12], %g2
	add	%fp, -412, %g1
	mov	%g2, %o1
	mov	%g1, %o0
	call	sumarray, 0
	 nop
	st	%o0, [%fp-8]
	ld	[%fp-8], %o1
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
	.global sumarray
	.type	sumarray, #function
	.proc	04
sumarray:
	save	%sp, -104, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	st	%g0, [%fp-4]
	b	.L6
	 nop
.L7:
	ld	[%fp-4], %g1
	sll	%g1, 2, %g1
	ld	[%fp+68], %g2
	add	%g2, %g1, %g1
	ld	[%g1], %g2
	sethi	%hi(sum.1947), %g1
	or	%g1, %lo(sum.1947), %g1
	ld	[%g1], %g1
	add	%g2, %g1, %g2
	sethi	%hi(sum.1947), %g1
	or	%g1, %lo(sum.1947), %g1
	st	%g2, [%g1]
	ld	[%fp-4], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-4]
.L6:
	ld	[%fp-4], %g2
	ld	[%fp+72], %g1
	cmp	%g2, %g1
	bl	.L7
	 nop
	sethi	%hi(sum.1947), %g1
	or	%g1, %lo(sum.1947), %g1
	ld	[%g1], %g1
	mov	%g1, %i0
	restore
	jmp	%o7+8
	 nop
	.size	sumarray, .-sumarray
	.local	sum.1947
	.common	sum.1947,4,4
	.ident	"GCC: (crosstool-NG 1.21.0) 5.1.0"
	.section	.note.GNU-stack,"",@progbits
