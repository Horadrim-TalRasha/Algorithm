#ifndef ALLOCATOR_H
#define ALLOCATOR_H


template<int inst>
class __malloc_alloc_template
{
private:
    //  oom = out of memory
    static void *oom_malloc(const size_t &);

    static void *oom_realloc(void*, const size_t &);

    static void (*__malloc_alloc_oom_handler)();

public:
    static void* allocate(const size_t & n)
    {
        void * p = malloc(n);
        if(p == 0)
        {
            p = oom_malloc(n);
        }

        return p;
    }

    static void deallocate(void *p, const size_t &)
    {
        free(p);
    }

    static void* reallocate(void* p, const size_t &, const size_t & nSize)
    {
        void* np = realloc(p, nSize);
        if(0 == np)
        {
            np = oom_realloc(p, nSize);
        }

        return np;
    }

    static void (*set_malloc_handler(void (*f)()))()
    {
        void (*old)() = __malloc_alloc_oom_handler;
        __malloc_alloc_oom_handler = f;
        return (old);
    }
};

template<int inst>
void (*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;

template<int inst>
void * __malloc_alloc_template<inst>::oom_malloc(const size_t & n)
{
    void (*my_malloc_handler)();
    void *p = 0;
    for(;;)
    {
        my_malloc_handler = __malloc_alloc_oom_handler;
        if(0 == my_malloc_handler)
        {
            throw std::bad_alloc();
        }

        (*my_malloc_handler)();
        p = malloc(n);
        if(p)
        {
            break;
        }
    }

    return p;
}

template<int inst>
void * __malloc_alloc_template<inst>::oom_realloc(void* p, const size_t & n)
{
    void (*my_malloc_handler)();
    void *np = 0;

    for(;;)
    {
        my_malloc_handler = __malloc_alloc_oom_handler;
        if(0 == my_malloc_handler)
        {
            throw std::bad_alloc();
        }

        my_malloc_handler();
        np = realloc(p, n);
        if(np)
        {
            break;
        }
    }

    return np;
}

typedef __malloc_alloc_template<0> malloc_alloc;

template<typename T, class Alloc>
class simple_alloc
{
public:
    static T* allocate(const size_t& n)
    {
        return n == 0 ? 0 : (T*)Alloc::allocate(n * sizeof(T));
    }

    static T* allocate(void)
    {
        return (T*)Alloc::allocate(sizeof(T));
    }

    static void deallocate(T *p, const size_t & n)
    {
        if(0 == n)
        {
            Alloc::deallocate(p, n * sizeof(T));
        }
    }

    static void deallocate(T *p)
    {
        Alloc::deallocate(p, sizeof(T));
    }
};


#endif
