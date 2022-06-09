bits 64
section .text
global memmove

memmove:
	xor rcx, rcx
	cmp rdx, 0
	je end

stack_w:
	cmp rcx, rdx
	je stack_r
	movsx rbx, BYTE [rsi + rcx]
	push rbx
	inc rcx
	jmp stack_w

stack_r:
	dec rcx
	pop rbx
	mov BYTE [rdi + rcx], bl
	cmp rcx, 0
	je end
	jmp stack_r

end:
	mov rax, rdi
	ret