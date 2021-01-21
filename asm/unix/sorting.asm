; Variables
; r10 = begin + length - 1
; r13 = swap_count
; r11 = index ptr
; r14d and r15d = compared values.
global bubble_sort_asm
bubble_sort_asm: ; (int*, size_t)
    lea r10, [rdi+rsi-1] ; last
    test rsi, rsi ; count zero, bye
    je .end_bubble
.bubble_loop_begin:
    xor r13, r13 ; swap_count set to 0
    mov r11, rdi ; begin index ptr
.bubble_iteration_begin:
    cmp r11, r10 ; if we are at the end of the array
    je .bubble_ending_loop
    mov r14d, dword [r11]
    mov r15d, dword [r11+4]
    cmp r14d, r15d
    jle .bubble_iteration_end
    ; swapping
    mov dword [r11], r15d
    mov dword [r11+4], r14d
    inc r13 ; update swap_count
.bubble_iteration_end:
    inc r11
    jmp .bubble_iteration_begin
.bubble_ending_loop:
    test  r13, r13 ; no swap means sorted
    je .end_bubble
    jmp .bubble_loop_begin
.end_bubble:
    ret

global insertion_sort_asm
insertion_sort_asm:
end_insertion:
    ret