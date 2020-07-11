#include <iostream>
#include <memory>

class Foo : public std::enable_shared_from_this<Foo> 
{
private:
public: 
    Foo() {std::cout << "Foo class "<< this << std::endl; }
    ~Foo() {std::cout << "~Foo....\n";}
    void foo() 
    {
        std::cout << "Thing::foo() ... \n";
    }

    std::shared_ptr<Foo> getFoo() 
    { 
        std::cout << "Shared from this "<<  shared_from_this() << std::endl;
        return shared_from_this(); 
    }
};

