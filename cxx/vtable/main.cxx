#include <stdio.h>

class A
{
public:
    virtual void func(const int & a) { printf("class A\n"); };
};

class B : virtual public A
{
public:
    virtual void func(const int & a) { printf("class B\n"); };

};

class C : virtual public A
{
public:
    virtual void func(const int & a) { printf("class C\n"); };
};

class D : public B, public C
{
public:
    virtual void func(const int & a) { printf("class D\n"); };
};

class NonInherit
{
public:
    int m_memberA;
};

int main(int argc, char** argv)
{
    NonInherit c;
	D d;
    printf("vptr: %p\n", *(int *)&d);
    printf("first virtual func addr: %p\n", *(int *)*(int *)&d);
    typedef void(*Func)(const int &);
	Func fun = (Func)(*(int *)*(int *)(&d));
	fun(15);

	Func fun2 = (Func)*((int *)*((int *)(&d)) + 1);
	fun2(17);    // segment fault looks like the memory layout is not like VC++.

	// a reference here: http://www.cnblogs.com/QG-whz/p/4909359.html
    return 0;
}
