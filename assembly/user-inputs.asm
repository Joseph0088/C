                                                                                                                                                                                                           section .data
    userMsg db 'Please enter a number : ', 10
    lenUserMsg equ $ - userMsg
    dispMsg db 'You have entered :', 10
    lenDispMsg equ $ - dispMsg

section .bss
    num resb 6

section .text
    global _start

_start:
    ; Print user message
    mov eax, 4
    mov ebx, 1
    mov ecx, userMsg
    mov edx, lenUserMsg
    int 80h

    ; Read input
    mov eax, 3
    mov ebx, 2
    mov ecx, num
    mov edx, 6
    int 80h

    ; Print You have entered :
    mov eax, 4
    mov ebx, 1
    mov ecx, dispMsg
    mov edx, lenDispMsg
    int 80h

    ; Print the number
    mov eax, 4
    mov ebx, 1
    mov ecx, num
    mov edx, 6
    int 80h

    ; Exit
    mov eax, 1
    xor ebx, ebx
    int 80h

