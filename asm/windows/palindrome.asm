global is_palindrome_asm
is_palindrome_asm: ; (char*, size_t)
    test rdx, rdx
    je .return_true
    lea rax, [rcx+rdx-1]
.loop:
    mov r8b, BYTE [rax]
    cmp BYTE [rcx], r8b
    jne .return_false
.end_of_loop:
    inc rcx
    dec rax
    cmp rcx, rax
    jge .return_true
    jmp .loop
.return_false:
    xor eax, eax
    ret
.return_true:
    mov eax, 1
    ret