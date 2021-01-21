; Variables
; r10 = begin + length - 1
; r13 = swap_count
; r11 = index ptr
; r14d and r15d = compared values.
; rdi = begin
; rsi = length
global bubble_sort_asm
bubble_sort_asm: ; (int*, size_t)
    lea r10, [rdi+(rsi-1)*4] ; last (end-1)
    test rsi, rsi ; count zero, bye
    je .bubble_end
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
    add r11, 4
    jmp .bubble_iteration_begin
.bubble_ending_loop:
    test  r13, r13 ; no swap means sorted
    je .bubble_end
    jmp .bubble_loop_begin
.bubble_end:
    ret

global insertion_sort_asm
insertion_sort_asm:
end_insertion:
    ret