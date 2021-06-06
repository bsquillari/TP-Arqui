
extern printRegName
extern printHex

global readDirection
global printRegs

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

%macro pushState 0
	push rax
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro

%macro popState 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro

readDirection:
	xor rax,rax
	mov rax,[rdi] 
	ret


printRegs:
	pushState
	mov rbx, 0
	mov rcx, rsp
	add rcx, 8
	nextReg:
	push rcx
	mov rdi, rbx
	call printRegName
	pop rcx
	push rcx
	mov rdi, [rcx]
	call printHex
	pop rcx
	add rcx, 8
	inc rbx
	cmp rbx, 15
	jne nextReg
	popState
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
	
