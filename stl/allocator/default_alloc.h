#ifndef DEFAULT_ALLOC_H
#define DEFAULT_ALLOC_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <new>

#include "allocator.h"

enum {__ALIGN = 8};
enum {__MAX_BYTES = 128};
enum {__NFREELISTS = __MAX_BYTES / __ALIGN};


template<bool threads, int inst>
class __default_alloc_template
{
private:
    static size_t ROUND_UP(const size_t & bytes)
    {
        return ((bytes + __ALIGN - 1) & -(__ALIGN - 1));
    }

    static size_t FREELIST_INDEX(const size_t & bytes)
    {
        return (((bytes) + __ALIGN - 1) / __ALIGN - 1);
    }

    union obj
    {
        union obj * free_list_link;
        char client_data[1];
    };

    static obj * volatile free_list[__NFREELISTS];

    static void * refill(const size_t & n)
    {
        int nobjs = 20;
        char * chunk = chunk_alloc(n, nobjs);
        obj * volatile * my_free_list = 0;
        obj * result = 0;
        obj * current_obj = 0, * next_obj = 0;
        int i = 0;

        if(nobjs == 1)
        {
            return chunk;
        }

        my_free_list = free_list + FREELIST_INDEX(n);
        result = (obj *)chunk;
        *my_free_list = next_obj = (obj *)(chunk + n);
        for(i = 1; ; ++i)
        {
            current_obj = next_obj;
            next_obj = (obj *)((char *)next_obj + n);
            if(nobjs - 1 == i)
            {
                current_obj->free_list_link = 0;
                break;
            }
            else
            {
                current_obj->free_list_link = next_obj;
            }
        }
        return result;
    }

    static char * chunk_alloc(const size_t & size, int & nobjs)
    {
        char * result;
        size_t total_bytes = size * nobjs;
        size_t bytes_left = end_free - start_free;

        if(bytes_left >= total_bytes)
        {
            result = start_free;
            start_free += total_bytes;
            return result;
        }
        else if(bytes_left >= size)
        {
            nobjs = bytes_left / size;
            total_bytes = nobjs * size;
            result = start_free;
            start_free += total_bytes;
            return result;
        }
        else
        {
            size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);
            if(bytes_left > 0)
            {
                obj * volatile * my_free_list = free_list + FREELIST_INDEX(bytes_left);
                ((obj*)start_free)->free_list_link = *my_free_list;
                *my_free_list = (obj*)start_free;
            }            

            start_free = (char*)malloc(bytes_to_get);
            if(start_free == 0)
            {
                int i = 0;
                obj * volatile * my_free_list = 0, * p = 0;
                
                for(i = size; i <= __MAX_BYTES; i += __ALIGN)
                {
                    my_free_list = free_list + FREELIST_INDEX(i);
                    p = *my_free_list;
                    if(p != NULL)
                    {
                        *my_free_list = p->free_list_link;
                        start_free = (char *)p;
                        end_free = start_free + i;
                        return chunk_alloc(size, nobjs);
                    }
                }

                end_free = 0;
                start_free = (char *)malloc_alloc::allocate(bytes_to_get);
            }
            heap_size += bytes_to_get;
            end_free = start_free + bytes_to_get;
            return chunk_alloc(size, nobjs);
        }
    }

    static char * start_free;

    static char * end_free;

    static size_t heap_size;

public:
    static void * allocate(const size_t & n)
    {
        obj * volatile * my_free_list = 0;
        obj * result;

        if (n > (size_t)__MAX_BYTES)
        {
            return malloc_alloc::allocate(n);
        }

        my_free_list = free_list + FREELIST_INDEX(n);
        result = *my_free_list;
        if(result == 0)
        {
            void *r = refill(ROUND_UP(n));
            return r;
        }

        *my_free_list = result->free_list_link;
        return result;
    }

    static void deallocate(void* p, const size_t & n)
    {
        obj *q = (obj *)p;
        obj * volatile * my_free_list;

        if(n > (size_t)__MAX_BYTES)
        {
            malloc_alloc::deallocate(p, n);
            return;
        }

        my_free_list = free_list + FREELIST_INDEX(n);
        q->free_link_list = *my_free_list;
        *my_free_list = q;
    }

    static void * reallocate(void* p, const size_t & old_size, const size_t & new_size);

    friend class SGIMemPoolTest;
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
