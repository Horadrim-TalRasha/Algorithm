/**
Data              Author               Content
2015-07-25        lichao              Create Version
 */

#include <string.h>
#include "quicksort.h"
#include "heapmemalloc.h"

int main(int argc, char** argv)
{
    HeapMemAlloc memAlloc;
    QuickSort<int> intQuickSort(&memAlloc);
    int d[] = {3, 4, 8, 5, 26, 12};
    intQuickSort.Alloc(sizeof(d));
    intQuickSort.CopyData(d, sizeof(d));
    return 0;
}
