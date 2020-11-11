	.file	"datalayout.c"
	.text
.globl set_i
	.type	set_i, @function
set_i:
.LFB33:
	.cfi_startproc
	movl	%esi, 12(%rdi)
	ret
	.cfi_endproc
.LFE33:
	.size	set_i, .-set_i
.globl get_ap
	.type	get_ap, @function
get_ap:
.LFB34:
	.cfi_startproc
	movslq	%esi, %rsi
	leaq	(%rdi,%rsi,4), %rax
	ret
	.cfi_endproc
.LFE34:
	.size	get_ap, .-get_ap
.globl check_val
	.type	check_val, @function
check_val:
.LFB35:
	.cfi_startproc
	movl	$0, %eax
	movl	$1, %ecx
	jmp	.L12
.L8:
	movslq	12(%rdi), %rdx
	cmpl	%esi, (%rdi,%rdx,4)
	jne	.L7
	movl	%ecx, %eax
	jmp	.L12
.L7:
	movq	16(%rdi), %rdi
.L12:
	testl	%eax, %eax
	jne	.L11
	testq	%rdi, %rdi
	jne	.L8
.L11:
	.p2align 4,,2
	rep; ret
	.cfi_endproc
.LFE35:
	.size	check_val, .-check_val
.globl set_val
	.type	set_val, @function
set_val:
.LFB36:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L16
.L17:
	movslq	12(%rdi), %rax
	movl	%esi, (%rdi,%rax,4)
	movq	16(%rdi), %rdi
	testq	%rdi, %rdi
	jne	.L17
.L16:
	rep; ret
	.cfi_endproc
.LFE36:
	.size	set_val, .-set_val
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"A at %p, A[5] at %p, 5[A] at %p\n"
	.text
.globl array_surprise
	.type	array_surprise, @function
array_surprise:
.LFB32:
	.cfi_startproc
	subq	$264, %rsp
	.cfi_def_cfa_offset 272
	movq	%rsp, %rsi
	leaq	20(%rsp), %rdx
	movq	%rdx, %rcx
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	addq	$264, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE32:
	.size	array_surprise, .-array_surprise
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"pins: 0x%8x\n"
.LC2:
	.string	"ERROR, they're not all equal"
	.text
.globl main
	.type	main, @function
main:
.LFB37:
	.cfi_startproc
	subq	$72, %rsp
	.cfi_def_cfa_offset 80
	movl	$0, 48(%rsp)
	movl	$0, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	orb	$64, 48(%rsp)
	movl	48(%rsp), %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, 48(%rsp)
	movl	$0, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$1, (%rsp)
	movl	$2, 4(%rsp)
	movl	$3, 8(%rsp)
	movl	$4, 12(%rsp)
	movl	$5, 16(%rsp)
	movl	$6, 20(%rsp)
	movl	$7, 24(%rsp)
	movl	$8, 28(%rsp)
	movl	$9, 32(%rsp)
	movl	$6, %eax
	cmpl	%eax, %eax
	je	.L22
	movl	$.LC2, %edi
	call	puts
.L22:
	movl	$0, %eax
	call	array_surprise
	addq	$72, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE37:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-23)"
	.section	.note.GNU-stack,"",@progbits
