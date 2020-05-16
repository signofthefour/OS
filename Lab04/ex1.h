#ifndef __ALIGNED_MALLOC__
#define __ALIGNED_MALLOC__

void * aligned_malloc(unsigned int size, unsigned int align);
void * aligned_free (void* ptr);

#endif