#include <iostream>
#include <string.h>
#include <random>
#include "Entity.h"

typedef struct struct1
{
    int c = 3;
    int d = 4;
};

typedef struct struct2
{
    int a = 1;
    int b = 2;
    int f = 5;
};

struct Foo{};
struct Bar{};

void func1()
{
    std::cout << "Funtion 1 " << std::endl;

    int a = std::rand(); // random number gen

 //   int *ptr1 = static_cast<int*>(a);
 //   int *ptr2 = dynamic_cast<int*>(a);
    int *ptr3 = reinterpret_cast<int*>(a); // we can use only reinterpret_cast
}

void func2()
{
    std::cout << "Funtion 2 " << std::endl;

    struct1 *ss1 = new struct1;
    struct2 *ss2 = new struct2;

    ss1 = reinterpret_cast<struct1*>(ss2);

    std::cout << "ss1 c " << ss1->c << std::endl; // 3 -> 1
    std::cout << "ss1 d " << ss1->d << std::endl; // 4 -> 2
                                                // its working but not safe check func6 ..
}

void func3()
{
    std::cout << "Funtion 3 " << std::endl;

    struct1 *ss1 = new struct1;
    struct2 *ss2 = new struct2;

    ss2 = reinterpret_cast<struct2*>(ss1);

    std::cout << "ss2 a " << ss2->a << std::endl;
    std::cout << "ss2 b " << ss2->b << std::endl;
    std::cout << "ss3 f " << ss2->f << std::endl; // We can get core..
}

void func4()
{
    std::cout << "Funtion 4 " << std::endl;
    int* p = new int(65); 
    char* ch = reinterpret_cast<char*>(p);
    std::cout << *p << std::endl; // print 65
    std::cout << *ch << std::endl; // A
    std::cout << p << std::endl; // register
    std::cout << ch << std::endl; // A
}

struct mstruct 
{ 
    int x; 
    int y; 
    char c; 
    bool b; 
}; 

void func5()
{
    std::cout << "Funtion 5 " << std::endl;
    mstruct s;
    s.x = 5; 
    s.y = 10; 
    s.c = 'A'; 
    s.b = true; 

    int* ptr = reinterpret_cast<int*>(&s);

    std::cout << "Sizeof struct "<<  sizeof(s) <<  std::endl;
    std::cout << "Print to ptr value actually is equal to x "<<  *ptr << std::endl; 
    ptr++;
    std::cout << "Pointer increase +1 its equal to y " << *ptr << std::endl;
    ptr++;
    std::cout << "Pointer increase +1 its equal to c,  but character 1b int 4 byte "  << std::endl;
    
    char* ch = reinterpret_cast<char*>(ptr); // we can reinterpret to char and increse
    ch++; // 1 byte for char

    std::cout << *(reinterpret_cast<bool*>(ch)); 
}

void func6()
{
    std::cout << "Funtion 6 " << std::endl;

    Entity *e = new Entity;
    int *ptr = reinterpret_cast<int*>(e);
    *ptr = 123456;
    e = reinterpret_cast<Entity*>(ptr);
    std::cout << e->foo() << std::endl;
}

int main()
{
    func1();
    func2();
    func3();
    func4();
    func5();
   // func6();
    return 0;
}