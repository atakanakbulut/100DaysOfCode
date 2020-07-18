#ifndef PURECLASS_H
#define PURECLASS_H

class PureClass
{
    public:
        ~PureClass() {};
        virtual void doProcess() = 0;
};

#endif