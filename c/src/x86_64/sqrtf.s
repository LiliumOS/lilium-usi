
.globl sqrtf

sqrtf:
    sqrtss xmm0, xmm0
    ret
    sqrtf._end:
.type sqrtf, STT_FUNC
.size sqrtf, sqrtf._end-sqrtf
