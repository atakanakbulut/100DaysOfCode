#ifndef _DEVICES_H_
#define _DEVICES_H_

#include <iostream>

enum Component
{
    eResistor = 0,
    eCapasitor,
    eRelay,
    eOpamp,
    eTransitor
};

typedef enum Component  component;

class Devices
{
private:
public:
    component m_component;
    Devices();
    ~Devices();
};

Devices::Devices()
{
}

Devices::~Devices()
{
}

#endif