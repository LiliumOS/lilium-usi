#include <stddef.h>
#include <stdint.h>

#include <lilium-sci/process.h>

#include <helpers.h>

void* __usi_malloc_map(size_t bytes) {
    size_t pages = (bytes + 4095)>>12;

    void* map_addr = NULL;

    SysResult res = CreateMapping(&map_addr, pages, MAP_ATTR_READ | MAP_ATTR_WRITE, MAP_KIND_NORMAL, &CSLICE_EMPTY(MapExtendedAttr));
    if (res < 0)
        return (void*)(-1);
    else
        return map_addr;
}