#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Optional: use these functions to add debug or error prints to your application
#define DEBUG_LOG(msg,...)
//#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)

void* threadfunc(void* thread_param)
{
    // Casting data to obtain thread argumens from the parameter
    struct thread_data* thread_func_args = (struct thread_data *) thread_param;
    // Waiting (us = ms *1000)
    usleep(thread_func_args->wait_to_obtain_ms * 1000);
    // Obtain mutex and locking
    pthread_mutex_lock(thread_func_args->mutex);
    // Holds the thread ...
    usleep(thread_func_args->wait_to_release_ms*1000);
    // Releasing mutex
    pthread_mutex_unlock(thread_func_args->mutex);
    // Returning sucess
    thread_func_args->thread_complete_success = true;
    return thread_param;
}


bool start_thread_obtaining_mutex(pthread_t *thread, pthread_mutex_t *mutex,int wait_to_obtain_ms, int wait_to_release_ms)
{   
    // Alocate memory for thread_data
    struct thread_data* pthreadData = (struct thread_data*)malloc(sizeof(struct thread_data));
    
    // Setup mutex and wait arguments
    pthreadData->mutex = mutex;
    pthreadData->wait_to_obtain_ms = wait_to_obtain_ms;
    pthreadData->wait_to_release_ms = wait_to_release_ms;

    // Passing thread_data to create a thread
    int rc = pthread_create(thread, NULL, threadfunc, pthreadData);
    if (rc != 0) {
        ERROR_LOG("Thread: Error to create!");
        free(pthreadData);
        return false;
    }
    // Return true if sucessful
    return true;
}

