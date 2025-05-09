
#include <lilium-sci/types.h>
#include <elf.h>
#include <helpers.h>
#include <at_exit.h>
#include <lilium-sci/syscall.h>
#include <syscall.h>

_Thread_local Handle* __handle __STDIN_HANDLE;

_Noreturn void __usi_setup_prg(long argc, char** argv, char** envp, struct __Elf_AuxEnt* auxv, int (main)(int, char**, char**), void (*fini)()) {
    if(__cxa_at_exit)
        __cxa_at_exit(fini, NULL,NULL);
    int res = main(argc, argv, envp);
    if(__cxa_finalize)
        __cxa_finalize(NULL);
    DO_SYSCALL(__LILIUM_SYSNO(3, 0), res);
    __builtin_trap();
}