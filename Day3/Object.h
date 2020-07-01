#pragma once

#include <iostream>

class Object
{
    private:
    int m_value;

    public:
    void print()
    {
        std::cout << "Data: "<< m_value << std::endl;
    }

    void pushData(int data)
    {
        m_value = data;
    }

    int getData()
    {
        return m_value;
    }

};