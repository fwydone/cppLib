#include <iostream>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "Task.hpp"

using namespace std;

class TaskExample: public Task
{
protected:
    virtual void Run()
    {
        while(1)
        {
        }
    }
};

int main(int argc, char *argv[])
{
    int iTasks = atoi(argv[1]);
    for ( int i = 0; i < iTasks; ++i )
    {
        TaskExample thrExp;
        thrExp.Execute();
    }

    return 0;
}
