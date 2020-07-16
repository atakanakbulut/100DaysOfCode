#include <iostream>
#include "InterProcess.h"
 
int main()
{
   InterProcess *i = new InterProcess();
   i->application();
    while (true)
    {
        // main thread
        sleep(5);
    }

}

