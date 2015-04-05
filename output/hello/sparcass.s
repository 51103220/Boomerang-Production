	.file	"hello.c"
	.section	".rodata"
	.align 8
.LC0:
	.asciz	"Hello, world!"
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	04
main:
	save	%sp, -96, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	st	%i2, [%fp+76]
	sethi	%hi(.LC0), %g1
	or	%g1, %lo(.LC0), %o0
	call	puts, 0
	 nop
	mov	0, %g1
	mov	%g1, %i0
	restore
	jmp	%o7+8
	 nop
	.size	main, .-main
	.ident	"GCC: (crosstool-NG 1.20.0) 4.9.1"
	.section	.note.GNU-stack,"",@progbits
