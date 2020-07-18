#ifndef ADAPTER_H
#define ADAPTER_H

#include "IAdapter.h" 

class Adapter : public IAdapter
{
    public:
    Adapter() {};
    ~Adapter() {};
    virtual void small() {};
    virtual void medium() {};
    virtual void big() {};
};

#endif