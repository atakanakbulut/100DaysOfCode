#ifndef ENTITY_H
#define ENTITY_H

#include <stdlib.h>
#include <iostream>

class Entity
{
public:
    Entity() = default;
    ~Entity();
    std::string foo() { std::cout << "We can get core " << m_value << std::endl;};
private:
    std::string m_value;
};


#endif