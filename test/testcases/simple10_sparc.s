	.file	"simple10.c"
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
	save	%sp, -128, %sp
	add	%fp, -8, %g1
	mov	%g1, %o1
	sethi	%hi(.LC0), %g1
	or	%g1, %lo(.LC0), %o0
	call	__isoc99_scanf, 0
	 nop
	add	%fp, -12, %g1
	mov	%g1, %o1
	sethi	%hi(.LC0), %g1
	or	%g1, %lo(.LC0), %o0
	call	__isoc99_scanf, 0
	 nop
	ld	[%fp-8], %g2
	ld	[%fp-12], %g3
	mov	8, %g1
	st	%g1, [%sp+104]
	mov	7, %g1
	st	%g1, [%sp+100]
	mov	6, %g1
	st	%g1, [%sp+96]
	mov	5, %g1
	st	%g1, [%sp+92]
	mov	4, %o5
	mov	3, %o4
	mov	2, %o3
	mov	1, %o2
	mov	%g3, %o1
	mov	%g2, %o0
	call	add10, 0
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
	.global add10
	.type	add10, #function
	.proc	04
add10:
	save	%sp, -96, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	st	%i2, [%fp+76]
	st	%i3, [%fp+80]
	st	%i4, [%fp+84]
	st	%i5, [%fp+88]
	ld	[%fp+76], %g2
	ld	[%fp+80], %g1
	add	%g2, %g1, %g2
	ld	[%fp+84], %g1
	add	%g2, %g1, %g2
	ld	[%fp+88], %g1
	add	%g2, %g1, %g2
	ld	[%fp+92], %g1
	add	%g2, %g1, %g2
	ld	[%fp+96], %g1
	add	%g2, %g1, %g2
	ld	[%fp+100], %g1
	add	%g2, %g1, %g2
	ld	[%fp+104], %g1
	add	%g2, %g1, %g2
	ld	[%fp+72], %g1
	add	%g2, %g1, %g2
	ld	[%fp+68], %g1
	add	%g2, %g1, %g1
	mov	%g1, %i0
	restore
	jmp	%o7+8
	 nop
	.size	add10, .-add10
	.ident	"GCC: (crosstool-NG 1.21.0) 5.1.0"
	.section	.note.GNU-stack,"",@progbits
