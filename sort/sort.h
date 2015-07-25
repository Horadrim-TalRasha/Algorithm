/**
Data              Author               Content
2015-07-25        lichao              Create Version
 */

#ifndef SORT_H
#define SORT_H

#include "memallocator.h"

template<typename T>
class Sort
{
    virtual T* sort() = 0;
protected:
    T* m_pUnsortedData;
    MemAllocator* m_pMemAlloc;    
};



#endif
