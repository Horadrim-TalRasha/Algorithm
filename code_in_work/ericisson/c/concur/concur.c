#include "concur.h"


static pthread_mutex_t thread_pool_lock_;
static pthread_mutex_t dead_lock_;
static pthread_cond_t thread_pool_cond_;

static int is_thread_pool_running = 1;

static void * thread_pool_entry(void * thread_params)
{
    while(is_thread_pool_running)
    {
        printf("before mutex lock\n");
        pthread_mutex_lock(&thread_pool_lock_);
        printf("after mutex lock\n");

        struct timespec abstime;
        clock_gettime(CLOCK_REALTIME, &abstime);
        abstime.tv_sec += 5;

        printf("before timed wait\n");
        int timeout = pthread_cond_timedwait(&thread_pool_cond_, &thread_pool_lock_, &abstime);
        printf("thread: %d passed clock and timeout = %d\n", *(int *)thread_params, timeout);
        pthread_mutex_unlock(&thread_pool_lock_);
    }
    return NULL;
}

int startThreads(int threadNum)
{
    printf("ETIMEDOUT = %d\n", ETIMEDOUT);
    int thread_pool_lock_init_ret = pthread_mutex_init(&thread_pool_lock_, NULL);
    if(thread_pool_lock_init_ret)
    {
        return thread_pool_lock_init_ret;
    }

    int thread_pool_cond_init_ret = pthread_cond_init(&thread_pool_cond_, NULL);
    if(thread_pool_cond_init_ret)
    {
        return thread_pool_cond_init_ret;
    }

    int dead_lock_init_ret = pthread_mutex_init(&dead_lock_, NULL);
    if(dead_lock_init_ret)
    {
        return dead_lock_init_ret;
    }

    int i = 0;
    for(;i < threadNum; i++)
    {
    	pthread_t thread_id;
    	pthread_create(&thread_id, NULL, thread_pool_entry, &i);
    }

    pthread_mutex_lock(&dead_lock_);
    pthread_mutex_lock(&dead_lock_);

    pthread_mutex_destroy(&thread_pool_lock_);
    pthread_mutex_destroy(&dead_lock_);
    pthread_cond_destroy(&thread_pool_cond_);
    return 0;
}

