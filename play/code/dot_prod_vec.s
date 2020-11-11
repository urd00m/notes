	.file	"dot_prod.c"
	.text
	.p2align 4,,15
.globl init
	.type	init, @function
init:
.LFB18:
	.cfi_startproc
	testq	%rsi, %rsi
	jle	.L4
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L3:
	cvtsi2sdq	%rax, %xmm0
	movsd	%xmm0, (%rdi,%rax,8)
	addq	$1, %rax
	cmpq	%rsi, %rax
	jne	.L3
.L4:
	rep; ret
	.cfi_endproc
.LFE18:
	.size	init, .-init
	.p2align 4,,15
.globl dot_product
	.type	dot_product, @function
dot_product:
.LFB19:
	.cfi_startproc
	testq	%rdx, %rdx
	jle	.L13
	xorpd	%xmm0, %xmm0
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L10:
	movsd	(%rdi,%rax,8), %xmm1
	mulsd	(%rsi,%rax,8), %xmm1
	addq	$1, %rax
	cmpq	%rdx, %rax
	addsd	%xmm1, %xmm0
	jne	.L10
	rep; ret
.L13:
	xorpd	%xmm0, %xmm0
	ret
	.cfi_endproc
.LFE19:
	.size	dot_product, .-dot_product
	.p2align 4,,15
.globl get_cycle_count
	.type	get_cycle_count, @function
get_cycle_count:
.LFB21:
	.cfi_startproc
#APP
# 64 "dot_prod.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -8(%rsp)
	movl	%edx, -4(%rsp)
	movq	-8(%rsp), %rax
	ret
	.cfi_endproc
.LFE21:
	.size	get_cycle_count, .-get_cycle_count
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"usage: dot_prod N"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Dot product of %lu element vectors took %lu cycles\n"
	.text
	.p2align 4,,15
.globl main
	.type	main, @function
main:
.LFB20:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$16, %rsp
	.cfi_def_cfa_offset 48
	cmpl	$2, %edi
	jne	.L29
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	leaq	0(,%rax,8), %r12
	movq	%rax, %rbx
	movq	%r12, %rdi
	call	malloc
	movq	%r12, %rdi
	movq	%rax, %rbp
	call	malloc
	testq	%rbx, %rbx
	movq	%rax, %rcx
	jle	.L19
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L20:
	cvtsi2sdq	%rax, %xmm0
	movsd	%xmm0, 0(%rbp,%rax,8)
	addq	$1, %rax
	cmpq	%rbx, %rax
	jne	.L20
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L21:
	cvtsi2sdq	%rax, %xmm0
	movsd	%xmm0, (%rcx,%rax,8)
	addq	$1, %rax
	cmpq	%rbx, %rax
	jne	.L21
.L19:
#APP
# 64 "dot_prod.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	testq	%rbx, %rbx
	movl	%eax, (%rsp)
	movl	%edx, 4(%rsp)
	movq	(%rsp), %rsi
	jle	.L30
	xorpd	%xmm1, %xmm1
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L24:
	movsd	0(%rbp,%rax,8), %xmm0
	mulsd	(%rcx,%rax,8), %xmm0
	addq	$1, %rax
	cmpq	%rbx, %rax
	addsd	%xmm0, %xmm1
	jne	.L24
.L23:
	movsd	%xmm1, 8(%rsp)
#APP
# 64 "dot_prod.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%edx, 4(%rsp)
	movl	$.LC2, %edi
	movq	(%rsp), %rdx
	movl	%eax, (%rsp)
	xorl	%eax, %eax
	subq	%rsi, %rdx
	movq	%rbx, %rsi
	call	printf
	xorl	%eax, %eax
.L18:
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L29:
	.cfi_restore_state
	movl	$.LC1, %edi
	call	puts
	movl	$-1, %eax
	jmp	.L18
.L30:
	xorpd	%xmm1, %xmm1
	jmp	.L23
	.cfi_endproc
.LFE20:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-23)"
	.section	.note.GNU-stack,"",@progbits
