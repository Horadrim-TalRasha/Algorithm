#ifndef MYITER_H
#define MYITER_H

#include <stddef.h>


struct input_iterator_tag
{

};
struct output_iterator_tag
{

};

struct forward_iterator_tag :public input_iterator_tag
{

};

struct bidirectional_iterator_tag : public forward_iterator_tag
{

};

struct random_access_iterator_tag : public bidirectional_iterator_tag
{

};

template<
         class Category,
         class T,
         class Distance = ptrdiff_t,
         class Pointer = T*,
         class Reference = T&
        >
struct iterator
{
    typedef Category  iterator_category;
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
};



template<typename T>
class MyIter
{
    typedef T value_type;
    T * ptr;
    explicit MyIter(T *p = 0) : ptr(p) {}
    T& operator*() const { return *ptr; }
};

template<typename I>
class iterator_traits
{
    typedef typename I::iterator_category iterator_category;
    typedef typename I::value_type value_type;
    typedef typename I::difference_type difference_type;
    typedef typename I::pointer pointer;
    typedef typename I::reference reference;
};

template<typename T>
class iterator_traits<T*>
{
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;
};

template<typename T>
class iterator_traits<const T*>
{
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef const T* pointer;
    typedef const T& reference;
};

template<class I>
static inline typename iterator_traits<I>::iterator_category
iterator_category(const I &)
{
    typedef typename iterator_traits<I>::iterator_category category;
    return category();
}

template<class I>
inline typename iterator_traits<I>::difference_type*
distance_type(const I &)
{
    return static_cast< typename iterator_traits<I>::difference_type* >(0);
}

template<class I>
inline typename iterator_traits<I>::value_type*
value_type(const I &)
{
    return static_cast<typename iterator_traits<I>::value_type* >(0);
}

template<class InputIterator>
static inline typename iterator_traits<InputIterator>::difference_type
__distance(InputIterator first, InputIterator last, input_iterator_tag)
{
    typename iterator_traits<InputIterator>::difference_type n = 0;
    while(first != last)
    {
        ++first;
        ++n;
    }
    return n;
}

template<class RandomAccessIterator>
static inline typename iterator_traits<RandomAccessIterator>::difference_type
__distance(RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag)
{
    return last - first;
}

template<class InputIterator>
inline typename iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last)
{
    typedef typename iterator_traits<InputIterator>::iterator_category category;
    return __distance(first, last, category());
}

template<class InputIterator, class Distance>
static inline void __advance(InputIterator & i, Distance n, input_iterator_tag)
{
    while(n--) ++i;
}

template<class BidirectionalIterator, class Distance>
static inline void __advance(BidirectionalIterator & i, Distance n, bidirectional_iterator_tag)
{
    if(n >= 0)
    {
        while(n--) ++i;
    }
    else
    {
        while(n++) --i;
    }
}

template<class RandomAccessIterator, class Distance>
static inline void __advance(RandomAccessIterator & i, Distance n, random_access_iterator_tag)
{
    i += n;
}

template<class InputIterator, class Distance>
inline void advance(InputIterator & i, Distance n)
{
    __advance(i, n, iterator_category(i));
}

#endif
