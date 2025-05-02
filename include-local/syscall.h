#pragma once

#include <helpers.h>
#include <asm.h>

#ifdef __x86_64__

#define SYSNO(arg)                        \
    register long __sysno __asm__("rax"); \
    __sysno = arg;

#define SYSCALL_INSTR "syscall"

#define RESULT_REGISTER "rax"

#define SYSARGS(arg1, arg2, arg3, arg4, arg5, arg6, ...)    \
    register __typeof__(arg1) __arg1 __asm__("rdi") = arg1; \
    register __typeof__(arg2) __arg2 __asm__("rsi") = arg2; \
    register __typeof__(arg3) __arg3 __asm__("rdx") = arg3; \
    register __typeof__(arg4) __arg4 __asm__("r10") = arg4; \
    register __typeof__(arg5) __arg5 __asm__("r8") = arg5;  \
    register __typeof__(arg6) __arg6 __asm__("r9") = arg6;


#define syscall_wrapper(__retty, __name, ...)\
     __attribute__((__naked__)) __retty __name(__VA_ARGS__)\
    {\
        __intel_asm_volatile("mov rax, " STRINGIFY(__SYS_ ## __name) "\nmov r10, rcx\n syscall\n ret");\
    }

#endif

#define DO_SYSCALL(sysno, ...)\
    ({                                                                     \
    SYSNO(sysno);                                                          \
    SYSARGS(__VA_ARGS__, 0, 0, 0, 0, 0, 0);                                \
    register long __res __asm__(RESULT_REGISTER);                          \
    __intel_asm_volatile(SYSCALL_INSTR, "=r"(__res) : "0"(__sysno), "r"(__arg1), "r"(__arg2), "r"(__arg3), "r"(__arg4), "r"(__arg5), "r"(__arg6)); \
    __res;                                                                 \
})


