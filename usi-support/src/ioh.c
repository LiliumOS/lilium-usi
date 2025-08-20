
#include <io-handles.h>
#include <lilium-sci/io/hdl.h>

_Thread_local IOHandle* __handle __HANDLE_IO_STDIN __attribute__((tls_model("initial-exec")));
_Thread_local IOHandle* __handle __HANDLE_IO_STDOUT __attribute__((tls_model("initial-exec")));
_Thread_local IOHandle* __handle __HANDLE_IO_STDERR __attribute__((tls_model("initial-exec")));