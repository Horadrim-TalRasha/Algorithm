#include "sgi_mem_pool_test.h"


int main(int argc, char** argv)
{

    SGIMemPoolTest::TestRoundUp();

    SGIMemPoolTest::TestFreeIndex();

    SGIMemPoolTest::TestMemoryAlloc();

    int * p[3] = {0, 0, 0};
    int * q = *p + 2;
    q = new int();
    *q = 10;
    printf("p[1] = %p\n", p[1]);
    printf("p + 1 = %p\n", p + 1);
    return 0;
}
