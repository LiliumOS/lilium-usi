
#include <lilium-sci/types.h>
#include <elf.h>
#include <helpers.h>
#include <at_exit.h>
#include <lilium-sci/syscall.h>
#include <syscall.h>

_Thread_local Handle* __handle __STDIN_HANDLE;
_Thread_local Handle* __handle __STDOUT_HANDLE;
_Thread_local Handle* __handle __STDERR_HANDLE;

_Thread_local struct {
    Handle* __handle * __arr;
    unsigned long __len;
} __init_handles;

union __aux_val __auxv[126];

_Noreturn void __usi_setup_prg(long argc, char** argv, char** envp, struct __Elf_AuxEnt* auxv, int (main)(int, char**, char**), void (*fini)()) {
    if(__cxa_at_exit)
        __cxa_at_exit(fini, NULL,NULL);
    
    for(;auxv->__aux_type;auxv++){
        if(auxv->__aux_type!=1)
            __auxv[auxv->__aux_type-2] = auxv->__aux_val;
    }

    if(__auxv[AT_LILIUM_INIT_HANDLES].__aux_ptr){
        __init_handles.__arr = __auxv[AT_LILIUM_INIT_HANDLES].__aux_ptr;
        __init_handles.__len = __auxv[AT_LILIUM_INIT_HANDLES_LEN].__aux_val;
    }

    if(__init_handles.__len >= 1) {
        __STDIN_HANDLE = __init_handles.__arr[0];
    }
    if(__init_handles.__len >= 2) {
        __STDOUT_HANDLE = __init_handles.__arr[1];
    }
    if(__init_handles.__len >= 3) {
        __STDERR_HANDLE = __init_handles.__arr[2];
    }

    int res = main(argc, argv, envp);
    if(__cxa_finalize)
        __cxa_finalize(NULL);
    DO_SYSCALL(__LILIUM_SYSNO(3, 0), res);
    __builtin_trap();
}