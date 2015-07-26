/**
 Data              Author               Content
 2015-07-26        lichao              Create Version
 2015-07-26        lichao              Implement HeapSort Algorithm
  */

#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "sort.h"

template<typename T>
class HeapSort : public Sort<T>
{
public:
    HeapSort(MemAllocator* pAlloc)
    {
        Sort<T>::m_pMemAlloc = pAlloc;
        Sort<T>::m_pUnsortedData = NULL;
        m_nDataLen = 0;
    }

    virtual ~HeapSort()
    {
        delete Sort<T>::m_pUnsortedData;
        Sort<T>::m_pUnsortedData = NULL;
    }

    T* sort()
    {
        StartHeapSort();
        return Sort<T>::m_pUnsortedData;
    }

    void SetDataLen(const int& nDataLen)
    {
        m_nDataLen = nDataLen;
    }

    void HeapAdjust(int iPos, const int& iLen) const
    {
        int iChild;
        for(; 2 * iPos + 1 < iLen; iPos = iChild)
        {
            iChild = 2 * iPos + 1;
            if(iChild < iLen - 1 &&
               Sort<T>::m_pUnsortedData[iChild + 1] > Sort<T>::m_pUnsortedData[iChild])
            {
                iChild++;
            }
            
            if(Sort<T>::m_pUnsortedData[iPos] < Sort<T>::m_pUnsortedData[iChild])
            {
                T t_temp = Sort<T>::m_pUnsortedData[iPos];
                Sort<T>::m_pUnsortedData[iPos] = Sort<T>::m_pUnsortedData[iChild];
                Sort<T>::m_pUnsortedData[iChild] = t_temp;
            }
            else
            {
                break;
            }
        }
    }

private:
    void StartHeapSort() const
    {
        int i;
        for(i = m_nDataLen / 2 - 1; i >= 0; i--)
        {
            HeapAdjust(i, m_nDataLen);
        }

        for(i = m_nDataLen - 1; i > 0; i--)
        {
            T t_temp = Sort<T>::m_pUnsortedData[0];
            Sort<T>::m_pUnsortedData[0] = Sort<T>::m_pUnsortedData[i];
            Sort<T>::m_pUnsortedData[i] = t_temp;
            HeapAdjust(0, i);
        }
    }

    int m_nDataLen;
};

#endif

