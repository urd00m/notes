	.file	"array.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"sum = %d\n"
	.text
.globl main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$array, %edx
	movl	$0, %eax
.L2:
	movl	%eax, (%rdx)
	addl	$1, %eax
	addq	$4, %rdx
	cmpl	$10, %eax
	jne	.L2
	movl	$0, %eax
	movl	$0, %esi
	movl	$array, %edx
.L3:
	addl	(%rdx,%rax), %esi
	addq	$4, %rax
	cmpq	$40, %rax
	jne	.L3
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.comm	array,40,32
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-23)"
	.section	.note.GNU-stack,"",@progbits
