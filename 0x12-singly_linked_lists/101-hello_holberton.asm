section .data
	msg db 'Hello, Holberton', 0   ; Message to print with null terminator

section .text
	global main
	extern printf

main:
	; Setup the stack frame
	push rbp
	mov rbp, rsp

	; Call printf
	lea rdi, [rel msg]   ; Load effective address of msg into rdi
	xor eax, eax         ; Clear eax register (no floating-point arguments)
	call printf          ; Call printf

	; Exit the program
	mov rsp, rbp
	pop rbp
	ret
