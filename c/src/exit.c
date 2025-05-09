
#include <lilium-sci/process.h>

_Noreturn void _Exit(int c) {
    ExitProcess(c);
    __builtin_unreachable();
}
