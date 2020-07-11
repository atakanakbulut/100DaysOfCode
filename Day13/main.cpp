#include <iostream>
#include <memory>
#include <unistd.h>

#include "Entitiy.h"
#include "Foo.h"

int main()
{

    std::shared_ptr<Entitiy> e1(new Entitiy(1));
    std::shared_ptr<Entitiy> e2;

    // counters e1 or e2 not a matter
    std::cout << "smart ptr counter is " <<  e1.use_count() << std::endl;
    e2 = e1;
    std::cout << "smart ptr counter is " <<  e1.use_count() << std::endl;

    std::weak_ptr<Entitiy> e3;
    e3 = e2;
    std::cout << "smart ptr counter is " <<  e3.use_count() << std::endl;

    // Weak pointers and cycle example
    std::shared_ptr<Entitiy> sharedptr(new Entitiy(1));
    sharedptr->printObjectInfo();

    std::weak_ptr<Entitiy> weakptr;
    weakptr = sharedptr;
    // weakptr->printObjectInfo() we cannot use witch derefferance or -> operator with weak ptr
    sharedptr.reset();
    std::cout << "Shared ptr reset and now count " << sharedptr.use_count() << std::endl;
    
    // shared ptr is null but we can check with weak ptr
    // if we call without check definitely get core dump error 
    if(weakptr.lock())
    {
        sharedptr->printObjectInfo();
    }
    else
    {
        std::cout << "No any refferance for shared ptr " << std::endl;
    }

    // this usage is harmful for smart pointer so that we must be use enable_shared_from_this for smart ptr
    // implemented for Foo class
    std::shared_ptr<Foo> this1(new Foo);
    this1->getFoo();

    return 0;
}
