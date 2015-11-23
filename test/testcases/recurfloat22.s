	.file	"recurfloat22.c"
	.section	".rodata"
	.align 8
.LC0:
	.asciz	"%d"
	.align 8
.LC1:
	.asciz	"Sum = %ld\n"
	.align 4
.LC2:
	.long	0
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	06
main:
	save	%sp, -120, %sp
	add	%fp, -8, %g1
	mov	%g1, %o1
	sethi	%hi(.LC0), %g1
	or	%g1, %lo(.LC0), %o0
	call	__isoc99_scanf, 0
	 nop
	ld	[%fp-8], %f10
	ld	[%fp-8], %f9
	ld	[%fp-8], %f8
	fmuls	%f9, %f8, %f8
	st	%f8, [%fp-12]
	ld	[%fp-12], %o1
	st	%f10, [%fp-12]
	ld	[%fp-12], %o0
	call	add2, 0
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
	sethi	%hi(.LC2), %g1
	or	%g1, %lo(.LC2), %g1
	ld	[%g1], %f8
	fmovs	%f8, %f0
	restore
	jmp	%o7+8
	 nop
	.size	main, .-main
	.section	".rodata"
	.align 4
.LC3:
	.long	1065353216
	.align 4
.LC4:
	.long	1073741824
	.section	".text"
	.align 4
	.global add1
	.type	add1, #function
	.proc	06
add1:
	save	%sp, -104, %sp
	st	%i0, [%fp+68]
	ld	[%fp+68], %f9
	sethi	%hi(.LC3), %g1
	or	%g1, %lo(.LC3), %g1
	ld	[%g1], %f8
	fcmpes	%f9, %f8
	nop
	fbuge	.L8
	 nop
	sethi	%hi(.LC3), %g1
	or	%g1, %lo(.LC3), %g1
	ld	[%g1], %f8
	b	.L6
	 nop
.L8:
	ld	[%fp+68], %f9
	sethi	%hi(.LC3), %g1
	or	%g1, %lo(.LC3), %g1
	ld	[%g1], %f8
	fsubs	%f9, %f8, %f10
	ld	[%fp+68], %f9
	sethi	%hi(.LC4), %g1
	or	%g1, %lo(.LC4), %g1
	ld	[%g1], %f8
	fadds	%f9, %f8, %f8
	st	%f8, [%fp-4]
	ld	[%fp-4], %o1
	st	%f10, [%fp-4]
	ld	[%fp-4], %o0
	call	add2, 0
	 nop
	fmovs	%f0, %f9
	sethi	%hi(.LC3), %g1
	or	%g1, %lo(.LC3), %g1
	ld	[%g1], %f8
	fadds	%f9, %f8, %f8
.L6:
	fmovs	%f8, %f0
	restore
	jmp	%o7+8
	 nop
	.size	add1, .-add1
	.section	".rodata"
	.align 4
.LC5:
	.long	1065353216
	.align 4
.LC6:
	.long	1073741824
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
	sethi	%hi(.LC5), %g1
	or	%g1, %lo(.LC5), %g1
	ld	[%g1], %f8
	fcmpes	%f9, %f8
	nop
	fbuge	.L14
	 nop
	sethi	%hi(.LC5), %g1
	or	%g1, %lo(.LC5), %g1
	ld	[%g1], %f8
	b	.L12
	 nop
.L14:
	ld	[%fp+72], %f9
	sethi	%hi(.LC6), %g1
	or	%g1, %lo(.LC6), %g1
	ld	[%g1], %f8
	fadds	%f9, %f8, %f8
	st	%f8, [%fp-4]
	ld	[%fp+68], %f9
	sethi	%hi(.LC5), %g1
	or	%g1, %lo(.LC5), %g1
	ld	[%g1], %f8
	fsubs	%f9, %f8, %f8
	st	%f8, [%fp-8]
	ld	[%fp-8], %o0
	call	add1, 0
	 nop
	fmovs	%f0, %f8
	ld	[%fp-4], %f9
	fadds	%f9, %f8, %f8
.L12:
	fmovs	%f8, %f0
	restore
	jmp	%o7+8
	 nop
	.size	add2, .-add2
	.ident	"GCC: (crosstool-NG 1.21.0) 5.1.0"
	.section	.note.GNU-stack,"",@progbits
