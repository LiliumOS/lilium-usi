#pragma once

int __cxa_at_exit(void (*__func)(void *), void *__udata, void *__dso) __attribute__((weak));

void __cxa_finalize(void* __dso) __attribute__((weak));