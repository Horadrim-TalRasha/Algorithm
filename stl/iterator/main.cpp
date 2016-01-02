#include <stdio.h>


template <class I>
struct iterator_traits
{
    typedef typename I::value_type   value_type;
};

template <class I>
typename iterator_traits<I>::value_type
func(I ite)
{
    return ite;
}

template <class T>
struct iterator_traits<T*>
{
    typedef T value_type;
};

int main(int argc, char** argv)
{

    return 0;
}
