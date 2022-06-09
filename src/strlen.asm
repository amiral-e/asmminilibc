bits 64
section .text
global strlen

strlen:
	xor rax, rax

loop:
	cmp BYTE [rdi], 0
	je end
	inc rdi
	inc rax
	jmp loop

end:
	ret