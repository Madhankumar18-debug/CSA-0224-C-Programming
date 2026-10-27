	.file	"main.c"
	.text
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rdx, -40(%rbp)
	movq	%r8, -32(%rbp)
	movq	%r9, -24(%rbp)
	movq	%rcx, -48(%rbp)
	leaq	-40(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdx
	movq	-48(%rbp), %rcx
	call	__mingw_vprintf
	movl	%eax, %ebx
	movl	%ebx, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "Grama Jyothi Electricity Billing System\0"
.LC1:
	.ascii "=== %s ===\12\0"
.LC2:
	.ascii "Version 1.0 (C11 Strict)\0"
.LC3:
	.ascii "Release: %s\12\12\0"
	.align 8
.LC4:
	.ascii "Compilation stages demonstrated:\12\0"
	.align 8
.LC5:
	.ascii "  Stage 1 (Preprocessing): gcc -E main.c -o main.i\12\0"
	.align 8
.LC6:
	.ascii "  Stage 2 (Compilation):   gcc -S main.c -o main.s\12\0"
	.align 8
.LC7:
	.ascii "  Stage 3 (Assembly):      gcc -c main.c -o main.o\12\0"
	.align 8
.LC8:
	.ascii "  Stage 4 (Linking):       gcc main.o -o billing.exe\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	printf
	leaq	.LC2(%rip), %rdx
	leaq	.LC3(%rip), %rcx
	call	printf
	leaq	.LC4(%rip), %rcx
	call	printf
	leaq	.LC5(%rip), %rcx
	call	printf
	leaq	.LC6(%rip), %rcx
	call	printf
	leaq	.LC7(%rip), %rcx
	call	printf
	leaq	.LC8(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	__mingw_vprintf;	.scl	2;	.type	32;	.endef
