;[BITS 64]
;
;SECTION .data
;a: dq 0
;b: dq 0
;
;SECTION PAGE
;global Int07f
;
;Int07f:
;    swapgs
;    mov [a], rax
;    mov [b], rbx
;
;    xor rax, rax
;    xor rbx, rbx
;
;    mov rax, [rsp + 8]  ;指令地址
;    mov byte bl, [rax]  ;待减的值
;    sub rax, rbx
;    mov [rsp + 8], rax
;
;    mov rbx, [b]
;    mov rax, [a]
;	swapgs
;	iretq

option casemap:none

.data
a dq 0
b dq 0

.code

Int0f proc
	swapgs
    mov [a], rax
    mov [b], rbx

    xor rax, rax
    xor rbx, rbx

    int 3

    mov rax, [rsp]  ;指令地址
    mov byte ptr bl, [rax]  ;待减的值
    sub rax, rbx
    mov [rsp], rax

    mov rbx, [b]
    mov rax, [a]
	swapgs
	iretq
Int0f endp

end