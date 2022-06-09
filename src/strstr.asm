bits 64
section .text
global strstr

strstr:
	xor rcx, rcx
	xor rax, rax

loop:
	cmp BYTE [rsi + rcx], 0
	je end
	mov al, BYTE [rdi + rcx]
	cmp al, 0
	je null_end
	cmp al, BYTE [rsi + rcx]
	jne not_found
	cmp al, BYTE [rsi + rcx]
	je found

not_found:
	inc rdi
	xor rcx, rcx
	jmp loop

found:
	inc rcx
	jmp loop

null_end:
	ret

end:
	mov rax, rdi
	ret