#include <boost/intrusive_ptr.hpp>
#include <stdio.h>
#include <vector>

#include "intrusive_ptr_base.hpp"


class foo : public intrusive_ptr_base<foo>
{
public:
    explicit foo() : m_nTag(0)
    {
        std::cout << "call foo constructor" << std::endl;
    }

    foo(const foo & rhs) : m_nTag(rhs.m_nTag)
    {

    }

private:
    int m_nTag;
};

int main(int argc, char** argv)
{
    std::vector< boost::intrusive_ptr<foo> > range;
    for(int i = 0; i < 5; i++)
    {
        boost::intrusive_ptr<foo> p(new foo());
        range.push_back(p);
    }

    std::cout << "--------------------------------------" << std::endl << std::endl;

    for(std::vector< boost::intrusive_ptr<foo> >::iterator it = range.begin(); it != range.end(); ++it)
    {
        boost::intrusive_ptr<foo> p = *it;
    }

    std::cout << "vector size: " << range.size() << std::endl;
    return 0;
}
