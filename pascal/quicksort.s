	.text
	.file	"main"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entrypoint
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	pushq	%rax
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -24
	.cfi_offset %rbp, -16
	movl	$.L__unnamed_1, %edi
	movl	$N, %esi
	xorl	%eax, %eax
	callq	scanf
	movl	N(%rip), %ebx
	decl	%ebx
	movl	$0, i(%rip)
	.p2align	4, 0x90
.LBB0_2:                                # %cond
                                        # =>This Inner Loop Header: Depth=1
	movl	i(%rip), %ebp
	cmpl	%ebx, %ebp
	jg	.LBB0_3
# %bb.1:                                # %body
                                        #   in Loop: Header=BB0_2 Depth=1
	movslq	i(%rip), %rax
	leaq	arr(,%rax,4), %rsi
	movl	$.L__unnamed_2, %edi
	xorl	%eax, %eax
	callq	scanf
	incl	%ebp
	movl	%ebp, i(%rip)
	jmp	.LBB0_2
.LBB0_3:                                # %forcont
	movl	N(%rip), %esi
	decl	%esi
	xorl	%edi, %edi
	callq	sort
	movl	N(%rip), %ebx
	decl	%ebx
	movl	$0, i(%rip)
	.p2align	4, 0x90
.LBB0_5:                                # %cond13
                                        # =>This Inner Loop Header: Depth=1
	movl	i(%rip), %ebp
	cmpl	%ebx, %ebp
	jg	.LBB0_6
# %bb.4:                                # %body12
                                        #   in Loop: Header=BB0_5 Depth=1
	movslq	i(%rip), %rax
	movl	arr(,%rax,4), %esi
	movl	$.str, %edi
	xorl	%eax, %eax
	callq	printf
	incl	%ebp
	movl	%ebp, i(%rip)
	jmp	.LBB0_5
.LBB0_6:                                # %forcont11
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function sort
	.type	sort,@function
sort:                                   # @sort
	.cfi_startproc
# %bb.0:                                # %entrypoint
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	%edi, 8(%rsp)
	movl	%esi, 12(%rsp)
	movl	$0, 16(%rsp)
	movl	$0, (%rsp)
	movl	$0, 4(%rsp)
	movl	$0, 20(%rsp)
	cmpl	%esi, %edi
	jge	.LBB1_4
# %bb.1:                                # %then
	movslq	8(%rsp), %rax
	movl	arr(,%rax,4), %ecx
	movl	%ecx, 16(%rsp)
	movl	%eax, (%rsp)
	leal	1(%rax), %ecx
	movl	12(%rsp), %r8d
	jmp	.LBB1_2
	.p2align	4, 0x90
.LBB1_7:                                # %ifcont16
                                        #   in Loop: Header=BB1_2 Depth=1
	incl	%ecx
.LBB1_2:                                # %cond
                                        # =>This Inner Loop Header: Depth=1
	movl	%ecx, 4(%rsp)
	movl	4(%rsp), %ecx
	cmpl	%r8d, %ecx
	jg	.LBB1_3
# %bb.5:                                # %body
                                        #   in Loop: Header=BB1_2 Depth=1
	movslq	4(%rsp), %rdx
	movl	arr(,%rdx,4), %edx
	cmpl	16(%rsp), %edx
	jge	.LBB1_7
# %bb.6:                                # %then17
                                        #   in Loop: Header=BB1_2 Depth=1
	movslq	4(%rsp), %rdx
	movl	arr(,%rdx,4), %esi
	movl	%esi, 20(%rsp)
	movl	(%rsp), %edi
	incl	%edi
	movslq	%edi, %rdi
	movl	arr(,%rdi,4), %eax
	movl	%eax, arr(,%rdx,4)
	movl	%esi, arr(,%rdi,4)
	movslq	(%rsp), %rax
	leal	1(%rax), %edx
	movslq	%edx, %rdx
	movl	arr(,%rax,4), %eax
	movl	%eax, arr(,%rdx,4)
	movslq	(%rsp), %rax
	movl	%esi, arr(,%rax,4)
	incl	(%rsp)
	jmp	.LBB1_7
.LBB1_3:                                # %forcont
	movl	8(%rsp), %edi
	movl	(%rsp), %esi
	decl	%esi
	callq	sort
	movl	(%rsp), %edi
	incl	%edi
	movl	12(%rsp), %esi
	callq	sort
.LBB1_4:                                # %ifcont
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	sort, .Lfunc_end1-sort
	.cfi_endproc
                                        # -- End function
	.type	N,@object               # @N
	.bss
	.globl	N
	.p2align	2
N:
	.long	0                       # 0x0
	.size	N, 4

	.type	i,@object               # @i
	.globl	i
	.p2align	2
i:
	.long	0                       # 0x0
	.size	i, 4

	.type	arr,@object             # @arr
	.globl	arr
	.p2align	4
arr:
	.zero	40004
	.size	arr, 40004

	.type	.L__unnamed_1,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%d"
	.size	.L__unnamed_1, 3

	.type	.L__unnamed_2,@object   # @1
.L__unnamed_2:
	.asciz	"%d"
	.size	.L__unnamed_2, 3

	.type	.str,@object            # @.str
	.section	.rodata,"a",@progbits
	.globl	.str
.str:
	.asciz	"%d\n"
	.size	.str, 4

	.section	".note.GNU-stack","",@progbits
