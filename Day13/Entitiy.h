#include <iostream>

class Entitiy
{
private:
    unsigned int m_objectId;
public:
    Entitiy(unsigned int id) : m_objectId(id) {} //= default;

    void printObjectInfo()
    {
        std::cout << "object id " << m_objectId << " Object ref. " << this << std::endl;
    }

};
