#include <iostream>
#include <string.h>

#include "Entity.h"

void func1()
{
    const unsigned char *Passwd = 0;
    //  *Passwd = 2; -> cannot casting because of const parameter..
    unsigned char *newPass = const_cast<unsigned char *>(Passwd);
    static_cast<void>(newPass);
}

void func2(const char* buffer)
{
   char* p = const_cast<char*>(buffer);
   buffer = const_cast<const char *>(p);
   std::cout << "Buffer " << *buffer << std::endl;
}

void func3()
{
   const int a = 20;
   const int* b = &a;
   std::cout << " Old value is "<< *b << std::endl;
   int* c = const_cast<int *>(b);
   *c = 40;
   std::cout << " New value is " << *b << std::endl;
}

void func4()
{
    int i = 0;
    const int& ref = i;
    const int* ptr = &i;
    const_cast<int&>(ref) = 3;
    *const_cast<int*>(ptr) = 3;
}

int main()
{
    func1();
    const char *ch = "1";
    func2(ch);
    func3();

    Entity e(3);
    e.roll();
    e.printRoll();
    
    return 0;
}