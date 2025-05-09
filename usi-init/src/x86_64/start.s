.intel_syntax noprefix

.global _start

_start:
    test eax, 1
    je 2f
    pop rdi
    lea rsi, [rsp]
    mov rcx, rbx
    mov r9, rdx
    mov rdx, r12
    mov r8, qword ptr [main@GOTPCREL+rip]
    call qword ptr [__usi_setup_prg@GOTPCREL+rip]
    2:
    ud2