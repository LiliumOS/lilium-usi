
#include <lilium-sci/process.h>
#include <lilium-sci/base.h>
#include <lilium-sci/types/uuid.h>

#include <stdlib.h>
#include <at_exit.h>
#include <stdatomic.h>

_Noreturn void _Exit(int c) {
    ExitProcess(c);
    __builtin_unreachable();
}

_Noreturn void exit(int c) {
    __cxa_finalize(NULL);
    _Exit(c);
}

// 466fbae6-be8b-5525-bd04-ee7153b74f55
#define ABORT_PROCESS ((struct Uuid){.minor = 0xbd04ee7153b74f55, .major = 0x466fbae6be8b5525})

_Noreturn void abort() {
    ExceptionStatusInfo info = {.except_code = ABORT_PROCESS};
    ExceptHandleSynchronous(&info, NULL);
    UnmanagedException(&info);
    __builtin_unreachable(); 
}

#define __AT_EXIT_BLOCK_COUNT (32)

typedef void __at_quick_exit(void);

static _Atomic(__ulong) __at_quick_exit_lock;

struct at_quick_exit_buffer {
    struct at_quick_exit_buffer* __prev;
    size_t __num_handles;
    __at_quick_exit* __handlers[__AT_EXIT_BLOCK_COUNT];
};

static struct at_quick_exit_buffer __local_quick_exit;

static struct at_quick_exit_buffer* __current_quick_exit = &__local_quick_exit;

int at_quick_exit(__at_quick_exit* __func) {
    while(atomic_exchange_explicit(&__at_quick_exit_lock, 1, memory_order_acquire) != 0){
         __builtin_ia32_pause(); // TODO: Something more efficient than a spinlock
    }
    if(__current_quick_exit->__num_handles == __AT_EXIT_BLOCK_COUNT){
        if(!malloc)
            return INSUFFICIENT_MEMORY;
        struct at_quick_exit_buffer* next = malloc(sizeof(struct at_quick_exit_buffer));
        if(!next)
            return INSUFFICIENT_MEMORY;
        *next = (struct at_quick_exit_buffer){.__prev = __current_quick_exit};
        __current_quick_exit = next;
    }
    __current_quick_exit->__handlers[__current_quick_exit->__num_handles++] = __func;

    atomic_store_explicit(&__at_quick_exit_lock, 0, memory_order_release);
}

_Noreturn void quick_exit(int __code) {
    while(atomic_exchange_explicit(&__at_quick_exit_lock, 1, memory_order_acquire) != 0){
         __builtin_ia32_pause(); // TODO: Something more efficient than a spinlock
    }
    
    for(struct at_quick_exit_buffer* __current = __current_quick_exit;__current; __current = __current->__prev) {
        for(size_t __idx = __current->__num_handles; __idx > 0; ) {
            __current->__handlers[--__idx]();
        }
    }
    _Exit(0);
}