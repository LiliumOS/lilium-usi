#include <lilium-sci/base.h>
#include <syscall.h>


syscall_wrapper(SysResult,ShareHandle, Handle* __shared_handle * hdl_out, Handle* __handle hdl, __u32 flags);
