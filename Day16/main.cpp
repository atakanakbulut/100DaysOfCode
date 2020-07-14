#include <iostream>
#include <unistd.h>
#include "ThreadPool.h"

int main()
{
    ThreadPool t;
    //t.runThreadPool();
     t.runDualThread();

   // t.cpuAffinity(11);

    while (true)
    {
        // main thread
        sleep(5);
    }
    


    return 0;
}