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
public:
    virtual T* sort() = 0;
    int Alloc(const unsigned int& uiSize)
    {
        if(!(m_pUnsortedData = (T*)m_pMemAlloc->AllocMem(uiSize)))
        {
            return 1;
        }
        return 0;
    }
  
    int CopyData(T* pSrcData, const unsigned int& uiSize)
    {
        if(pSrcData == NULL)
        {
            return 1;
        }

        memcpy(m_pUnsortedData, pSrcData, uiSize);
        return 0;
    }
 
    inline const long& GetUnSortedData()
    {
        return (long)m_pUnsortedData;
    }

protected:
    T* m_pUnsortedData;
    MemAllocator* m_pMemAlloc;    
};



#endif
