	.file	"recursion.c"
	.text
.globl fact
	.type	fact, @function
fact:
.LFB11:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	%edi, %ebx
	testl	%edi, %edi
	jne	.L2
	movl	$1, %eax
	jmp	.L3
.L2:
	leal	-1(%rbx), %edi
	call	fact
	imull	%ebx, %eax
.L3:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	fact, .-fact
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"fact %d = %d\n"
	.text
.globl main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$12, %edi
	call	fact
	movl	%eax, %edx
	movl	$12, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-23)"
	.section	.note.GNU-stack,"",@progbits
