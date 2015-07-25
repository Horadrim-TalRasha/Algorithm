/**
Data              Author               Content
2015-07-25        lichao              Create Version
 */

#ifndef MEM_ALLOCATOR_H
#define MEM_ALLOCATOR_H

class MemAllocator
{
public:
    virtual void* AllocMem(const unsigned int& uiSize) = 0;

};

#endif
