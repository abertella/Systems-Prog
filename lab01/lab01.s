	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	leaq	L_.str(%rip), %rax
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.1(%rip), %rdi
	leaq	-20(%rbp), %rsi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	cmpl	$94, -20(%rbp)
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	jle	LBB0_2
## %bb.1:
	leaq	L_.str.2(%rip), %rdi
	xorl	%eax, %eax
	movb	%al, %cl
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	movb	%cl, %al
	callq	_printf
	movl	-32(%rbp), %edi         ## 4-byte Reload
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	callq	_exit
LBB0_2:
	movl	-20(%rbp), %edi
	callq	_fib
	leaq	L_.str.3(%rip), %rdi
	movl	-20(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	-20(%rbp), %edi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	callq	_print_array
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function fib
_fib:                                   ## @fib
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	_fib_arr@GOTPCREL(%rip), %rax
	movl	%edi, -4(%rbp)
	movq	$0, (%rax)
	movq	$1, 8(%rax)
	movl	$2, -8(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jge	LBB1_4
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movq	_fib_arr@GOTPCREL(%rip), %rax
	movl	-8(%rbp), %ecx
	subl	$2, %ecx
	movslq	%ecx, %rdx
	movq	(%rax,%rdx,8), %rdx
	movl	-8(%rbp), %ecx
	subl	$1, %ecx
	movslq	%ecx, %rsi
	addq	(%rax,%rsi,8), %rdx
	movslq	-8(%rbp), %rsi
	movq	%rdx, (%rax,%rsi,8)
## %bb.3:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB1_1
LBB1_4:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function print_array
_print_array:                           ## @print_array
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	$0, -8(%rbp)
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jge	LBB2_7
## %bb.2:                               ##   in Loop: Header=BB2_1 Depth=1
	movl	-8(%rbp), %eax
	movl	-4(%rbp), %ecx
	subl	$1, %ecx
	cmpl	%ecx, %eax
	jne	LBB2_4
## %bb.3:                               ##   in Loop: Header=BB2_1 Depth=1
	leaq	L_.str.4(%rip), %rdi
	movq	_fib_arr@GOTPCREL(%rip), %rax
	movslq	-8(%rbp), %rcx
	movq	(%rax,%rcx,8), %rsi
	movb	$0, %al
	callq	_printf
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	jmp	LBB2_5
LBB2_4:                                 ##   in Loop: Header=BB2_1 Depth=1
	leaq	L_.str.5(%rip), %rdi
	movq	_fib_arr@GOTPCREL(%rip), %rax
	movslq	-8(%rbp), %rcx
	movq	(%rax,%rcx,8), %rsi
	movb	$0, %al
	callq	_printf
	movl	%eax, -16(%rbp)         ## 4-byte Spill
LBB2_5:                                 ##   in Loop: Header=BB2_1 Depth=1
	jmp	LBB2_6
LBB2_6:                                 ##   in Loop: Header=BB2_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB2_1
LBB2_7:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"n = "

L_.str.1:                               ## @.str.1
	.asciz	"%d"

L_.str.2:                               ## @.str.2
	.asciz	"This number is too big to represent in 64 bits! Exiting...\n"

L_.str.3:                               ## @.str.3
	.asciz	"The first %d Fibonacci number(s) are:\n"

	.comm	_fib_arr,800,4          ## @fib_arr
L_.str.4:                               ## @.str.4
	.asciz	"%llu\n"

L_.str.5:                               ## @.str.5
	.asciz	"%llu, "


.subsections_via_symbols
