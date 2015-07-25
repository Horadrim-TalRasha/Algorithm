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
        StartQuickSort(0, m_uiDataLength - 1);
        return NULL;
    }

    void SetDataLength(const int& uiDataLength)
    {
        m_uiDataLength = uiDataLength;
    }

    const int& DataLength() const
    {
        return m_uiDataLength;
    }
private:
    void StartQuickSort(const int& uiLeft, const int& uiRight)
    {
        if(uiLeft < uiRight)
        {
            T t_key = Sort<T>::m_pUnsortedData[uiLeft];
            int uiLow = uiLeft;
            int uiHigh = uiRight;
            while(uiLow < uiHigh)
            {
                while(uiLow < uiHigh && Sort<T>::m_pUnsortedData[uiHigh] >= t_key)
                {
                    uiHigh--;
                }
                Sort<T>::m_pUnsortedData[uiLow] = t_key;
                while(uiLow < uiHigh && Sort<T>::m_pUnsortedData[uiLow] <= t_key)
                {
                    uiLow++;
                }
                Sort<T>::m_pUnsortedData[uiHigh] = Sort<T>::m_pUnsortedData[uiLow];
            }

            Sort<T>::m_pUnsortedData[uiLow] = t_key;
            StartQuickSort(uiLeft, uiLow - 1);
            StartQuickSort(uiHigh + 1, uiRight);
        }
    }

     int  m_uiDataLength;
};

#endif
