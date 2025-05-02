#define __LILIUM_WANT_SYSPROTO 1
#include <lilium-sci/syscall.h>
#include <lilium-sci/types.h>

#include <syscall.h>
#include <helpers.h>


SysResult GetSystemInfo(KSlice reqs) {
    SysInfoRequest* req_ptr = reqs.buf_ptr;
    SysInfoRequest* end = req_ptr+reqs.len;
    SysInfoRequest* first_adjusted_req = NULL;
    for(; req_ptr != end; req_ptr++) {
        if (UUID_EQ(req_ptr->head.ty, __LILIUM__SYS_INFO_REQUEST_OS_VERSION_ID)){
            req_ptr->head.flags |= OPTION_FLAG_SYSINFO_FORCE_IGNORE | OPTION_FLAG_IGNORE;
            first_adjusted_req = first_adjusted_req?:req_ptr;

            req_ptr->os_version.os_major = 0;
            req_ptr->os_version.os_minor = 1;
            __ilong res = TRY_FILL_STR_CONST(req_ptr->os_version.os_name, "Lilium");
            if (res < 0)
                return res;
        }
    }

    SysResult res = DO_SYSCALL(__LILIUM_SYSNO(SUBSYS_BASE, __SYS_GetSystemInfo), reqs.buf_ptr, reqs.len);

    if(first_adjusted_req)
        for(; first_adjusted_req!=end; first_adjusted_req++) {
            if(req_ptr->head.flags & OPTION_FLAG_SYSINFO_FORCE_IGNORE)
                req_ptr->head.flags &= ~(OPTION_FLAG_SYSINFO_FORCE_IGNORE | OPTION_FLAG_IGNORE);
        }
}
