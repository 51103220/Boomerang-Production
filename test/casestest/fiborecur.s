	.file	"fiborecur.c"
	.section	".rodata"
	.align 8
.LC0:
	.asciz	"%d"
	.align 8
.LC1:
	.asciz	"Fibonacci series"
	.align 8
.LC2:
	.asciz	"%d\n"
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	04
main:
	save	%sp, -112, %sp
	st	%g0, [%fp-4]
	add	%fp, -12, %g1
	mov	%g1, %o1
	sethi	%hi(.LC0), %g1
	or	%g1, %lo(.LC0), %o0
	call	__isoc99_scanf, 0
	 nop
	sethi	%hi(.LC1), %g1
	or	%g1, %lo(.LC1), %o0
	call	puts, 0
	 nop
	mov	1, %g1
	st	%g1, [%fp-8]
	b	.L2
	 nop
.L3:
	ld	[%fp-4], %o0
	call	Fibonacci, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o1
	sethi	%hi(.LC2), %g1
	or	%g1, %lo(.LC2), %o0
	call	printf, 0
	 nop
	ld	[%fp-4], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-4]
	ld	[%fp-8], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-8]
.L2:
	ld	[%fp-12], %g1
	ld	[%fp-8], %g2
	cmp	%g2, %g1
	ble	.L3
	 nop
	mov	0, %g1
	mov	%g1, %i0
	restore
	jmp	%o7+8
	 nop
	.size	main, .-main
	.align 4
	.global Fibonacci
	.type	Fibonacci, #function
	.proc	04
Fibonacci:
	save	%sp, -96, %sp
	st	%i0, [%fp+68]
	ld	[%fp+68], %g1
	cmp	%g1, 0
	bne	.L6
	 nop
	mov	0, %g1
	b	.L7
	 nop
.L6:
	ld	[%fp+68], %g1
	cmp	%g1, 1
	bne	.L8
	 nop
	mov	1, %g1
	b	.L7
	 nop
.L8:
	ld	[%fp+68], %g1
	add	%g1, -1, %g1
	mov	%g1, %o0
	call	Fibonacci, 0
	 nop
	mov	%o0, %i5
	ld	[%fp+68], %g1
	add	%g1, -2, %g1
	mov	%g1, %o0
	call	Fibonacci, 0
	 nop
	mov	%o0, %g1
	add	%i5, %g1, %g1
.L7:
	mov	%g1, %i0
	restore
	jmp	%o7+8
	 nop
	.size	Fibonacci, .-Fibonacci
	.ident	"GCC: (crosstool-NG 1.21.0) 5.1.0"
	.section	.note.GNU-stack,"",@progbits
