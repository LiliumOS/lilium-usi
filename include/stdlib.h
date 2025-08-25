#ifndef __LILIUM_USI_STDLIB_H_2025_05_19
#define __LILIUM_USI_STDLIB_H_2025_05_19

#include <bits/lang-version.h>

#include <stddef.h>

#include <bits/noreturn.h>
#include <bits/has-builtin.h>

__LILIUM_USI_BEGIN_CDECLS

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

void *malloc(size_t __size);
void free(void *__mem);

#include <bits/div.h>

__LILIUM_USI_DEF_DIV(, int);
__LILIUM_USI_DEF_DIV(l, long);

#if __USE_C99 || __USE_CXX11
__LILIUM_USI_DEF_DIV(ll, long long);
#endif

#define RAND_MAX __INT_MAX__

int rand(void);

void srand(unsigned int);

__LILIUM_USI_END_CDECLS

#endif /* __LILIUM_USI_STDLIB_H_2025_05_19 */