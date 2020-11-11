	.file	"ctrlflow.c"
	.text
.globl get_cycle_count
	.type	get_cycle_count, @function
get_cycle_count:
.LFB11:
	.cfi_startproc
#APP
# 13 "ctrlflow.c" 1
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
.globl if_goto
	.type	if_goto, @function
if_goto:
.LFB13:
	.cfi_startproc
	testl	%edi, %edi
	jne	.L4
	movl	%edx, %eax
	ret
.L4:
	movl	%esi, %eax
.L5:
.L6:
.L7:
	ret
	.cfi_endproc
.LFE13:
	.size	if_goto, .-if_goto
.globl if_nogoto
	.type	if_nogoto, @function
if_nogoto:
.LFB14:
	.cfi_startproc
	testl	%edi, %edi
	je	.L10
	movl	%esi, %eax
	ret
.L10:
	movl	%edx, %eax
	ret
	.cfi_endproc
.LFE14:
	.size	if_nogoto, .-if_nogoto
.globl do_while_loop
	.type	do_while_loop, @function
do_while_loop:
.LFB15:
	.cfi_startproc
	movl	$93, -4(%rsp)
.L14:
	movl	-4(%rsp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rsp)
	subl	$1, %edi
	jne	.L14
	movl	-4(%rsp), %eax
	ret
	.cfi_endproc
.LFE15:
	.size	do_while_loop, .-do_while_loop
.globl while_loop
	.type	while_loop, @function
while_loop:
.LFB16:
	.cfi_startproc
	movl	$93, -4(%rsp)
	testl	%edi, %edi
	je	.L18
.L21:
	movl	-4(%rsp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rsp)
	subl	$1, %edi
	jne	.L21
.L18:
	movl	-4(%rsp), %eax
	ret
	.cfi_endproc
.LFE16:
	.size	while_loop, .-while_loop
.globl for_loop
	.type	for_loop, @function
for_loop:
.LFB17:
	.cfi_startproc
	movl	$93, -4(%rsp)
	testl	%edi, %edi
	je	.L24
.L25:
	movl	-4(%rsp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rsp)
	subl	$1, %edi
	jne	.L25
.L24:
	movl	-4(%rsp), %eax
	ret
	.cfi_endproc
.LFE17:
	.size	for_loop, .-for_loop
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Hi, %d\n"
	.text
.globl switch_case
	.type	switch_case, @function
switch_case:
.LFB18:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	cmpl	$4, %edi
	ja	.L29
	mov	%edi, %edi
	jmp	*.L35(,%rdi,8)
	.section	.rodata
	.align 8
	.align 4
.L35:
	.quad	.L30
	.quad	.L31
	.quad	.L32
	.quad	.L33
	.quad	.L34
	.text
.L32:
	movl	$533, %eax
	jmp	.L36
.L31:
	movl	$99, %eax
	jmp	.L36
.L30:
	movl	$0, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$3, %eax
	jmp	.L36
.L33:
	movl	$321, %eax
	jmp	.L36
.L34:
	movl	$-4, %eax
	jmp	.L36
.L29:
	movl	$0, %eax
.L36:
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE18:
	.size	switch_case, .-switch_case
.globl main
	.type	main, @function
main:
.LFB19:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$5, %edi
	call	do_while_loop
	movl	$5, %edi
	call	while_loop
	movl	$5, %edi
	call	for_loop
	movl	$2, %edi
	call	switch_case
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE19:
	.size	main, .-main
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC1:
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
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE12:
	.size	timing_overhead, .-timing_overhead
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-23)"
	.section	.note.GNU-stack,"",@progbits
