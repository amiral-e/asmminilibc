bits 64
section .text
global memset

memset:
	mov rax, rdi
	xor rcx, rcx

loop:
	cmp rcx, rdx
	je end
	mov	BYTE [rax + rcx], sil
	inc rcx
	jmp loop

end:
	ret