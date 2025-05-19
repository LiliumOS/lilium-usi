
#include <lilium-sci/types/int.h>
#include <stdatomic.h>
#include <helpers.h>

#define __AT_EXIT_BLOCK_COUNT (32)

struct __at_exit_block{
    struct __at_exit_block* prev;
    __ulong last_ent;
    struct __at_exit_ent{void* __dso; void* __key; void (*__at_exit_hdl)(void*);} __block[__AT_EXIT_BLOCK_COUNT];
};

void* malloc(__ulong) __attribute__((weak));

void* memset(void* restrict dest, int src, __ulong len);

static struct __at_exit_block __local_at_exit;

static struct __at_exit_block* __current = &__local_at_exit;

static _Atomic(__ulong) __cxa_at_exit_lock;

int __cxa_at_exit(void (*func)(void*), void* udata, void* dso) {
    int __step;
    while(atomic_exchange_explicit(&__cxa_at_exit_lock, 1, memory_order_acquire) != 0){
         __builtin_ia32_pause(); // TODO: Something more efficient than a spinlock
    }

    if (__current->last_ent == __AT_EXIT_BLOCK_COUNT) {
        if(malloc){
            struct __at_exit_block* next_block = malloc(sizeof(struct __at_exit_block));
            if (!next_block)
                return INSUFFICIENT_MEMORY;
            memset(next_block, 0, sizeof(struct __at_exit_block));
            next_block->prev = __current;
            __current = next_block;
        } else {
            return INSUFFICIENT_MEMORY;
        }
    }

    __current->__block[__current->last_ent++] = (struct __at_exit_ent){dso, udata, func};

    atomic_store_explicit(&__cxa_at_exit_lock, 0, memory_order_release);
    return 0;
}

int atexit(void(*func)(void)) {
    __cxa_at_exit((void(*)(void*))func, NULL, NULL);
} 

void __cxa_finalize(void* dso) {
    while(atomic_exchange_explicit(&__cxa_at_exit_lock, 1, memory_order_acquire) != 0){
         __builtin_ia32_pause(); // TODO: Something more efficient than a spinlock
    }
    for(struct __at_exit_block* addr = __current; addr ; addr = addr->prev) {
        for (__ulong n = addr->last_ent; n > 0; n--){
            struct __at_exit_ent* ent = &addr->__block[n-1];
            if(!dso || ent->__dso == dso)
                ent->__at_exit_hdl(ent->__key);
        }
    }
    atomic_store_explicit(&__cxa_at_exit_lock, 0, memory_order_release);
}