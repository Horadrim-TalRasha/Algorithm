#ifndef SGI_MEM_POOL_TEST_H
#define SGI_MEM_POOL_TEST_H

#include "default_alloc.h"
#include <iostream>
#include <stdio.h>

class SGIMemPoolTest
{
public:
    typedef __default_alloc_template<false, 0> default_alloc;
    static void TestRoundUp()
    {
        size_t roundedUpSize = 0;

        roundedUpSize = default_alloc::ROUND_UP(4);
        std::cout << "4 byte round up size: " << roundedUpSize << std::endl;

        roundedUpSize = default_alloc::ROUND_UP(15);
        std::cout << "15 byte round up size: " << roundedUpSize << std::endl;

        roundedUpSize = default_alloc::ROUND_UP(16);
        std::cout << "16 byte round up size: " << roundedUpSize << std::endl;

        roundedUpSize = default_alloc::ROUND_UP(32);
        std::cout << "32 byte round up size: " << roundedUpSize << std::endl;

        roundedUpSize = default_alloc::ROUND_UP(33);
        std::cout << "33 byte round up size: " << roundedUpSize << std::endl;

        roundedUpSize = default_alloc::ROUND_UP(64);
        std::cout << "64 byte round up size: " << roundedUpSize << std::endl;
    }

    static void TestFreeIndex()
    {
        size_t freeIndex = 0;

        freeIndex = default_alloc::FREELIST_INDEX(15);
        std::cout << "15 byte Free Index: " << freeIndex << std::endl;

        freeIndex = default_alloc::FREELIST_INDEX(8);
        std::cout << "8 byte Free Index: " << freeIndex << std::endl;

        freeIndex = default_alloc::FREELIST_INDEX(16);
        std::cout << "16 byte Free Index: " << freeIndex << std::endl;
    }

    static void TestMemoryAlloc()
    {
        char * p = (char *)default_alloc::allocate(16);
        std::cout << "p = " << p << std::endl;
        printf("%p\n", (char *)(default_alloc::free_list[default_alloc::FREELIST_INDEX(16)]));

    }
};
#endif
