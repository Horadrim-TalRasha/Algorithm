#include <stdio.h>
#include <utility>
#include <string>
#include <iostream>


class foo
{
public:
    foo() : a(0)
    {
        printf("constructor called a = %d\n", a);
    }

    foo(const foo& s) : a(s.a)
    {
//        printf("copy constructor called s.a = %d\n", s.a);
//        a = s.a;
    }

    foo& operator=(foo& s)
    {
        printf("operator = called s.a = %d a = %d\n", s.a, a);
        a = s.a;
        return *this;
    }

    int a;
};


//void value(int& i)
//{
//    printf("left value: %d\n", i);
//}

void value(int&& i)
{
    printf("address: %p\n", &i);
    printf("right value: %d\n", i);
}

//void value(const int& i)
//{
//    printf("const\n");

//}

int main(int argc, char** argv)
{
    value(1);
    int a = 19;
    value(std::move(a));


    std::string str1("Hello");
    std::string str2 = std::move(str1);
    std::cout << "after move str:" << str1 <<std::endl;    // str1 was cleared

    foo t;
    t.a = 16;
    foo s = t; // call copy constructor
    foo v;
    v = s;  // call operator==
    return 0;
}
