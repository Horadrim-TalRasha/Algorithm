#ifndef INTRUSIVE_PTR_BASE_HPP
#define INTRUSIVE_PTR_BASE_HPP

#include <boost/intrusive_ptr.hpp>
#include <boost/detail/atomic_count.hpp>
#include <boost/checked_delete.hpp>
#include <iostream>


template<typename T>
class intrusive_ptr_base
{
private:
    mutable boost::detail::atomic_count ref_count;

public:
    intrusive_ptr_base() : ref_count(0)
    {
        std::cout << "call constructor" << std::endl;
    }

    intrusive_ptr_base(const intrusive_ptr_base<T> & rhs) : ref_count(0)
    {
        std::cout << "call copy constructor" << std::endl;
    }

    intrusive_ptr_base& operator=(const intrusive_ptr_base<T> & rhs)
    {
        std::cout << "call operator=" << std::endl;
        return *this;
    }

    friend void intrusive_ptr_add_ref(const intrusive_ptr_base<T> * s)
    {
        std::cout << "before intrusive_ptr_add_ref... " << s->ref_count << std::endl;
        ++s->ref_count;
        std::cout << "after intrusive_ptr_add_ref... " << s->ref_count << std::endl;
    }

    friend void intrusive_ptr_release(const intrusive_ptr_base<T> * s)
    {
        std::cout << "before intrusive_ptr_release... " << s->ref_count << std::endl;
        if(--s->ref_count == 0)
        {
            boost::checked_delete(static_cast<const T*>(s));
        }
        else
        {
            std::cout << "after intrusive_ptr_release... " << s->ref_count << std::endl;
        }
    }

    boost::intrusive_ptr<T> self()
    {
        return boost::intrusive_ptr<T>((T*)this);
    }

    boost::intrusive_ptr<T> self() const
    {
        return boost::intrusive_ptr<const T>((T const*)this);
    }

    int refcount() const
    {
        return ref_count;
    }
};

#endif
