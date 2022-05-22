	.text
	.file	"main"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entrypoint
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$0, totalCrediet(%rip)
	movl	$0, attemptCrediet(%rip)
	movl	$0, getCrediet(%rip)
	movl	$0, remainCredite(%rip)
	movl	$0, gradeTmp(%rip)
	movl	$0, validIdx(%rip)
	movl	$.L__unnamed_1, %edi
	jmp	.LBB0_3
	.p2align	4, 0x90
.LBB0_1:                                # %ifcont135
                                        #   in Loop: Header=BB0_3 Depth=1
	movslq	n(%rip), %rax
	movb	ch(%rip), %cl
	movb	%cl, grade(%rax)
	movl	$.L__unnamed_2, %edi
	movl	$ch, %esi
	xorl	%eax, %eax
	callq	scanf
.LBB0_2:                                # %ifcont75
                                        #   in Loop: Header=BB0_3 Depth=1
	movl	$.L__unnamed_3, %edi
.LBB0_3:                                # %cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_6 Depth 2
	movl	$c, %esi
	xorl	%eax, %eax
	callq	scanf
	cmpb	$99, c(%rip)
	jne	.LBB0_20
# %bb.5:                                # %body
                                        #   in Loop: Header=BB0_3 Depth=1
	movl	$.L__unnamed_4, %edi
	movl	$n, %esi
	xorl	%eax, %eax
	callq	scanf
	movslq	validIdx(%rip), %rax
	movl	n(%rip), %ecx
	movl	%ecx, validCourse(,%rax,4)
	incl	validIdx(%rip)
	movl	$.L__unnamed_5, %edi
	movl	$ch, %esi
	xorl	%eax, %eax
	callq	scanf
	movl	$.L__unnamed_6, %edi
	movl	$num, %esi
	xorl	%eax, %eax
	callq	scanf
	movslq	n(%rip), %rax
	movl	num(%rip), %ecx
	movl	%ecx, crediet(,%rax,4)
	movl	num(%rip), %eax
	addl	%eax, totalCrediet(%rip)
	movl	$.L__unnamed_7, %edi
	movl	$ch, %esi
	xorl	%eax, %eax
	callq	scanf
	movl	$.L__unnamed_8, %edi
	movl	$ch, %esi
	xorl	%eax, %eax
	callq	scanf
	movl	$0, idx(%rip)
	.p2align	4, 0x90
.LBB0_6:                                # %cond32
                                        #   Parent Loop BB0_3 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpb	$124, ch(%rip)
	je	.LBB0_11
# %bb.7:                                # %body31
                                        #   in Loop: Header=BB0_6 Depth=2
	movl	$.L__unnamed_9, %edi
	movl	$cNum, %esi
	xorl	%eax, %eax
	callq	scanf
	movslq	n(%rip), %rax
	imulq	$4000, %rax, %rax       # imm = 0xFA0
	movslq	idx(%rip), %rcx
	movl	cNum(%rip), %edx
	movl	%edx, require(%rax,%rcx,4)
	incl	idx(%rip)
	movl	$.L__unnamed_10, %edi
	movl	$ch, %esi
	xorl	%eax, %eax
	callq	scanf
	cmpb	$44, ch(%rip)
	jne	.LBB0_9
# %bb.8:                                # %then
                                        #   in Loop: Header=BB0_6 Depth=2
	movl	$.L__unnamed_11, %edi
	movl	$ch, %esi
	xorl	%eax, %eax
	callq	scanf
.LBB0_9:                                # %ifcont
                                        #   in Loop: Header=BB0_6 Depth=2
	cmpb	$59, ch(%rip)
	jne	.LBB0_6
# %bb.10:                               # %then55
                                        #   in Loop: Header=BB0_6 Depth=2
	movslq	n(%rip), %rax
	imulq	$4000, %rax, %rax       # imm = 0xFA0
	movslq	idx(%rip), %rcx
	movl	$-1, require(%rax,%rcx,4)
	incl	idx(%rip)
	movl	$.L__unnamed_12, %edi
	movl	$ch, %esi
	xorl	%eax, %eax
	callq	scanf
	jmp	.LBB0_6
	.p2align	4, 0x90
.LBB0_11:                               # %whilecont30
                                        #   in Loop: Header=BB0_3 Depth=1
	movslq	n(%rip), %rax
	imulq	$4000, %rax, %rax       # imm = 0xFA0
	movslq	idx(%rip), %rcx
	movl	$-2, require(%rax,%rcx,4)
	movl	$.L__unnamed_13, %edi
	movl	$ch, %esi
	xorl	%eax, %eax
	callq	scanf
	cmpb	$10, ch(%rip)
	je	.LBB0_2
# %bb.12:                               # %then76
                                        #   in Loop: Header=BB0_3 Depth=1
	movl	num(%rip), %eax
	addl	%eax, attemptCrediet(%rip)
	cmpb	$65, ch(%rip)
	jne	.LBB0_14
# %bb.13:                               # %then86
                                        #   in Loop: Header=BB0_3 Depth=1
	movl	num(%rip), %eax
	addl	%eax, getCrediet(%rip)
	shll	$2, %eax
	addl	%eax, gradeTmp(%rip)
	movslq	n(%rip), %rax
	movl	$1, pass(,%rax,4)
.LBB0_14:                               # %ifcont85
                                        #   in Loop: Header=BB0_3 Depth=1
	cmpb	$66, ch(%rip)
	jne	.LBB0_16
# %bb.15:                               # %then102
                                        #   in Loop: Header=BB0_3 Depth=1
	movl	num(%rip), %eax
	addl	%eax, getCrediet(%rip)
	leal	(%rax,%rax,2), %eax
	addl	%eax, gradeTmp(%rip)
	movslq	n(%rip), %rax
	movl	$1, pass(,%rax,4)
.LBB0_16:                               # %ifcont101
                                        #   in Loop: Header=BB0_3 Depth=1
	cmpb	$67, ch(%rip)
	jne	.LBB0_18
# %bb.17:                               # %then119
                                        #   in Loop: Header=BB0_3 Depth=1
	movl	num(%rip), %eax
	addl	%eax, getCrediet(%rip)
	addl	%eax, %eax
	addl	%eax, gradeTmp(%rip)
	movslq	n(%rip), %rax
	movl	$1, pass(,%rax,4)
.LBB0_18:                               # %ifcont118
                                        #   in Loop: Header=BB0_3 Depth=1
	cmpb	$68, ch(%rip)
	jne	.LBB0_1
# %bb.19:                               # %then136
                                        #   in Loop: Header=BB0_3 Depth=1
	movl	num(%rip), %eax
	addl	%eax, getCrediet(%rip)
	addl	%eax, gradeTmp(%rip)
	movslq	n(%rip), %rax
	movl	$1, pass(,%rax,4)
	jmp	.LBB0_1
.LBB0_20:                               # %whilecont
	movslq	validIdx(%rip), %rax
	movl	$-1, validCourse(,%rax,4)
	cmpb	$120, c(%rip)
	jne	.LBB0_22
# %bb.21:                               # %then162
	movl	$0, attemptCrediet(%rip)
	movl	$0, getCrediet(%rip)
	movl	$3, totalCrediet(%rip)
.LBB0_22:                               # %ifcont161
	movl	$.str, %edi
	movl	$71, %esi
	movl	$80, %edx
	movl	$65, %ecx
	movl	$58, %r8d
	movl	$32, %r9d
	xorl	%eax, %eax
	callq	printf
	cmpl	$0, attemptCrediet(%rip)
	jne	.LBB0_24
# %bb.23:                               # %then171
	movq	$0, GPA(%rip)
	jmp	.LBB0_25
.LBB0_24:                               # %else172
	movl	gradeTmp(%rip), %eax
	cvtsi2sd	%rax, %xmm0
	movsd	%xmm0, gradeReal(%rip)
	movl	attemptCrediet(%rip), %eax
	cvtsi2sd	%rax, %xmm1
	movsd	%xmm1, attemptCredietReal(%rip)
	divsd	%xmm1, %xmm0
	movsd	%xmm0, GPA(%rip)
.LBB0_25:                               # %ifcont170
	movsd	GPA(%rip), %xmm0        # xmm0 = mem[0],zero
	movl	$.str.1, %edi
	movb	$1, %al
	callq	printf
	movl	$.str.2, %edi
	movl	$72, %esi
	movl	$111, %edx
	movl	$117, %ecx
	movl	$114, %r8d
	movl	$115, %r9d
	movl	$0, %eax
	pushq	$32
	.cfi_adjust_cfa_offset 8
	pushq	$58
	.cfi_adjust_cfa_offset 8
	pushq	$100
	.cfi_adjust_cfa_offset 8
	pushq	$101
	.cfi_adjust_cfa_offset 8
	pushq	$116
	.cfi_adjust_cfa_offset 8
	pushq	$112
	.cfi_adjust_cfa_offset 8
	pushq	$109
	.cfi_adjust_cfa_offset 8
	pushq	$101
	.cfi_adjust_cfa_offset 8
	pushq	$116
	.cfi_adjust_cfa_offset 8
	pushq	$116
	.cfi_adjust_cfa_offset 8
	pushq	$65
	.cfi_adjust_cfa_offset 8
	pushq	$32
	.cfi_adjust_cfa_offset 8
	callq	printf
	addq	$96, %rsp
	.cfi_adjust_cfa_offset -96
	movl	attemptCrediet(%rip), %esi
	movl	$.str.3, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.str.4, %edi
	movl	$72, %esi
	movl	$111, %edx
	movl	$117, %ecx
	movl	$114, %r8d
	movl	$115, %r9d
	movl	$0, %eax
	pushq	$32
	.cfi_adjust_cfa_offset 8
	pushq	$58
	.cfi_adjust_cfa_offset 8
	pushq	$100
	.cfi_adjust_cfa_offset 8
	pushq	$101
	.cfi_adjust_cfa_offset 8
	pushq	$116
	.cfi_adjust_cfa_offset 8
	pushq	$101
	.cfi_adjust_cfa_offset 8
	pushq	$108
	.cfi_adjust_cfa_offset 8
	pushq	$112
	.cfi_adjust_cfa_offset 8
	pushq	$109
	.cfi_adjust_cfa_offset 8
	pushq	$111
	.cfi_adjust_cfa_offset 8
	pushq	$67
	.cfi_adjust_cfa_offset 8
	pushq	$32
	.cfi_adjust_cfa_offset 8
	callq	printf
	addq	$96, %rsp
	.cfi_adjust_cfa_offset -96
	movl	getCrediet(%rip), %esi
	movl	$.str.5, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.str.6, %edi
	movl	$67, %esi
	movl	$114, %edx
	movl	$101, %ecx
	movl	$100, %r8d
	movl	$105, %r9d
	movl	$0, %eax
	pushq	$32
	.cfi_adjust_cfa_offset 8
	pushq	$58
	.cfi_adjust_cfa_offset 8
	pushq	$103
	.cfi_adjust_cfa_offset 8
	pushq	$110
	.cfi_adjust_cfa_offset 8
	pushq	$105
	.cfi_adjust_cfa_offset 8
	pushq	$110
	.cfi_adjust_cfa_offset 8
	pushq	$105
	.cfi_adjust_cfa_offset 8
	pushq	$97
	.cfi_adjust_cfa_offset 8
	pushq	$109
	.cfi_adjust_cfa_offset 8
	pushq	$101
	.cfi_adjust_cfa_offset 8
	pushq	$82
	.cfi_adjust_cfa_offset 8
	pushq	$32
	.cfi_adjust_cfa_offset 8
	pushq	$115
	.cfi_adjust_cfa_offset 8
	pushq	$116
	.cfi_adjust_cfa_offset 8
	callq	printf
	addq	$112, %rsp
	.cfi_adjust_cfa_offset -112
	movl	totalCrediet(%rip), %esi
	subl	getCrediet(%rip), %esi
	movl	$.str.7, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.str.8, %edi
	movl	$10, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.str.9, %edi
	movl	$80, %esi
	movl	$111, %edx
	movl	$115, %ecx
	movl	$115, %r8d
	movl	$105, %r9d
	movl	$0, %eax
	pushq	$116
	.cfi_adjust_cfa_offset 8
	pushq	$120
	.cfi_adjust_cfa_offset 8
	pushq	$101
	.cfi_adjust_cfa_offset 8
	pushq	$78
	.cfi_adjust_cfa_offset 8
	pushq	$32
	.cfi_adjust_cfa_offset 8
	pushq	$101
	.cfi_adjust_cfa_offset 8
	pushq	$107
	.cfi_adjust_cfa_offset 8
	pushq	$97
	.cfi_adjust_cfa_offset 8
	pushq	$84
	.cfi_adjust_cfa_offset 8
	pushq	$32
	.cfi_adjust_cfa_offset 8
	pushq	$111
	.cfi_adjust_cfa_offset 8
	pushq	$116
	.cfi_adjust_cfa_offset 8
	pushq	$32
	.cfi_adjust_cfa_offset 8
	pushq	$115
	.cfi_adjust_cfa_offset 8
	pushq	$101
	.cfi_adjust_cfa_offset 8
	pushq	$115
	.cfi_adjust_cfa_offset 8
	pushq	$114
	.cfi_adjust_cfa_offset 8
	pushq	$117
	.cfi_adjust_cfa_offset 8
	pushq	$111
	.cfi_adjust_cfa_offset 8
	pushq	$67
	.cfi_adjust_cfa_offset 8
	pushq	$32
	.cfi_adjust_cfa_offset 8
	pushq	$101
	.cfi_adjust_cfa_offset 8
	pushq	$108
	.cfi_adjust_cfa_offset 8
	pushq	$98
	.cfi_adjust_cfa_offset 8
	callq	printf
	addq	$192, %rsp
	.cfi_adjust_cfa_offset -192
	movl	$.str.10, %edi
	movl	$10, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$0, validIdx(%rip)
	movl	totalCrediet(%rip), %eax
	cmpl	getCrediet(%rip), %eax
	jne	.LBB0_27
# %bb.26:                               # %then203
	subq	$8, %rsp
	.cfi_adjust_cfa_offset 8
	movl	$.str.11, %edi
	movl	$32, %esi
	movl	$32, %edx
	movl	$78, %ecx
	movl	$111, %r8d
	movl	$110, %r9d
	movl	$0, %eax
	pushq	$10
	.cfi_adjust_cfa_offset 8
	pushq	$33
	.cfi_adjust_cfa_offset 8
	pushq	$115
	.cfi_adjust_cfa_offset 8
	pushq	$110
	.cfi_adjust_cfa_offset 8
	pushq	$111
	.cfi_adjust_cfa_offset 8
	pushq	$105
	.cfi_adjust_cfa_offset 8
	pushq	$116
	.cfi_adjust_cfa_offset 8
	pushq	$97
	.cfi_adjust_cfa_offset 8
	pushq	$108
	.cfi_adjust_cfa_offset 8
	pushq	$117
	.cfi_adjust_cfa_offset 8
	pushq	$116
	.cfi_adjust_cfa_offset 8
	pushq	$97
	.cfi_adjust_cfa_offset 8
	pushq	$114
	.cfi_adjust_cfa_offset 8
	pushq	$103
	.cfi_adjust_cfa_offset 8
	pushq	$110
	.cfi_adjust_cfa_offset 8
	pushq	$111
	.cfi_adjust_cfa_offset 8
	pushq	$67
	.cfi_adjust_cfa_offset 8
	pushq	$32
	.cfi_adjust_cfa_offset 8
	pushq	$45
	.cfi_adjust_cfa_offset 8
	pushq	$32
	.cfi_adjust_cfa_offset 8
	pushq	$101
	.cfi_adjust_cfa_offset 8
	callq	printf
	addq	$176, %rsp
	.cfi_adjust_cfa_offset -176
.LBB0_27:                               # %ifcont202
	movl	totalCrediet(%rip), %eax
	cmpl	getCrediet(%rip), %eax
	jne	.LBB0_30
.LBB0_28:                               # %ifcont210
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
	.p2align	4, 0x90
.LBB0_29:                               # %ifcont306
                                        #   in Loop: Header=BB0_30 Depth=1
	.cfi_def_cfa_offset 16
	incl	validIdx(%rip)
.LBB0_30:                               # %cond215
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_35 Depth 2
	movslq	validIdx(%rip), %rax
	cmpl	$-1, validCourse(,%rax,4)
	je	.LBB0_28
# %bb.31:                               # %body214
                                        #   in Loop: Header=BB0_30 Depth=1
	movslq	validIdx(%rip), %rax
	movslq	validCourse(,%rax,4), %rax
	movl	%eax, n(%rip)
	movl	$0, idx(%rip)
	movl	$1, flag(%rip)
	movl	$0, ok(%rip)
	cmpl	$1, pass(,%rax,4)
	jne	.LBB0_34
# %bb.32:                               # %then233
                                        #   in Loop: Header=BB0_30 Depth=1
	movl	$0, flag(%rip)
	cmpl	$0, flag(%rip)
	jne	.LBB0_35
	jmp	.LBB0_46
	.p2align	4, 0x90
.LBB0_33:                               # %ifcont284
                                        #   in Loop: Header=BB0_30 Depth=1
	incl	idx(%rip)
.LBB0_34:                               # %cond238
                                        #   in Loop: Header=BB0_30 Depth=1
	cmpl	$0, flag(%rip)
	je	.LBB0_46
.LBB0_35:                               # %body237
                                        #   Parent Loop BB0_30 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	n(%rip), %rax
	imulq	$4000, %rax, %rax       # imm = 0xFA0
	movslq	idx(%rip), %rcx
	cmpl	$-2, require(%rax,%rcx,4)
	jne	.LBB0_39
# %bb.36:                               # %then250
                                        #   in Loop: Header=BB0_35 Depth=2
	cmpl	$1, flag(%rip)
	jne	.LBB0_38
# %bb.37:                               # %then256
                                        #   in Loop: Header=BB0_35 Depth=2
	movl	$1, ok(%rip)
.LBB0_38:                               # %ifcont255
                                        #   in Loop: Header=BB0_35 Depth=2
	movl	$0, flag(%rip)
.LBB0_39:                               # %ifcont249
                                        #   in Loop: Header=BB0_35 Depth=2
	movslq	n(%rip), %rax
	imulq	$4000, %rax, %rax       # imm = 0xFA0
	movslq	idx(%rip), %rcx
	cmpl	$-1, require(%rax,%rcx,4)
	jne	.LBB0_43
# %bb.40:                               # %then268
                                        #   in Loop: Header=BB0_35 Depth=2
	cmpl	$1, flag(%rip)
	jne	.LBB0_42
# %bb.41:                               # %then274
                                        #   in Loop: Header=BB0_35 Depth=2
	movl	$1, ok(%rip)
.LBB0_42:                               # %ifcont273
                                        #   in Loop: Header=BB0_35 Depth=2
	movl	$1, flag(%rip)
.LBB0_43:                               # %ifcont267
                                        #   in Loop: Header=BB0_35 Depth=2
	movslq	n(%rip), %rax
	imulq	$4000, %rax, %rax       # imm = 0xFA0
	movslq	idx(%rip), %rcx
	cmpl	$0, require(%rax,%rcx,4)
	js	.LBB0_33
# %bb.44:                               # %then285
                                        #   in Loop: Header=BB0_35 Depth=2
	movslq	n(%rip), %rax
	imulq	$4000, %rax, %rax       # imm = 0xFA0
	movslq	idx(%rip), %rcx
	movslq	require(%rax,%rcx,4), %rax
	cmpl	$0, pass(,%rax,4)
	jne	.LBB0_33
# %bb.45:                               # %then297
                                        #   in Loop: Header=BB0_35 Depth=2
	movl	$-1, flag(%rip)
	incl	idx(%rip)
	cmpl	$0, flag(%rip)
	jne	.LBB0_35
.LBB0_46:                               # %whilecont236
                                        #   in Loop: Header=BB0_30 Depth=1
	cmpl	$1, ok(%rip)
	jne	.LBB0_29
# %bb.47:                               # %then307
                                        #   in Loop: Header=BB0_30 Depth=1
	movl	n(%rip), %r8d
	movl	$.str.12, %edi
	movl	$32, %esi
	movl	$32, %edx
	movl	$99, %ecx
	movl	$10, %r9d
	xorl	%eax, %eax
	callq	printf
	incl	validIdx(%rip)
	jmp	.LBB0_30
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	MaxN,@object            # @MaxN
	.section	.rodata,"a",@progbits
	.globl	MaxN
	.p2align	2
MaxN:
	.long	100                     # 0x64
	.size	MaxN, 4

	.type	validCourse,@object     # @validCourse
	.bss
	.globl	validCourse
	.p2align	4
validCourse:
	.zero	4000
	.size	validCourse, 4000

	.type	crediet,@object         # @crediet
	.globl	crediet
	.p2align	4
crediet:
	.zero	4000
	.size	crediet, 4000

	.type	grade,@object           # @grade
	.globl	grade
	.p2align	4
grade:
	.zero	1000
	.size	grade, 1000

	.type	require,@object         # @require
	.globl	require
	.p2align	4
require:
	.zero	4000000
	.size	require, 4000000

	.type	pass,@object            # @pass
	.globl	pass
	.p2align	4
pass:
	.zero	4000
	.size	pass, 4000

	.type	n,@object               # @n
	.globl	n
	.p2align	2
n:
	.long	0                       # 0x0
	.size	n, 4

	.type	num,@object             # @num
	.globl	num
	.p2align	2
num:
	.long	0                       # 0x0
	.size	num, 4

	.type	cNum,@object            # @cNum
	.globl	cNum
	.p2align	2
cNum:
	.long	0                       # 0x0
	.size	cNum, 4

	.type	idx,@object             # @idx
	.globl	idx
	.p2align	2
idx:
	.long	0                       # 0x0
	.size	idx, 4

	.type	validIdx,@object        # @validIdx
	.globl	validIdx
	.p2align	2
validIdx:
	.long	0                       # 0x0
	.size	validIdx, 4

	.type	c,@object               # @c
	.globl	c
c:
	.byte	0                       # 0x0
	.size	c, 1

	.type	ch,@object              # @ch
	.globl	ch
ch:
	.byte	0                       # 0x0
	.size	ch, 1

	.type	binary,@object          # @binary
	.globl	binary
binary:
	.byte	0                       # 0x0
	.size	binary, 1

	.type	totalCrediet,@object    # @totalCrediet
	.globl	totalCrediet
	.p2align	2
totalCrediet:
	.long	0                       # 0x0
	.size	totalCrediet, 4

	.type	attemptCrediet,@object  # @attemptCrediet
	.globl	attemptCrediet
	.p2align	2
attemptCrediet:
	.long	0                       # 0x0
	.size	attemptCrediet, 4

	.type	getCrediet,@object      # @getCrediet
	.globl	getCrediet
	.p2align	2
getCrediet:
	.long	0                       # 0x0
	.size	getCrediet, 4

	.type	remainCredite,@object   # @remainCredite
	.globl	remainCredite
	.p2align	2
remainCredite:
	.long	0                       # 0x0
	.size	remainCredite, 4

	.type	gradeTmp,@object        # @gradeTmp
	.globl	gradeTmp
	.p2align	2
gradeTmp:
	.long	0                       # 0x0
	.size	gradeTmp, 4

	.type	GPA,@object             # @GPA
	.globl	GPA
	.p2align	3
GPA:
	.quad	0                       # double 0
	.size	GPA, 8

	.type	flag,@object            # @flag
	.globl	flag
	.p2align	2
flag:
	.long	0                       # 0x0
	.size	flag, 4

	.type	ok,@object              # @ok
	.globl	ok
	.p2align	2
ok:
	.long	0                       # 0x0
	.size	ok, 4

	.type	gradeReal,@object       # @gradeReal
	.globl	gradeReal
	.p2align	3
gradeReal:
	.quad	0                       # double 0
	.size	gradeReal, 8

	.type	attemptCredietReal,@object # @attemptCredietReal
	.globl	attemptCredietReal
	.p2align	3
attemptCredietReal:
	.quad	0                       # double 0
	.size	attemptCredietReal, 8

	.type	.L__unnamed_1,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%c"
	.size	.L__unnamed_1, 3

	.type	.L__unnamed_4,@object   # @1
.L__unnamed_4:
	.asciz	"%d"
	.size	.L__unnamed_4, 3

	.type	.L__unnamed_5,@object   # @2
.L__unnamed_5:
	.asciz	"%c"
	.size	.L__unnamed_5, 3

	.type	.L__unnamed_6,@object   # @3
.L__unnamed_6:
	.asciz	"%d"
	.size	.L__unnamed_6, 3

	.type	.L__unnamed_7,@object   # @4
.L__unnamed_7:
	.asciz	"%c"
	.size	.L__unnamed_7, 3

	.type	.L__unnamed_8,@object   # @5
.L__unnamed_8:
	.asciz	"%c"
	.size	.L__unnamed_8, 3

	.type	.L__unnamed_9,@object   # @6
.L__unnamed_9:
	.asciz	"%d"
	.size	.L__unnamed_9, 3

	.type	.L__unnamed_10,@object  # @7
.L__unnamed_10:
	.asciz	"%c"
	.size	.L__unnamed_10, 3

	.type	.L__unnamed_11,@object  # @8
.L__unnamed_11:
	.asciz	"%c"
	.size	.L__unnamed_11, 3

	.type	.L__unnamed_12,@object  # @9
.L__unnamed_12:
	.asciz	"%c"
	.size	.L__unnamed_12, 3

	.type	.L__unnamed_13,@object  # @10
.L__unnamed_13:
	.asciz	"%c"
	.size	.L__unnamed_13, 3

	.type	.L__unnamed_2,@object   # @11
.L__unnamed_2:
	.asciz	"%c"
	.size	.L__unnamed_2, 3

	.type	.L__unnamed_3,@object   # @12
.L__unnamed_3:
	.asciz	"%c"
	.size	.L__unnamed_3, 3

	.type	.str,@object            # @.str
	.section	.rodata,"a",@progbits
	.globl	.str
.str:
	.asciz	"%c%c%c%c%c"
	.size	.str, 11

	.type	.str.1,@object          # @.str.1
	.globl	.str.1
.str.1:
	.asciz	"%.1lf\n"
	.size	.str.1, 7

	.type	.str.2,@object          # @.str.2
	.globl	.str.2
	.p2align	4
.str.2:
	.asciz	"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	.size	.str.2, 35

	.type	.str.3,@object          # @.str.3
	.globl	.str.3
.str.3:
	.asciz	"%d\n"
	.size	.str.3, 4

	.type	.str.4,@object          # @.str.4
	.globl	.str.4
	.p2align	4
.str.4:
	.asciz	"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	.size	.str.4, 35

	.type	.str.5,@object          # @.str.5
	.globl	.str.5
.str.5:
	.asciz	"%d\n"
	.size	.str.5, 4

	.type	.str.6,@object          # @.str.6
	.globl	.str.6
	.p2align	4
.str.6:
	.asciz	"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	.size	.str.6, 39

	.type	.str.7,@object          # @.str.7
	.globl	.str.7
.str.7:
	.asciz	"%d\n"
	.size	.str.7, 4

	.type	.str.8,@object          # @.str.8
	.globl	.str.8
.str.8:
	.asciz	"%c"
	.size	.str.8, 3

	.type	.str.9,@object          # @.str.9
	.globl	.str.9
	.p2align	4
.str.9:
	.asciz	"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	.size	.str.9, 59

	.type	.str.10,@object         # @.str.10
	.globl	.str.10
.str.10:
	.asciz	"%c"
	.size	.str.10, 3

	.type	.str.11,@object         # @.str.11
	.globl	.str.11
	.p2align	4
.str.11:
	.asciz	"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	.size	.str.11, 53

	.type	.str.12,@object         # @.str.12
	.globl	.str.12
.str.12:
	.asciz	"%c%c%c%d%c"
	.size	.str.12, 11

	.section	".note.GNU-stack","",@progbits
