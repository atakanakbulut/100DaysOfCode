#ifndef ENTITY_H
#define ENTITY_H

#include <stdlib.h>
#include <iostream>

class Entity
{
public:
    Entity(int val) : m_value(val) 
    {

    };

    void roll() const
    {
        (const_cast<Entity*>(this))-> m_value =  rand() % 100 + 1 ;
    }

    void printRoll()  
    { 
        std::cout << "Roll " << m_value << std::endl;
    } 

    ~Entity() {};
private:
    int m_value;
};


#endif