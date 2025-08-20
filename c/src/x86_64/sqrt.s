
.global sqrt, sqrtl

sqrtl:
    sqrtsd xmm0, xmm0
    ret
    sqrtl._end:
.type sqrtl, STT_FUNC
.size sqrtl, sqrtl._end-sqrtl


sqrt:
    sqrtsd xmm0, xmm0
    ret
    sqrt._end:
.type sqrt, STT_FUNC
.size sqrt, sqrt._end-sqrt
