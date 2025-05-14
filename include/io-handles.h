#ifndef __LILIUM_USI_IO_HANDLES_H_2025_05_13_23_51_44
#define __LILIUM_USI_IO_HANDLES_H_2025_05_13_23_51_44

#include <lilium-sci/io/hdl.h>
#include <bits/thread-local.h>

#if __LILIUM_USI_HAS_THREAD_LOCAL
extern __LILIUM_USI_THREAD_LOCAL IOHandle *__handle __HANDLE_IO_STDIN;
extern __LILIUM_USI_THREAD_LOCAL IOHandle *__handle __HANDLE_IO_STDOUT;
extern __LILIUM_USI_THREAD_LOCAL IOHandle *__handle __HANDLE_IO_STDERR;
#endif

/// Returns a pointer to the stdin handle for the current thread.
/// The returned pointer is the same as the address of `__HANDLE_IO_STDIN`
IOHandle *__handle *__get_io_stdin();
/// Returns a pointer to the stdout handle for the current thread.
/// The returned pointer is the same as the address of `__HANDLE_IO_STDOUT`
IOHandle *__handle *__get_io_stdout();
/// Returns a pointer to the stderr handle for the current thread.
/// The returned pointer is the same as the address of `__HANDLE_IO_STDERR`
IOHandle *__handle *__get_io_stderr();

#endif /* __LILIUM_USI_IO_HANDLES_H_2025_05_13_23_51_44 */