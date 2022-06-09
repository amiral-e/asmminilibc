bits 64
section .text
global strcmp

strcmp:
	xor rcx, rcx
	xor r8, r8
	xor rax, rax

loop:
	mov	r8b, BYTE [rsi + rcx]
	mov	al, BYTE [rdi + rcx]
	cmp r8, 0
	je end
	cmp rax, 0
	je end
	cmp r8b, al
	jne end
	inc rcx
	jmp loop

end:
	sub	al, r8b
	movsx rax, al
	ret