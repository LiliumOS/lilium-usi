#pragma once

#define __intel_asm(strings, ...) \
    __asm__(strings : __VA_ARGS__)

#define __intel_asm_volatile(strings, ...) \
    __asm__ volatile(strings : __VA_ARGS__)
