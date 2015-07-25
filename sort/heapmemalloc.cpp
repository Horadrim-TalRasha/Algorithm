/**
Data              Author               Content
2015-07-25        lichao              Create Version
 */


#include "heapmemalloc.h"


HeapMemAlloc::HeapMemAlloc()
{


}

HeapMemAlloc::~HeapMemAlloc()
{


}

void* HeapMemAlloc::AllocMem(const unsigned int& uiSize)
{
    void* p = malloc(uiSize);
    return p;
}
