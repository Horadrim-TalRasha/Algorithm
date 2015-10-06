#include <stdio.h>
#include <utility>
#include <string>
#include <iostream>


class foo
{
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
    value(a);


    std::string str1("Hello");
    std::string str2 = std::move(str1);
    std::cout << "after move str:" << str1 <<std::endl;    // str1 was cleared
    return 0;
}
