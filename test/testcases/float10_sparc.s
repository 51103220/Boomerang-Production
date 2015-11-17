	.file	"float10.c"
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
	save	%sp, -176, %sp
	add	%fp, -44, %g1
	mov	%g1, %o1
	sethi	%hi(.LC0), %g1
	or	%g1, %lo(.LC0), %o0
	call	__isoc99_scanf, 0
	 nop
	ld	[%fp-44], %f9
	ld	[%fp-36], %f8
	st	%f8, [%sp+104]
	ld	[%fp-32], %f8
	st	%f8, [%sp+100]
	ld	[%fp-28], %g1
	st	%g1, [%sp+96]
	ld	[%fp-24], %g1
	st	%g1, [%sp+92]
	ld	[%fp-20], %o5
	ld	[%fp-16], %o4
	ld	[%fp-12], %o3
	ld	[%fp-8], %o2
	ld	[%fp-4], %o1
	st	%f9, [%fp-52]
	ld	[%fp-52], %o0
	call	add10, 0
	 nop
	st	%f0, [%fp-40]
	ld	[%fp-40], %f8
	fstod	%f8, %f8
	std	%f8, [%fp-64]
	ldd	[%fp-64], %g2
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
	.align 4
	.global add10
	.type	add10, #function
	.proc	06
add10:
	save	%sp, -104, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	st	%i2, [%fp+76]
	st	%i3, [%fp+80]
	st	%i4, [%fp+84]
	st	%i5, [%fp+88]
	ld	[%fp+68], %f9
	ld	[%fp+72], %f8
	fadds	%f9, %f8, %f9
	ld	[%fp+76], %g1
	st	%g1, [%fp-4]
	ld	[%fp-4], %f10
	fitos	%f10, %f8
	fadds	%f9, %f8, %f9
	ld	[%fp+80], %g1
	st	%g1, [%fp-4]
	ld	[%fp-4], %f10
	fitos	%f10, %f8
	fadds	%f9, %f8, %f9
	ld	[%fp+84], %f8
	fadds	%f9, %f8, %f9
	ld	[%fp+88], %f8
	fadds	%f9, %f8, %f9
	ld	[%fp+92], %g1
	st	%g1, [%fp-4]
	ld	[%fp-4], %f10
	fitos	%f10, %f8
	fadds	%f9, %f8, %f9
	ld	[%fp+96], %g1
	st	%g1, [%fp-4]
	ld	[%fp-4], %f10
	fitos	%f10, %f8
	fadds	%f9, %f8, %f9
	ld	[%fp+100], %f8
	fadds	%f9, %f8, %f9
	ld	[%fp+104], %f8
	fadds	%f9, %f8, %f8
	fmovs	%f8, %f0
	restore
	jmp	%o7+8
	 nop
	.size	add10, .-add10
	.ident	"GCC: (crosstool-NG 1.21.0) 5.1.0"
	.section	.note.GNU-stack,"",@progbits
