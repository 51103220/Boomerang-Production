	.file	"float2.c"
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
	add	%fp, -12, %g1
	mov	%g1, %o1
	sethi	%hi(.LC0), %g1
	or	%g1, %lo(.LC0), %o0
	call	__isoc99_scanf, 0
	 nop
	ld	[%fp-12], %f8
	ld	[%fp-4], %o1
	st	%f8, [%fp-20]
	ld	[%fp-20], %o0
	call	add2, 0
	 nop
	st	%f0, [%fp-8]
	ld	[%fp-8], %f8
	fstod	%f8, %f8
	std	%f8, [%fp-32]
	ldd	[%fp-32], %g2
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
	.global add2
	.type	add2, #function
	.proc	06
add2:
	save	%sp, -96, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %f9
	ld	[%fp+72], %f8
	fadds	%f9, %f8, %f8
	fmovs	%f8, %f0
	restore
	jmp	%o7+8
	 nop
	.size	add2, .-add2
	.ident	"GCC: (crosstool-NG 1.21.0) 5.1.0"
	.section	.note.GNU-stack,"",@progbits
