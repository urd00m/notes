	.file	"infinite_recursion.c"
	.text
.globl fib
	.type	fib, @function
fib:
.LFB0:
	.cfi_startproc
	movq	%rbx, -16(%rsp)
	movq	%rbp, -8(%rsp)
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -16
	.cfi_offset 3, -24
	movq	%rdi, %rbx
	cmpq	$1, %rdi
	ja	.L2
	movl	$1, %eax
	jmp	.L3
.L2:
	leaq	-1(%rdi), %rdi
	call	fib
	movq	%rax, %rbp
	leaq	-2(%rbx), %rdi
	call	fib
	addq	%rbp, %rax
.L3:
	movq	8(%rsp), %rbx
	movq	16(%rsp), %rbp
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	fib, .-fib
.globl main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movabsq	$999999999999, %rdi
	call	fib
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-23)"
	.section	.note.GNU-stack,"",@progbits
