	.file	"simple11.c"
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
	mov 10, %i1
	st %i1, [%sp + 96]
	add %i1, 8, %i1
	ld	[%fp-8], %g1
	ld [%fp - 4],%g2
	add %g3, %g1, %g2
	st %g3 ,[ %fp - 4]
	ld [%fp - 4], %i1
	mov 8, %i0
	call	add1, 0
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
	.global add1
	.type	add1, #function
	.proc	04
add1:
	save	%sp, -96, %sp	
	mov %o1, %i2
	ld [%fp + 96], %g3
	st %g3, [%sp +  100]
	call	add2, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %i0
	restore
	jmp	%o7+8
	 nop
	.size	add1, .-add1
	.align 4
	.global add2
	.type	add2, #function
	.proc	04
add2:
	save	%sp, -96, %sp
	add	%g1, 2, %g1
	add %g2, %g1, %g2
	add %g2, %o2, %g2
	ld [%fp + 100], %g1
	add %g2, %g1, %g2 
	mov	%g1, %i0
	mov %g2, %i0
	restore
	jmp	%o7+8
	 nop
	.size	add2, .-add2
	.ident	"GCC: (crosstool-NG 1.21.0) 5.1.0"
	.section	.note.GNU-stack,"",@progbits
