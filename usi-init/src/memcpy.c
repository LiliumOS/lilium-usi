

__attribute__((weak)) void* memset(void* restrict __dest, int n, unsigned long len){
    char* __end = ((char*)__dest) + len; 
    for(char* __ptr = __dest; __ptr != __end; __ptr++)
        *__ptr = n;
}

__attribute__((weak)) void* memcpy(void* restrict __dest, const void* restrict __src, unsigned long len) {
    char* __dest_end = ((char*)__dest) + len;
    for(char* __ptr = __dest; __ptr != __dest_end; __ptr++)
        *__ptr = *(const char*)__src;
}

__attribute__((weak)) void* memmove(void* __dest, const void* __src, unsigned long len) {
    char* __dest_end = ((char*)__dest) + len;
    for(char* __ptr = __dest; __ptr != __dest_end; __ptr++)
        *__ptr = *(const char*)__src;
}