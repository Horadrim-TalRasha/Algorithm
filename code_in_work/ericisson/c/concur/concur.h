#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

typedef  void* (*thread_func)(void *);

typedef  void* (*task_handler)(void *);

typedef struct Task
{
    task_handler * handler_;
    void * parameters_;
} Task;

typedef struct TaskNode
{
    Task * task_;
    struct TaskNode * next_task_;
} TaskNode;

typedef struct TaskQueue
{
    TaskNode task_head_node_;
} TaskQueue;

int startThreads(int threadNum);