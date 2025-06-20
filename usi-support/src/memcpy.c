

void* memset(void* restrict __dest, int n, unsigned long len){
    char* __end = ((char*)__dest) + len; 
    for(char* __ptr = __dest; __ptr != __end; __ptr++)
        *__ptr = n;
}

void* memcpy(void* restrict __dest, const void* restrict __src, unsigned long len) {
    char* __dest_end = ((char*)__dest) + len;
    for(char* __ptr = __dest; __ptr != __dest_end; __ptr++)
        *__ptr = *(const char*)__src++;
}

void* memmove(void* __dest, const void* __src, unsigned long len) {
    char* __dest_end = ((char*)__dest) + len;
    for(char* __ptr = __dest; __ptr != __dest_end; __ptr++)
        *__ptr = *(const char*)__src++;
}

int memcmp(const void* __a, const void* __b, unsigned long len){
    const char* __a_end = ((const char*)__a)+len;
    for(const char* __a_ptr = (const char*)__a, *__b_ptr = (const char*)__b; __a_ptr!=__a_end; __a_ptr++, __b_ptr++){
        if((*__a_ptr)<(*__b_ptr))
            return -1;
        else if((*__a_ptr)>(*__b_ptr))
            return 1;
    }
    return 0;
}