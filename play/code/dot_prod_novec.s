	.file	"dot_prod.c"
	.text
.globl init
	.type	init, @function
init:
.LFB18:
	.cfi_startproc
	testq	%rsi, %rsi
	jle	.L4
	movl	$0, %eax
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
.globl dot_product
	.type	dot_product, @function
dot_product:
.LFB19:
	.cfi_startproc
	testq	%rdx, %rdx
	jg	.L7
	xorpd	%xmm0, %xmm0
	ret
.L7:
	movl	$0, %eax
	xorpd	%xmm0, %xmm0
.L9:
	movsd	(%rdi,%rax,8), %xmm1
	mulsd	(%rsi,%rax,8), %xmm1
	addsd	%xmm1, %xmm0
	addq	$1, %rax
	cmpq	%rdx, %rax
	jne	.L9
	rep; ret
	.cfi_endproc
.LFE19:
	.size	dot_product, .-dot_product
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
	leaq	-8(%rsp), %rcx
	movl	%eax, (%rcx)
	movl	%edx, 4(%rcx)
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
.globl main
	.type	main, @function
main:
.LFB20:
	.cfi_startproc
	movq	%rbx, -32(%rsp)
	movq	%rbp, -24(%rsp)
	movq	%r12, -16(%rsp)
	movq	%r13, -8(%rsp)
	subq	$56, %rsp
	.cfi_def_cfa_offset 64
	.cfi_offset 13, -16
	.cfi_offset 12, -24
	.cfi_offset 6, -32
	.cfi_offset 3, -40
	cmpl	$2, %edi
	je	.L15
	movl	$.LC1, %edi
	call	puts
	movl	$-1, %eax
	jmp	.L16
.L15:
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol
	movq	%rax, %rbx
	leaq	0(,%rax,8), %rbp
	movq	%rbp, %rdi
	call	malloc
	movq	%rax, %r12
	movq	%rbp, %rdi
	call	malloc
	movq	%rax, %rbp
	movq	%rbx, %rsi
	movq	%r12, %rdi
	call	init
	movq	%rbx, %rsi
	movq	%rbp, %rdi
	call	init
	movl	$0, %eax
	call	get_cycle_count
	movq	%rax, %r13
	movq	%rbx, %rdx
	movq	%rbp, %rsi
	movq	%r12, %rdi
	call	dot_product
	movsd	%xmm0, 8(%rsp)
	movl	$0, %eax
	call	get_cycle_count
	movq	%rax, %rdx
	subq	%r13, %rdx
	movq	%rbx, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
.L16:
	movq	24(%rsp), %rbx
	movq	32(%rsp), %rbp
	movq	40(%rsp), %r12
	movq	48(%rsp), %r13
	addq	$56, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE20:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-23)"
	.section	.note.GNU-stack,"",@progbits
