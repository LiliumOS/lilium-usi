

void* memset(void* restrict __dest, int n, unsigned long len){
    char* __end = ((char*)__dest) + len; 
    for(char* __ptr = __dest; __ptr != __end; __ptr++)
        *__ptr = n;
}