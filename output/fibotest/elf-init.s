	.file	"elf-init.c"
	.section	".rodata"
	.align 8
.LC0:
	.asciz	"Input number: "
	.align 8
.LC1:
	.asciz	"%d"
	.align 8
.LC2:
	.asciz	"fibonacci(%d) = %d\n"
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	04
main:
	save	%sp, -112, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	st	%i2, [%fp+76]
	sethi	%hi(.LC0), %g1
	or	%g1, %lo(.LC0), %o0
	call	printf, 0
	 nop
	add	%fp, -12, %g2
	sethi	%hi(.LC1), %g1
	or	%g1, %lo(.LC1), %o0
	mov	%g2, %o1
	call	scanf, 0
	 nop
	ld	[%fp-12], %g1
	mov	%g1, %o0
	ld	[%fp-4], %o1
	call	fib, 0
	 nop
	st	%o0, [%fp-8]
	ld	[%fp-12], %g2
	sethi	%hi(.LC2), %g1
	or	%g1, %lo(.LC2), %o0
	mov	%g2, %o1
	ld	[%fp-8], %o2
	call	printf, 0
	 nop
	mov	0, %g1
	mov	%g1, %i0
	restore
	jmp	%o7+8
	 nop
	.size	main, .-main
	.align 4
	.global fib
	.type	fib, #function
	.proc	04
fib:
	save	%sp, -120, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+72], %g1
	st	%g1, [%fp-8]
	ld	[%fp+68], %g1
	cmp	%g1, 1
	bg	.L4
	 nop
	ld	[%fp+68], %g1
	st	%g1, [%fp-12]
	ld	[%fp+68], %g1
	st	%g1, [%fp-4]
	b	.L5
	 nop
.L4:
	ld	[%fp+68], %g1
	add	%g1, -1, %g1
	mov	%g1, %o0
	ld	[%fp+72], %o1
	call	fib, 0
	 nop
	st	%o0, [%fp-16]
	ld	[%fp+68], %g1
	add	%g1, -2, %g1
	mov	%g1, %o0
	ld	[%fp-20], %o1
	call	fib, 0
	 nop
	st	%o0, [%fp-24]
	ld	[%fp-16], %g1
	st	%g1, [%fp-8]
	ld	[%fp-16], %g2
	ld	[%fp-24], %g1
	add	%g2, %g1, %g1
	st	%g1, [%fp-4]
.L5:
	ld	[%fp-4], %g1
	mov	%g1, %i0
	restore
	jmp	%o7+8
	 nop
	.size	fib, .-fib
	.ident	"GCC: (crosstool-NG 1.20.0) 4.9.1"
	.section	.note.GNU-stack,"",@progbits
