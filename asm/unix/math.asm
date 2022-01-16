section .rodata
pi dd 3.141592653589793238462

section .text
global circle_area_asm
circle_area_asm:
    mulss xmm0, xmm0
    movss xmm1, dword [rel pi]
    mulss xmm0, xmm1
    ret