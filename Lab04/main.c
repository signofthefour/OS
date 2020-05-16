#include <stdio.h>
#include <unistd.h>
#include "ex1.h"

int main() {
    void* p1 = aligned_malloc(16, 64);
    aligned_free(p1);

    void* brk;

    brk = sbrk( 0x3100 );
    printf( "New break value after sbrk( 0x3100 ) \t%p\n",
            brk );

    brk = sbrk( 0x0200 );
    printf( "New break value after sbrk( 0x0200 ) \t%p\n",
            brk );
    return 0;
}