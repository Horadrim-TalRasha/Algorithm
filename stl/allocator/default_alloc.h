#ifndef DEFAULT_ALLOC_H
#define DEFAULT_ALLOC_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <new>

enum {__ALIGN = 8};
enum {__MAX_BYTES = 128};
enum {__NFREELISTS = __MAX_BYTES / __ALIGN};


template<bool threads, int inst>
class __default_alloc_template
{
private:
    static size_t ROUND_UP(const size_t & bytes)
    {
        return ((bytes * __ALIGN - 1) & -(__ALIGN - 1));
    }

    union obj
    {
        union obj * free_list_link;
        char client_data[1];
    };

    static obj * volatile free_list[__NFREELISTS];

    static void * refill(const size_t & n);

    static char * chunk_alloc(const size_t & size, int & nObjs);

    static char * start_free;

    static char * end_free;

    static size_t heap_size;

public:
    static void * allocate(const size_t & n);

    static void deallocate(void* p, const size_t & n);

    static void * reallocate(void* p, const size_t & old_size, const size_t & new_size);
};

template<bool threads, int inst>
char * __default_alloc_template<threads, inst>::start_free = 0;

template<bool threads, int inst>
char * __default_alloc_template<threads, inst>::end_free = 0;

template<bool threads, int inst>
size_t __default_alloc_template<threads, inst>::heap_size = 0;

template<bool threads, int inst>
typename __default_alloc_template<threads, inst>::obj * volatile
__default_alloc_template<threads, inst>::free_list[__NFREELISTS] =
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

#endif
