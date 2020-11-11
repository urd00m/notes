	.file	"mat.c"
	.text
.globl alloc_mat
	.type	alloc_mat, @function
alloc_mat:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	imulq	-24(%rbp), %rax
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	imulq	-24(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	movq	-8(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	alloc_mat, .-alloc_mat
.globl fill_mat
	.type	fill_mat, @function
fill_mat:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	$0, -24(%rbp)
	jmp	.L4
	.cfi_offset 3, -24
.L5:
	movq	-24(%rbp), %rax
	salq	$3, %rax
	movq	%rax, %rbx
	addq	-40(%rbp), %rbx
	call	drand48
	movsd	%xmm0, (%rbx)
	addq	$1, -24(%rbp)
.L4:
	movq	-48(%rbp), %rax
	imulq	-48(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jg	.L5
	addq	$40, %rsp
	popq	%rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	fill_mat, .-fill_mat
.globl mult_mat
	.type	mult_mat, @function
mult_mat:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	%rcx, -64(%rbp)
	movq	$0, -32(%rbp)
	jmp	.L8
.L13:
	movq	$0, -24(%rbp)
	jmp	.L9
.L12:
	movl	$0, %eax
	movq	%rax, -8(%rbp)
	movq	$0, -16(%rbp)
	jmp	.L10
.L11:
	movq	-32(%rbp), %rax
	imulq	-64(%rbp), %rax
	addq	-16(%rbp), %rax
	salq	$3, %rax
	addq	-40(%rbp), %rax
	movsd	(%rax), %xmm1
	movq	-16(%rbp), %rax
	imulq	-64(%rbp), %rax
	addq	-24(%rbp), %rax
	salq	$3, %rax
	addq	-48(%rbp), %rax
	movsd	(%rax), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	-8(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	addq	$1, -16(%rbp)
.L10:
	movq	-16(%rbp), %rax
	cmpq	-64(%rbp), %rax
	jl	.L11
	movq	-32(%rbp), %rax
	imulq	-64(%rbp), %rax
	addq	-24(%rbp), %rax
	salq	$3, %rax
	addq	-56(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	addq	$1, -24(%rbp)
.L9:
	movq	-24(%rbp), %rax
	cmpq	-64(%rbp), %rax
	jl	.L12
	addq	$1, -32(%rbp)
.L8:
	movq	-32(%rbp), %rax
	cmpq	-64(%rbp), %rax
	jl	.L13
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	mult_mat, .-mult_mat
.globl sum_mat
	.type	sum_mat, @function
sum_mat:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	$0, -32(%rbp)
	jmp	.L16
.L19:
	movq	$0, -24(%rbp)
	jmp	.L17
.L18:
	movq	-32(%rbp), %rax
	imulq	-48(%rbp), %rax
	addq	-24(%rbp), %rax
	salq	$3, %rax
	addq	-40(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	-8(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	addq	$1, -24(%rbp)
.L17:
	movq	-24(%rbp), %rax
	cmpq	-48(%rbp), %rax
	jl	.L18
	addq	$1, -32(%rbp)
.L16:
	movq	-32(%rbp), %rax
	cmpq	-48(%rbp), %rax
	jl	.L19
	movq	-8(%rbp), %rax
	movq	%rax, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	sum_mat, .-sum_mat
	.section	.rodata
.LC1:
	.string	"mat s|m size"
	.align 8
.LC2:
	.string	"Doing op %c on matrices of size %ld by %ld\n"
	.text
.globl main
	.type	main, @function
main:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	cmpl	$3, -68(%rbp)
	je	.L22
	.cfi_offset 3, -24
	movl	$.LC1, %edi
	call	puts
	movl	$-1, %eax
	jmp	.L23
.L22:
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	movb	%al, -49(%rbp)
	cmpb	$115, -49(%rbp)
	je	.L24
	cmpb	$109, -49(%rbp)
	je	.L24
	movl	$.LC1, %edi
	call	puts
	movl	$-1, %eax
	jmp	.L23
.L24:
	movq	-80(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	cltq
	movq	%rax, -64(%rbp)
	movsbl	-49(%rbp), %ebx
	movl	$.LC2, %eax
	movq	-64(%rbp), %rcx
	movq	-64(%rbp), %rdx
	movl	%ebx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	cmpb	$115, -49(%rbp)
	jne	.L25
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	alloc_mat
	movq	%rax, -48(%rbp)
	movq	-64(%rbp), %rdx
	movq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fill_mat
	movq	-64(%rbp), %rdx
	movq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	sum_mat
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movl	$0, %eax
	jmp	.L23
.L25:
	cmpb	$109, -49(%rbp)
	jne	.L26
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	alloc_mat
	movq	%rax, -40(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	alloc_mat
	movq	%rax, -32(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	alloc_mat
	movq	%rax, -24(%rbp)
	movq	-64(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fill_mat
	movq	-64(%rbp), %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fill_mat
	movq	-64(%rbp), %rcx
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rbx
	movq	-40(%rbp), %rax
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	mult_mat
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movl	$0, %eax
	jmp	.L23
.L26:
	jmp	.L21
.L23:
.L21:
	addq	$72, %rsp
	popq	%rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-23)"
	.section	.note.GNU-stack,"",@progbits
