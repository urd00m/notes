	.file	"struct.c"
	.text
.globl insert_by_age
	.type	insert_by_age, @function
insert_by_age:
.LFB18:
	.cfi_startproc
	movq	(%rdi), %rdx
	testq	%rdx, %rdx
	je	.L2
	movzbl	8(%rsi), %ecx
	cmpb	%cl, 8(%rdx)
	jle	.L3
.L2:
	movq	%rdx, 16(%rsi)
	movq	%rsi, (%rdi)
	ret
.L6:
	movq	%rax, %rdx
.L3:
	movq	16(%rdx), %rax
	testq	%rax, %rax
	je	.L5
	cmpb	8(%rax), %cl
	jge	.L6
.L5:
	movq	16(%rdx), %rax
	movq	%rax, 16(%rsi)
	movq	%rsi, 16(%rdx)
	ret
	.cfi_endproc
.LFE18:
	.size	insert_by_age, .-insert_by_age
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%s => %d\n"
	.text
.globl print
	.type	print, @function
print:
.LFB19:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	testq	%rdi, %rdi
	je	.L11
.L12:
	movsbl	8(%rbx), %edx
	movq	(%rbx), %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movq	16(%rbx), %rbx
	testq	%rbx, %rbx
	jne	.L12
.L11:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE19:
	.size	print, .-print
	.section	.rodata.str1.1
.LC1:
	.string	"huh?"
	.text
.globl fail
	.type	fail, @function
fail:
.LFB20:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$.LC1, %edi
	call	puts
	movl	$-1, %edi
	call	exit
	.cfi_endproc
.LFE20:
	.size	fail, .-fail
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Offsets of fields in struct node are:"
	.align 8
.LC3:
	.string	"name: 0x%lx\nage:  0x%lx\nnext: 0x%lx\n"
	.section	.rodata.str1.1
.LC4:
	.string	"sizeof(struct node) = 0x%x\n"
.LC5:
	.string	"Joe"
.LC6:
	.string	"Jane"
.LC7:
	.string	"Dave"
.LC8:
	.string	"Michela"
	.text
.globl main
	.type	main, @function
main:
.LFB21:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$.LC2, %edi
	call	puts
	movl	$16, %ecx
	movl	$8, %edx
	movl	$0, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$24, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	$24, %edi
	call	malloc
	movq	%rax, %rbx
	testq	%rax, %rax
	jne	.L17
	movl	$0, %eax
	call	fail
.L17:
	movq	$.LC5, (%rbx)
	movb	$34, 8(%rbx)
	movq	%rbx, %rsi
	movl	$list, %edi
	call	insert_by_age
	movl	$24, %edi
	call	malloc
	movq	%rax, %rbx
	testq	%rax, %rax
	jne	.L18
	movl	$0, %eax
	call	fail
.L18:
	movq	$.LC6, (%rbx)
	movb	$43, 8(%rbx)
	movq	%rbx, %rsi
	movl	$list, %edi
	call	insert_by_age
	movl	$24, %edi
	call	malloc
	movq	%rax, %rbx
	testq	%rax, %rax
	jne	.L19
	movl	$0, %eax
	call	fail
.L19:
	movq	$.LC7, (%rbx)
	movb	$21, 8(%rbx)
	movq	%rbx, %rsi
	movl	$list, %edi
	call	insert_by_age
	movl	$24, %edi
	call	malloc
	movq	%rax, %rbx
	testq	%rax, %rax
	jne	.L20
	movl	$0, %eax
	call	fail
.L20:
	movq	$.LC8, (%rbx)
	movb	$27, 8(%rbx)
	movq	%rbx, %rsi
	movl	$list, %edi
	call	insert_by_age
	movq	list(%rip), %rdi
	call	print
	movl	$0, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE21:
	.size	main, .-main
.globl list
	.bss
	.align 8
	.type	list, @object
	.size	list, 8
list:
	.zero	8
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-23)"
	.section	.note.GNU-stack,"",@progbits
