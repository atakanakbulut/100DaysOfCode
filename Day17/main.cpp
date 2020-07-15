#include <iostream>
#include <unistd.h>
#include "Async.h"

int main()
{
    Async as;
    as.run();

    while (true)
    {
        // main thread
        sleep(5);
    }
    return 0;
}