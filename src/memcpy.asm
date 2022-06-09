bits 64
section .text
global memcpy

memcpy:
	mov rax, rdi
	xor rcx, rcx

loop:
	cmp rcx, rdx
	je end
	mov	r8b, BYTE [rsi + rcx]
	mov	BYTE [rax + rcx], r8b
	inc rcx
	jmp loop

end:
	ret