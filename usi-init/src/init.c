
#include <lilium-sci/types.h>
#include <elf.h>
#include <helpers.h>
#include <at_exit.h>
#include <lilium-sci/syscall.h>
#include <syscall.h>
#include <io-handles.h>

_Thread_local IOHandle* __handle __HANDLE_IO_STDIN __attribute__((tls_model("initial-exec")));
_Thread_local IOHandle* __handle __HANDLE_IO_STDOUT __attribute__((tls_model("initial-exec")));
_Thread_local IOHandle* __handle __HANDLE_IO_STDERR __attribute__((tls_model("initial-exec")));

_Thread_local struct {
    Handle* __handle * __arr;
    unsigned long __len;
} __init_handles;

union __aux_val __auxv[126];

_Noreturn void __usi_setup_prg(long argc, char** argv, char** envp, struct __Elf_AuxEnt* auxv, int (main)(int, char**, char**), void (*fini)()) {
    if(__builtin_expect(__cxa_at_exit != NULL, 1))
        __cxa_at_exit(fini, NULL,NULL);
    
    for(;auxv->__aux_type;auxv++){
        if(auxv->__aux_type!=1)
            __auxv[auxv->__aux_type-2] = auxv->__aux_val;
    }

    if(__builtin_expect(__auxv[AT_LILIUM_INIT_HANDLES - 2].__aux_ptr != NULL, 1)){
        __init_handles.__arr = __auxv[AT_LILIUM_INIT_HANDLES - 2].__aux_ptr;
        __init_handles.__len = __auxv[AT_LILIUM_INIT_HANDLES_LEN - 2].__aux_val;
    }

    if(__builtin_expect(__init_handles.__len >= 1, 1)) {
        __HANDLE_IO_STDIN = (IOHandle*)__init_handles.__arr[0];
    }
    if(__builtin_expect(__init_handles.__len >= 2, 1)) {
        __HANDLE_IO_STDOUT = (IOHandle*)__init_handles.__arr[1];
    }
    if(__builtin_expect(__init_handles.__len >= 3, 1)) {
        __HANDLE_IO_STDERR = (IOHandle*)__init_handles.__arr[2];
    }

    int res = main(argc, argv, envp);
    if(__builtin_expect(__cxa_finalize != NULL, 1))
        __cxa_finalize(NULL);
    DO_SYSCALL(__LILIUM_SYSNO(3, 0), res);
    __builtin_trap();
}