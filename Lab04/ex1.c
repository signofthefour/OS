#include <stdlib.h>

#include "ex1.h"

void * aligned_malloc(unsigned int size, unsigned int align) {
    void* p1, *p2;
    
    if ((p1 = (void*)malloc(size + align + sizeof (void*))) == NULL ) // check that heap
        return NULL;                                                  // has enough space and allocated a mem block
    size_t addr = *((size_t*)&p1) + align + sizeof(void*);
    addr -= (addr % align);
    p2 = (void*)(&(addr));
    *((size_t *)p2 - 1) = *((size_t*)&p1); // store the new that is allocated by malloc
    return p2;
}

void * aligned_free(void* ptr) {
    // we find the addr of the space that allocated by malloc
    // size_t has the 32 bits or 64 bits base on system. So,
    // we use size_t to make sure that we have enough space to store addr
    free((void*)(*((size_t*)ptr - 1)));   // deallocated the space that we stored in (prt - 1)
}