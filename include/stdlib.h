#ifndef __LILIUM_USI_STDLIB_H_2025_05_19
#define __LILIUM_USI_STDLIB_H_2025_05_19

#include <bits/lang-version.h>

#include <stddef.h>

#include <bits/noreturn.h>
#include <bits/has-builtin.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

__LILIUM_NORETURN__ void abort(void);
__LILIUM_NORETURN__ void exit(int __code);
#if __USE_CXX98 || __USE_C99
__LILIUM_NORETURN__ void _Exit(int __code);
#endif
#if __USE_CXX11 || __USE_C11
__LILIUM_NORETURN__ void quick_exit(int __code);
#endif

int atexit(void (*__func)(void));

#if __USE_CXX11 || __USE_C11
int at_quick_exit(void (*__func)(void));
#endif

void* malloc(size_t __size) __attribute__((weak));
void free(void* __mem) __attribute__((weak));

#endif /* __LILIUM_USI_STDLIB_H_2025_05_19 */