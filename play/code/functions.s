	.file	"functions.c"
	.text
.globl big_callee
	.type	big_callee, @function
big_callee:
.LFB11:
	.cfi_startproc
	testl	%edi, %edi
	jg	.L2
	movl	%edi, %eax
	ret
.L2:
	movl	%edi, %eax
	imull	%edi, %eax
	addl	%edi, %eax
	ret
	.cfi_endproc
.LFE11:
	.size	big_callee, .-big_callee
.globl big_caller
	.type	big_caller, @function
big_caller:
.LFB12:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	testl	%edi, %edi
	jg	.L6
	movl	%edi, %ebx
	jmp	.L7
.L6:
	movl	%edi, %ebx
	imull	%edi, %ebx
	addl	%edi, %ebx
.L7:
	call	big_callee
	leal	(%rbx,%rax), %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE12:
	.size	big_caller, .-big_caller
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Type in zip code:"
.LC1:
	.string	"OK, thanks."
	.text
.globl buf_overflow_vulnerability
	.type	buf_overflow_vulnerability, @function
buf_overflow_vulnerability:
.LFB13:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	$.LC0, %edi
	call	puts
	movq	%rsp, %rdi
	call	gets
	movl	$.LC1, %edi
	call	puts
	movl	$0, %eax
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE13:
	.size	buf_overflow_vulnerability, .-buf_overflow_vulnerability
.globl main
	.type	main, @function
main:
.LFB14:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$953, %edi
	call	big_caller
	movl	$0, %eax
	call	buf_overflow_vulnerability
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE14:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-23)"
	.section	.note.GNU-stack,"",@progbits
