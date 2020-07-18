#ifndef IADAPTER_H
#define IADAPTER_H

class IAdapter
{
    public:
    virtual ~IAdapter() {};
    virtual void small() = 0;
    virtual void medium() = 0;
    virtual void big() = 0;
};

#endif