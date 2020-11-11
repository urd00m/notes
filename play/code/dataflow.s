	.file	"dataflow.c"
	.text
.globl get_cycle_count
	.type	get_cycle_count, @function
get_cycle_count:
.LFB11:
	.cfi_startproc
#APP
# 13 "dataflow.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	leaq	-8(%rsp), %rcx
	movl	%eax, (%rcx)
	movl	%edx, 4(%rcx)
	movq	-8(%rsp), %rax
	ret
	.cfi_endproc
.LFE11:
	.size	get_cycle_count, .-get_cycle_count
.globl op_single
	.type	op_single, @function
op_single:
.LFB13:
	.cfi_startproc
	movl	%edi, %eax
	notl	%eax
	ret
	.cfi_endproc
.LFE13:
	.size	op_single, .-op_single
.globl op_regs
	.type	op_regs, @function
op_regs:
.LFB14:
	.cfi_startproc
	leal	(%rsi,%rdi), %eax
	ret
	.cfi_endproc
.LFE14:
	.size	op_regs, .-op_regs
.globl op_regs_long
	.type	op_regs_long, @function
op_regs_long:
.LFB15:
	.cfi_startproc
	leaq	(%rsi,%rdi), %rax
	ret
	.cfi_endproc
.LFE15:
	.size	op_regs_long, .-op_regs_long
.globl op_mem
	.type	op_mem, @function
op_mem:
.LFB16:
	.cfi_startproc
	movl	b(%rip), %eax
	addl	a(%rip), %eax
	movl	%eax, c(%rip)
	ret
	.cfi_endproc
.LFE16:
	.size	op_mem, .-op_mem
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"%d - %d = %d but %d > %d = %d\n"
	.text
.globl compare
	.type	compare, @function
compare:
.LFB18:
	.cfi_startproc
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	movl	$2147483647, 28(%rsp)
	movl	$-1, 24(%rsp)
	movl	28(%rsp), %edi
	movl	24(%rsp), %eax
	movl	24(%rsp), %r9d
	movl	28(%rsp), %r8d
	movl	28(%rsp), %ecx
	movl	24(%rsp), %r10d
	movl	24(%rsp), %edx
	movl	28(%rsp), %esi
	subl	%r10d, %ecx
	cmpl	%eax, %edi
	setg	%al
	movzbl	%al, %eax
	movl	%eax, (%rsp)
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	addq	$40, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE18:
	.size	compare, .-compare
	.section	.rodata.str1.8
	.align 8
.LC1:
	.string	"for loop and timing overhead took %llu cycles\n"
	.text
.globl op_for_loop
	.type	op_for_loop, @function
op_for_loop:
.LFB17:
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
	movq	%rdi, %rbp
	movl	%esi, %ebx
	movl	$0, %eax
	call	get_cycle_count
	movq	%rax, %r12
	testl	%ebx, %ebx
	jg	.L14
	movl	$1, %ebx
	jmp	.L15
.L14:
	subl	$1, %ebx
	leaq	4(,%rbx,4), %rdx
	movl	$0, %eax
	movl	$1, %ebx
.L16:
	addl	0(%rbp,%rax), %ebx
	addq	$4, %rax
	cmpq	%rdx, %rax
	jne	.L16
.L15:
	movl	$0, %eax
	call	get_cycle_count
	movq	%rax, %rsi
	subq	%r12, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	%ebx, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE17:
	.size	op_for_loop, .-op_for_loop
	.section	.rodata.str1.8
	.align 8
.LC2:
	.string	"timing overhead is at least %llu cycles\n"
	.text
.globl timing_overhead
	.type	timing_overhead, @function
timing_overhead:
.LFB12:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$0, %eax
	call	get_cycle_count
	movq	%rax, %rbx
	movl	$0, %eax
	call	get_cycle_count
	movq	%rax, %rsi
	subq	%rbx, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE12:
	.size	timing_overhead, .-timing_overhead
.globl main
	.type	main, @function
main:
.LFB19:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$0, %eax
	call	op_mem
	movl	$1024, %esi
	movl	$z, %edi
	call	op_for_loop
	movl	$0, %eax
	call	compare
	movl	$0, %eax
	call	timing_overhead
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE19:
	.size	main, .-main
	.comm	a,4,4
	.comm	b,4,4
	.comm	c,4,4
	.comm	z,4096,32
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-23)"
	.section	.note.GNU-stack,"",@progbits
