/**
Data              Author               Content
2015-07-25        lichao              Create Version
 */

#ifndef HEAP_MEM_ALLOC_H
#define HEAP_MEM_ALLOC_H

#include <stdlib.h>
#include "memallocator.h"

class HeapMemAlloc : public MemAllocator
{
public:
    HeapMemAlloc();
    virtual ~HeapMemAlloc();
    void* AllocMem(const unsigned int& uiSize);

};
#endif
