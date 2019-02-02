#include <pthread.h>

typedef  void (*thread_func)(void *);


int startThreads(int threadNum, thread_func func);