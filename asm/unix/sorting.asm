; Variables
; r10 = begin + length - 1 -> rdx
; rax = swap_count
; r11 = index ptr -> rcx
; r14d and r15d = compared values. - r8d, r9d
; rdi = begin
; rsi = length
global bubble_sort_asm
bubble_sort_asm: ; (int*, size_t)
    ;push rax
    lea rdx, [rdi+(rsi-1)*4] ; back (end-1)
    test rsi, rsi ; count zero, bye
    je .bubble_end
.bubble_loop_begin:
    xor rax, rax ; swap_count set to 0
    mov rcx, rdi ; begin index ptr
.bubble_iteration_begin:
    cmp rcx, rdx ; if we are at the back of the array
    je .bubble_ending_loop
    mov r8d, DWORD [rcx]
    mov r9d, DWORD [rcx+4]
    cmp r8d, r9d
    jle .bubble_iteration_end
    ; swapping
    mov DWORD [rcx], r9d
    mov DWORD [rcx+4], r8d
    inc rax ; update swap_count
.bubble_iteration_end:
    add rcx, 4
    jmp .bubble_iteration_begin
.bubble_ending_loop:
    test  rax, rax ; no swap means sorted
    je .bubble_end
    jmp .bubble_loop_begin
.bubble_end:
    xor rax, rax
    ;pop rax
    ret

; r10 = begin + length - 1
; rdi = begin
; rsi = length
; r11 = current index
; r12 = ptr going back
global insertion_sort_asm
insertion_sort_asm:
     push r10
    push r11
    push r14
    push r15
    push r12
    lea r10, [rdi+rsi*4] ; end
    test rsi, rsi ; count zero, bye
    je .insertion_end
    lea r11, [rdi+4]
.insertion_loop_begin:
    cmp r11, r10
    je .insertion_end
    mov r12, r11
.insertion_iteration_loop:
    cmp r12, rdi
    je .insertion_loop_end
    mov r8d, dword [r12-4]
    mov r9d, dword [r12]
    cmp r8d, r9d
    jle .insertion_loop_end
    mov dword [r12-4], r9d
    mov dword [r12], r8d
    sub r12, 4
    jmp .insertion_iteration_loop
.insertion_loop_end:
    add r11, 4
    jmp .insertion_loop_begin
.insertion_end:
    xor rax, rax
    pop r12
    pop r15
    pop r14
    pop r11
    pop r10
    ret