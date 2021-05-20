

GLOBAL _keyHandler
GLOBAL pruebaInt80		;;;;;;;;;;;;;;

SECTION .text

_keyHandler:
    xor rax,rax
	in al,60h
	ret

pruebaInt80:		;;;;;;;;;;;;;;;	
	mov rax, 1
	mov rdi, 0
	mov rsi, buffer
	mov rdx, 20
	int 80h
	mov rax, buffer
SECTION .bss
	buffer db 20