global is_palindrome_asm
is_palindrome_asm: ; (char*, size_t)
    test rsi, rsi
    je .return_true
    lea rax, [rdi+rsi-1]
.loop:
    mov dl, BYTE [rax]
    cmp BYTE [rdi], dl
    jne .return_false
.end_of_loop:
    inc rdi
    dec rax
    cmp rdi, rax
    jge .return_true
    jmp .loop
.return_false:
    xor eax, eax
    ret
.return_true:
    mov eax, 1
    ret