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
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	pushq	%rax
	.cfi_def_cfa_offset 48
	.cfi_offset %rbx, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movl	$.L__unnamed_1, %edi
	movl	$row1, %esi
	xorl	%eax, %eax
	callq	scanf
	movl	$.L__unnamed_2, %edi
	movl	$col1, %esi
	xorl	%eax, %eax
	callq	scanf
	movl	row1(%rip), %r14d
	decl	%r14d
	movl	$0, i(%rip)
	jmp	.LBB0_1
	.p2align	4, 0x90
.LBB0_8:                                # %forcont6
                                        #   in Loop: Header=BB0_1 Depth=1
	incl	%r15d
	movl	%r15d, i(%rip)
.LBB0_1:                                # %cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_7 Depth 2
	movl	i(%rip), %r15d
	cmpl	%r14d, %r15d
	jg	.LBB0_2
# %bb.35:                               # %body
                                        #   in Loop: Header=BB0_1 Depth=1
	movl	col1(%rip), %ebx
	decl	%ebx
	movl	$0, j(%rip)
	.p2align	4, 0x90
.LBB0_7:                                # %cond8
                                        #   Parent Loop BB0_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	j(%rip), %ebp
	cmpl	%ebx, %ebp
	jg	.LBB0_8
# %bb.6:                                # %body7
                                        #   in Loop: Header=BB0_7 Depth=2
	movslq	i(%rip), %rax
	imulq	$124, %rax, %rax
	movslq	j(%rip), %rcx
	leaq	A(%rax,%rcx,4), %rsi
	movl	$.L__unnamed_3, %edi
	xorl	%eax, %eax
	callq	scanf
	incl	%ebp
	movl	%ebp, j(%rip)
	jmp	.LBB0_7
.LBB0_2:                                # %forcont
	movl	$.L__unnamed_4, %edi
	movl	$row2, %esi
	xorl	%eax, %eax
	callq	scanf
	movl	$.L__unnamed_5, %edi
	movl	$col2, %esi
	xorl	%eax, %eax
	callq	scanf
	movl	row2(%rip), %r14d
	decl	%r14d
	movl	$0, i(%rip)
	jmp	.LBB0_3
	.p2align	4, 0x90
.LBB0_12:                               # %forcont36
                                        #   in Loop: Header=BB0_3 Depth=1
	incl	%r15d
	movl	%r15d, i(%rip)
.LBB0_3:                                # %cond30
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_11 Depth 2
	movl	i(%rip), %r15d
	cmpl	%r14d, %r15d
	jg	.LBB0_4
# %bb.9:                                # %body29
                                        #   in Loop: Header=BB0_3 Depth=1
	movl	col2(%rip), %ebx
	decl	%ebx
	movl	$0, j(%rip)
	.p2align	4, 0x90
.LBB0_11:                               # %cond38
                                        #   Parent Loop BB0_3 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	j(%rip), %ebp
	cmpl	%ebx, %ebp
	jg	.LBB0_12
# %bb.10:                               # %body37
                                        #   in Loop: Header=BB0_11 Depth=2
	movslq	i(%rip), %rax
	imulq	$124, %rax, %rax
	movslq	j(%rip), %rcx
	leaq	B(%rax,%rcx,4), %rsi
	movl	$.L__unnamed_6, %edi
	xorl	%eax, %eax
	callq	scanf
	incl	%ebp
	movl	%ebp, j(%rip)
	jmp	.LBB0_11
.LBB0_4:                                # %forcont28
	movl	col1(%rip), %eax
	cmpl	row2(%rip), %eax
	je	.LBB0_14
# %bb.5:                                # %then
	subq	$8, %rsp
	.cfi_adjust_cfa_offset 8
	movl	$.str, %edi
	movl	$73, %esi
	movl	$110, %edx
	movl	$99, %ecx
	movl	$111, %r8d
	movl	$109, %r9d
	movl	$0, %eax
	pushq	$10
	.cfi_adjust_cfa_offset 8
	pushq	$115
	.cfi_adjust_cfa_offset 8
	pushq	$110
	.cfi_adjust_cfa_offset 8
	pushq	$111
	.cfi_adjust_cfa_offset 8
	pushq	$105
	.cfi_adjust_cfa_offset 8
	pushq	$115
	.cfi_adjust_cfa_offset 8
	pushq	$110
	.cfi_adjust_cfa_offset 8
	pushq	$101
	.cfi_adjust_cfa_offset 8
	pushq	$109
	.cfi_adjust_cfa_offset 8
	pushq	$105
	.cfi_adjust_cfa_offset 8
	pushq	$68
	.cfi_adjust_cfa_offset 8
	pushq	$32
	.cfi_adjust_cfa_offset 8
	pushq	$101
	.cfi_adjust_cfa_offset 8
	pushq	$108
	.cfi_adjust_cfa_offset 8
	pushq	$98
	.cfi_adjust_cfa_offset 8
	pushq	$105
	.cfi_adjust_cfa_offset 8
	pushq	$116
	.cfi_adjust_cfa_offset 8
	pushq	$97
	.cfi_adjust_cfa_offset 8
	pushq	$112
	.cfi_adjust_cfa_offset 8
	callq	printf
	addq	$160, %rsp
	.cfi_adjust_cfa_offset -160
.LBB0_20:                               # %ifcont
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.LBB0_14:                               # %else
	.cfi_def_cfa_offset 48
	movl	row1(%rip), %eax
	decl	%eax
	movl	$0, i(%rip)
	jmp	.LBB0_15
	.p2align	4, 0x90
.LBB0_23:                               # %forcont66
                                        #   in Loop: Header=BB0_15 Depth=1
	incl	%ecx
	movl	%ecx, i(%rip)
.LBB0_15:                               # %cond60
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_22 Depth 2
	movl	i(%rip), %ecx
	cmpl	%eax, %ecx
	jg	.LBB0_16
# %bb.13:                               # %body59
                                        #   in Loop: Header=BB0_15 Depth=1
	movl	col2(%rip), %edx
	decl	%edx
	movl	$0, j(%rip)
	.p2align	4, 0x90
.LBB0_22:                               # %cond68
                                        #   Parent Loop BB0_15 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	j(%rip), %esi
	cmpl	%edx, %esi
	jg	.LBB0_23
# %bb.21:                               # %body67
                                        #   in Loop: Header=BB0_22 Depth=2
	movslq	i(%rip), %rdi
	imulq	$124, %rdi, %rdi
	movslq	j(%rip), %rbp
	movl	$0, C(%rdi,%rbp,4)
	incl	%esi
	movl	%esi, j(%rip)
	jmp	.LBB0_22
.LBB0_16:                               # %forcont58
	movl	row1(%rip), %r8d
	decl	%r8d
	movl	$0, i(%rip)
	jmp	.LBB0_17
	.p2align	4, 0x90
.LBB0_27:                               # %forcont88
                                        #   in Loop: Header=BB0_17 Depth=1
	incl	%r9d
	movl	%r9d, i(%rip)
.LBB0_17:                               # %cond82
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_26 Depth 2
                                        #       Child Loop BB0_29 Depth 3
	movl	i(%rip), %r9d
	cmpl	%r8d, %r9d
	jg	.LBB0_18
# %bb.25:                               # %body81
                                        #   in Loop: Header=BB0_17 Depth=1
	movl	col2(%rip), %r10d
	decl	%r10d
	movl	$0, j(%rip)
	jmp	.LBB0_26
	.p2align	4, 0x90
.LBB0_30:                               # %forcont96
                                        #   in Loop: Header=BB0_26 Depth=2
	incl	%esi
	movl	%esi, j(%rip)
.LBB0_26:                               # %cond90
                                        #   Parent Loop BB0_17 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB0_29 Depth 3
	movl	j(%rip), %esi
	cmpl	%r10d, %esi
	jg	.LBB0_27
# %bb.24:                               # %body89
                                        #   in Loop: Header=BB0_26 Depth=2
	movl	row2(%rip), %edi
	decl	%edi
	movl	$0, k(%rip)
	.p2align	4, 0x90
.LBB0_29:                               # %cond98
                                        #   Parent Loop BB0_17 Depth=1
                                        #     Parent Loop BB0_26 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movl	k(%rip), %ebp
	cmpl	%edi, %ebp
	jg	.LBB0_30
# %bb.28:                               # %body97
                                        #   in Loop: Header=BB0_29 Depth=3
	movslq	i(%rip), %rbx
	imulq	$124, %rbx, %rbx
	movslq	j(%rip), %rax
	movslq	k(%rip), %rcx
	movl	A(%rbx,%rcx,4), %edx
	imulq	$124, %rcx, %rcx
	imull	B(%rcx,%rax,4), %edx
	addl	%edx, C(%rbx,%rax,4)
	incl	%ebp
	movl	%ebp, k(%rip)
	jmp	.LBB0_29
.LBB0_18:                               # %forcont80
	movl	row1(%rip), %r14d
	decl	%r14d
	movl	$0, i(%rip)
	jmp	.LBB0_19
	.p2align	4, 0x90
.LBB0_34:                               # %forcont134
                                        #   in Loop: Header=BB0_19 Depth=1
	movl	$.str.2, %edi
	xorl	%eax, %eax
	callq	printf
	incl	%r15d
	movl	%r15d, i(%rip)
.LBB0_19:                               # %cond128
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_33 Depth 2
	movl	i(%rip), %r15d
	cmpl	%r14d, %r15d
	jg	.LBB0_20
# %bb.31:                               # %body127
                                        #   in Loop: Header=BB0_19 Depth=1
	movl	col2(%rip), %ebx
	decl	%ebx
	movl	$0, j(%rip)
	.p2align	4, 0x90
.LBB0_33:                               # %cond136
                                        #   Parent Loop BB0_19 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	j(%rip), %ebp
	cmpl	%ebx, %ebp
	jg	.LBB0_34
# %bb.32:                               # %body135
                                        #   in Loop: Header=BB0_33 Depth=2
	movslq	i(%rip), %rax
	imulq	$124, %rax, %rax
	movslq	j(%rip), %rcx
	movl	C(%rax,%rcx,4), %esi
	movl	$.str.1, %edi
	xorl	%eax, %eax
	callq	printf
	incl	%ebp
	movl	%ebp, j(%rip)
	jmp	.LBB0_33
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	row1,@object            # @row1
	.bss
	.globl	row1
	.p2align	2
row1:
	.long	0                       # 0x0
	.size	row1, 4

	.type	col1,@object            # @col1
	.globl	col1
	.p2align	2
col1:
	.long	0                       # 0x0
	.size	col1, 4

	.type	row2,@object            # @row2
	.globl	row2
	.p2align	2
row2:
	.long	0                       # 0x0
	.size	row2, 4

	.type	col2,@object            # @col2
	.globl	col2
	.p2align	2
col2:
	.long	0                       # 0x0
	.size	col2, 4

	.type	A,@object               # @A
	.globl	A
	.p2align	4
A:
	.zero	3844
	.size	A, 3844

	.type	B,@object               # @B
	.globl	B
	.p2align	4
B:
	.zero	3844
	.size	B, 3844

	.type	C,@object               # @C
	.globl	C
	.p2align	4
C:
	.zero	3844
	.size	C, 3844

	.type	i,@object               # @i
	.globl	i
	.p2align	2
i:
	.long	0                       # 0x0
	.size	i, 4

	.type	j,@object               # @j
	.globl	j
	.p2align	2
j:
	.long	0                       # 0x0
	.size	j, 4

	.type	k,@object               # @k
	.globl	k
	.p2align	2
k:
	.long	0                       # 0x0
	.size	k, 4

	.type	.L__unnamed_1,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%d"
	.size	.L__unnamed_1, 3

	.type	.L__unnamed_2,@object   # @1
.L__unnamed_2:
	.asciz	"%d"
	.size	.L__unnamed_2, 3

	.type	.L__unnamed_3,@object   # @2
.L__unnamed_3:
	.asciz	"%d"
	.size	.L__unnamed_3, 3

	.type	.L__unnamed_4,@object   # @3
.L__unnamed_4:
	.asciz	"%d"
	.size	.L__unnamed_4, 3

	.type	.L__unnamed_5,@object   # @4
.L__unnamed_5:
	.asciz	"%d"
	.size	.L__unnamed_5, 3

	.type	.L__unnamed_6,@object   # @5
.L__unnamed_6:
	.asciz	"%d"
	.size	.L__unnamed_6, 3

	.type	.str,@object            # @.str
	.section	.rodata,"a",@progbits
	.globl	.str
	.p2align	4
.str:
	.asciz	"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	.size	.str, 49

	.type	.str.1,@object          # @.str.1
	.globl	.str.1
.str.1:
	.asciz	"%10d"
	.size	.str.1, 5

	.type	.str.2,@object          # @.str.2
	.globl	.str.2
.str.2:
	.asciz	"\n"
	.size	.str.2, 2

	.section	".note.GNU-stack","",@progbits
