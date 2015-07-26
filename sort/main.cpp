/**
Data              Author               Content
2015-07-25        lichao              Create Version
2015-07-26        lichao              When print array, seporate array num by backspace
2015-07-26        lichao              add heapsort.h
 */

#include <string.h>
#include <stdio.h>
#include "quicksort.h"
#include "heapmemalloc.h"
#include "heapsort.h"

int main(int argc, char** argv)
{
    HeapMemAlloc memAlloc;
    QuickSort<int> intQuickSort(&memAlloc);
    int d[] = {3, 4, 8, 5, 26, 12};
    intQuickSort.Alloc(sizeof(d));
    intQuickSort.CopyData(d, sizeof(d));
    intQuickSort.SetDataLength(sizeof(d) / sizeof(int));
    int *p = intQuickSort.sort();
    for(int i = 0; i < 6; i++)
    {
        printf("p[%d] = %d ", i, p[i]);
    }

    printf("\n");
    printf("SortTimes = %u\n", intQuickSort.SortTimes());


    HeapSort<int> intHeapSort(&memAlloc);
    intHeapSort.Alloc(sizeof(d));
    intHeapSort.CopyData(d, sizeof(d));
    intHeapSort.SetDataLen(sizeof(d) / sizeof(int));   
    p = intHeapSort.sort();
    for(int i = 0; i < 6; i++)
    {
        printf("p[%d] = %d ", i, p[i]);
    }

    printf("\n");
    return 0;
}
