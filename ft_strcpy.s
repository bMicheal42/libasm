section .text
			global _ft_strcpy

_ft_strcpy:
	xor		rdx, rdx
	cmp		rsi, 0
	je		end
	jmp		copy

copy:
	mov		al, BYTE[rsi + rdx]
	mov		BYTE[rdi + rdx], al
	cmp		al, 0
	je		end
	inc		rdx
	jmp		copy

end:
	mov		BYTE[rdi + rdx], 0
	mov		rax, rdi
	ret
