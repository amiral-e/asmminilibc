bits 64
section .text
global strrchr

strrchr:
	xor rax, rax

loop:
	cmp BYTE [rdi], sil
	je found
	cmp BYTE [rdi], 0
	je end
	inc rdi
	jmp loop

found:
	mov rax, rdi
	cmp BYTE [rdi], 0
	je end
	inc rdi
	jmp loop

end:
	ret