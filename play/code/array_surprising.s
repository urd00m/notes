	.file	"array_surprising.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"a[3] = %d\n"
.LC1:
	.string	"3[a] = %d\n"
.LC2:
	.string	"a[9] = %d\n"
.LC3:
	.string	"a[-2] = %d\n"
.LC4:
	.string	"0x40100[0] = %d\n"
	.text
.globl main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	movl	$0, (%rsp)
	movl	$1, 4(%rsp)
	movl	$2, 8(%rsp)
	movl	$3, 12(%rsp)
	movl	$4, 16(%rsp)
	movl	$5, 20(%rsp)
	movl	$6, 24(%rsp)
	movl	$7, 28(%rsp)
	movl	$3, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$3, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	36(%rsp), %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	-8(%rsp), %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	262400, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	addq	$40, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-23)"
	.section	.note.GNU-stack,"",@progbits
