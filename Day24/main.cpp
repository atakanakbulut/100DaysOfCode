#include <iostream>
#include <string.h>
#include <random>

class BaseClass
{
 
public:
 
    virtual void print(){ std::cout << "BaseClass" << std::endl;};
};
 
class SubClass: public BaseClass
{
public:
    virtual void print() {std::cout << "SubClass" << std::endl;};
 
}; 

void func1()
{
    BaseClass *b1 = new BaseClass();
    BaseClass *b2 = new SubClass(); // gizli dönüştürme işlemi vardır dynamic cast kullanılabilir.
    BaseClass *b3;

    if ((b3 = dynamic_cast<SubClass*>(b1)) == NULL)
        std::cout << "b1 SubClass degil." << std::endl;

    if ((b3 = dynamic_cast<SubClass*>(b2)) == NULL)
        std::cout << "b2 SubClass degil." << std::endl;

    b3->print();
    
    delete b1;
    delete b2;
}   

void func2()
{

}

int main()
{
    func1();


    return 0;
}