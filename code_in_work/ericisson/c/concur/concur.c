#include "concur.h"


static pthread_mutex_t dead_lock_;


int startThreads(int threadNum, thread_func func)
{
    int init_ret = pthread_mutex_init(&dead_lock_, NULL);
    printf("init_ret = %d\n", init_ret);
    if(init_ret)
    {
        return init_ret;
    }
    // pthread_mutex_lock(&dead_lock_);
    // pthread_mutex_lock(&dead_lock_);

    return 0;
}
