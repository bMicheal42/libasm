section .text
			global _ft_strcmp

_ft_strcmp:
	xor		rdx, rdx
	cmp		rdi, 0
	jz		empty_str
	cmp		rsi, 0
	jz		empty_str
	jmp		main_part

empty_str:
	cmp		rdi, rsi
	ja		str1_bigger
	jb		str2_bigger
	jmp		str1_same_str2

end_of_str:
	mov		al, [rsi + rdx]
	cmp		BYTE[rdi + rdx] , al
	ja		str1_bigger
	jb		str2_bigger
	jmp		str1_same_str2

main_part:
	cmp		BYTE[rdi + rdx], 0
	je		end_of_str
	cmp		BYTE[rsi + rdx], 0
	je		end_of_str
	mov		al, [rsi + rdx]
	cmp		BYTE[rdi + rdx], al
	jnz		end_of_str
	inc		rdx
	jmp		main_part

str1_bigger:
	mov		rax, 1
	ret

str2_bigger:
	mov		rax, -1
	ret

str1_same_str2:
	mov		rax, 0
	ret
