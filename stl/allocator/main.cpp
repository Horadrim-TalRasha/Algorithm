#include "default_alloc.h"


int main(int argc, char** argv)
{
    __default_alloc_template<false, 0>::allocate(16);


    return 0;
}
