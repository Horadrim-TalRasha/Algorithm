#include <concur/concur.h>

static void* test_thread_func(void* para)
{
	printf("para = %p\n", para);
    return NULL;
}

int main(int argc, char ** argv)
{
	startThreads(10, test_thread_func);
	startThreads(10, test_thread_func);
    return 0;
}