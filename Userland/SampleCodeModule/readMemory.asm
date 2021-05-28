
extern printRegName
extern printHex
global printRegs
global readDirection

global readRAX
global readRBX
global readRCX
global readRDX
global readRBP
global readRSI
global readRDI
global readR8
global readR9
global readR10
global readR11
global readR12
global readR13
global readR14
global readR15

section .text

%macro popState 0
	pop rax
	pop rbx
	pop rcx
	pop rdx
	pop rbp
	pop rdi
	pop rsi
	pop r8
	pop r9
	pop r10
	pop r11
	pop r12
	pop r13
	pop r14
	pop r15
%endmacro

%macro pushState 0
	push r15
	push r14
	push r13
	push r12
	push r11
	push r10
	push r9
	push r8
	push rsi
	push rdi
	push rbp
	push rdx
	push rcx
	push rbx
	push rax
%endmacro

readDirection:
	xor rax,rax
	mov rax,[rdi] 
	ret

readRAX:
	ret
readRBX:
	mov rax,rbx
	ret
readRCX:
	mov rax,rcx
	ret

readRDX:
	mov rax,rdx
	ret
readRBP:
	mov rax,rbp
	ret
readRSI:
	mov rax,rsi
	ret

readRDI:
	mov rax,rdi
	ret
readR8:
	mov rax,r8
	ret
readR9:
	mov rax,r9
	ret

readR10:
	mov rax,r10
	ret

readR11:
	mov rax,r11
	ret

readR12:
	mov rax,r12
	ret

readR13:
	mov rax,r13
	ret

readR14:
	mov rax,r14
	ret

readR15:
	mov rax,r15
	ret
	
printRegs:
	pushState
	mov rbx, 0
	mov rcx, rsp
	add rcx, 8
	nextReg:
	mov rdi, rbx
	call printRegName
	mov rdi, [rcx]
	call printHex
	add rcx, 8
	inc rbx
	cmp rbx, 15
	jne nextReg
	popState
	ret