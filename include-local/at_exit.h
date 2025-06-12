#pragma once

typedef void (*__cxa_at_exit_func)(void*);

int __cxa_at_exit(__cxa_at_exit_func __func, void *__udata, void *__dso) __attribute__((weak));

void __cxa_finalize(void* __dso) __attribute__((weak));