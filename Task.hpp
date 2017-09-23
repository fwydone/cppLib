#ifndef _TASK_HPP
#define _TASK_HPP
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <iostream>
using std::cerr;
using std::endl;

class Task 
{
public:
    Task()
    {}

    void Execute()
    {
        pthread_t thrId;
        int iRes = pthread_create(&thrId, NULL, TaskFunc, this);
        if ( iRes != 0 )
        {
            cerr << "pthread_create failed:"
                << errno << ":" << strerror(errno)
                << endl;
            exit(1);
        }
        if ( pthread_join(thrId, NULL) != 0 )
        {
            cerr << "pthread_join failed:"
                << errno << ":" << strerror(errno)
                << endl;
            exit(1);
        }

    }
    static void *TaskFunc(void *arg)
    {
        Task *pThr = (Task *)arg;
        pThr->Run();
    }

    pthread_t TaskId() const 
    {
        return pthread_self();
    }

protected:
    virtual void Run() = 0;
    
private:
    Task(const Task &org);
    Task &operator=(const Task &org);
};


#endif

