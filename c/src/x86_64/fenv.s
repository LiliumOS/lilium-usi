.text 
fegetenv:
    stmxcsr dword ptr [rdi]
    xor eax, eax
    ret
    fegetenv.__end:

.type fegetenv, STT_FUNC
.size fegetenv, fegetenv.__end-fegetenv

fesetenv:
    ldmxcsr dword ptr [rdi]
    xor eax, eax
    ret
    fesetenv.__end:

.type fesetenv, STT_FUNC
.size fesetenv, fegetenv.__end-fegetenv

feholdexcept:
    stmxcsr dword ptr [rdi]
    mov eax, dword ptr [rdi]
    or eax, 0x1F80
    push rax
    ldmxcsr dword ptr [rsp]
    pop rax
    xor eax, eax
    ret
    feholdexcept.__end:
.type feholdexcept, STT_FUNC
.size feholdexcept, feholdexcept.__end-feholdexcept

feupdateenv:
    push rax
    stmxcsr dword ptr [rsp]
    pop rax
    and eax, 0x3F
    or eax, dword ptr [rdi]
    push rax
    ldmxcsr dword ptr [rsp]
    
    xor eax, eax
    ret
    feupdateenv.__end:
.type feupdateenv, STT_FUNC
.size feupdateenv, feupdateenv.__end-feupdateenv

.section .rodata
.align 4
__fe_default_env:
    .long 0x1F80

.type __fe_default_env, STT_OBJECT
.size __fe_default_env, 4

.global fegetenv, fesetenv, feholdexcept, feupdateenv, __fe_default_env
