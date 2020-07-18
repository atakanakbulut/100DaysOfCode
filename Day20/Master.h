#ifndef MASTER_H
#define MASTER_H

#include <iostream>
#include "PureClass.h"

class Master : public PureClass 
{
    public:
        Master();
        ~Master();
        int getData();
        virtual void doProcess() {};
    private:
        int m_value;
};

#endif