
long strlen(const char* p) {
    const char* n = p;
    for(; *n; n++);

    return n-p;
}