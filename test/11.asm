[BITS 64]

SECTION .text
global testWinMain
global aaa

aaa:
l0:
	ret
l1:
	mov rax, 1
int 0fh
db l2 - l0 -1
l2:
	mov rax, 2
int 0fh
db l3 - l1 - 1
l3:
testWinMain:
	mov rax, 3
int 0fh
db l4 - l2 -1
l4:
int 0fh
ret
