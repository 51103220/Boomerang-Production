	.file	"float123.c"
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
	save	%sp, -120, %sp
	add	%fp, -8, %g1
	mov	%g1, %o1
	sethi	%hi(.LC0), %g1
	or	%g1, %lo(.LC0), %o0
	call	__isoc99_scanf, 0
	 nop
	ld	[%fp-8], %f8
	st	%f8, [%fp-12]
	ld	[%fp-12], %o0
	call	add1, 0
	 nop
	st	%f0, [%fp-4]
	ld	[%fp-4], %f8
	fstod	%f8, %f8
	std	%f8, [%fp-24]
	ldd	[%fp-24], %g2
	mov	%g2, %o1
	mov	%g3, %o2
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
	.section	".rodata"
	.align 4
.LC2:
	.long	1065353216
	.section	".text"
	.align 4
	.global add1
	.type	add1, #function
	.proc	06
add1:
	save	%sp, -104, %sp
	st	%i0, [%fp+68]
	ld	[%fp+68], %f9
	sethi	%hi(.LC2), %g1
	or	%g1, %lo(.LC2), %g1
	ld	[%g1], %f8
	fadds	%f9, %f8, %f10
	ld	[%fp+68], %f9
	sethi	%hi(.LC2), %g1
	or	%g1, %lo(.LC2), %g1
	ld	[%g1], %f8
	fsubs	%f9, %f8, %f8
	st	%f8, [%fp-4]
	ld	[%fp-4], %o1
	st	%f10, [%fp-4]
	ld	[%fp-4], %o0
	call	add2, 0
	 nop
	fmovs	%f0, %f8
	fmovs	%f8, %f0
	restore
	jmp	%o7+8
	 nop
	.size	add1, .-add1
	.section	".rodata"
	.align 4
.LC3:
	.long	1065353216
	.section	".text"
	.align 4
	.global add2
	.type	add2, #function
	.proc	06
add2:
	save	%sp, -104, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %f9
	sethi	%hi(.LC3), %g1
	or	%g1, %lo(.LC3), %g1
	ld	[%g1], %f8
	fadds	%f9, %f8, %f10
	ld	[%fp+68], %f9
	sethi	%hi(.LC3), %g1
	or	%g1, %lo(.LC3), %g1
	ld	[%g1], %f8
	fsubs	%f9, %f8, %f8
	st	%f8, [%fp-4]
	ld	[%fp-4], %o2
	ld	[%fp+72], %o1
	st	%f10, [%fp-4]
	ld	[%fp-4], %o0
	call	add3, 0
	 nop
	fmovs	%f0, %f8
	fmovs	%f8, %f0
	restore
	jmp	%o7+8
	 nop
	.size	add2, .-add2
	.align 4
	.global add3
	.type	add3, #function
	.proc	06
add3:
	save	%sp, -96, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	st	%i2, [%fp+76]
	ld	[%fp+68], %f9
	ld	[%fp+72], %f8
	fadds	%f9, %f8, %f9
	ld	[%fp+76], %f8
	fadds	%f9, %f8, %f8
	fmovs	%f8, %f0
	restore
	jmp	%o7+8
	 nop
	.size	add3, .-add3
	.ident	"GCC: (crosstool-NG 1.21.0) 5.1.0"
	.section	.note.GNU-stack,"",@progbits
