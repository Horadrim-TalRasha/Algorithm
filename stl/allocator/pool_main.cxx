/*
 *   This is an example for practising pool allocator
 */

#include <ext/pool_allocator.h>
#include <vector>

int main(int argc, char ** argv)
{
    std::vector<int, __gnu_cxx::__pool_alloc<int> > v;
    v.push_back(1);

    return 0;
}
