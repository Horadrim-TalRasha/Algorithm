/*
 *   This is an example for practising pool allocator
 */

#include <ext/pool_allocator.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int * TestPoolAllocMemFree()
{
     __gnu_cxx::__pool_alloc<int> c;
    int * p = c.allocate(1);
    *p = 15;
    return p;
}

int main(int argc, char ** argv)
{
    std::vector<int, __gnu_cxx::__pool_alloc<int> > v;
    v.push_back(1);

    __gnu_cxx::__pool_alloc<int> c;
    int * p = c.allocate(16);
    c.deallocate(p, 16);


    int * q = TestPoolAllocMemFree();
    printf("*q = %d\n", *q);    ///     the memory allocated in memory pool will leak. 
    return 0;
}
