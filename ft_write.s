section .text
	global _ft_write
	extern ___error

_ft_write:
	mov		rax, 0x2000004
	syscall
	jc		err
	ret

err:
	push	rax ;сохраним значение ошибки в стек
	call	___error
	pop		rcx ;вытащим значение ошибки в rcs
	mov		[rax], rcx
	mov		rax, -1
	ret