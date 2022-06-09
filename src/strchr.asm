bits 64
section .text
global strchr

strchr:
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
	ret

end:
	ret