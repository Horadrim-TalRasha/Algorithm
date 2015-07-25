/**
Data              Author               Content
2015-07-25        lichao              Create Version
 */


#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "sort.h"

template<typename T>
class QuickSort : public Sort<T>
{
public:
    QuickSort(MemAllocator* pMemAlloc)
    {
        Sort<T>::m_pMemAlloc = pMemAlloc;
        Sort<T>::m_pUnsortedData = NULL;
    }
    virtual ~QuickSort()
    {
        delete Sort<T>::m_pUnsortedData;
        Sort<T>::m_pUnsortedData = NULL;
    }
    virtual T* sort()
    {
        return NULL;
    }
};

#endif
