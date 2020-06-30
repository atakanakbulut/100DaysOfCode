#include <iostream>

#include "Templates.h"
#include "Devices.h"

#include "Queue.h"
#include "queueX.h"

int main()
{
    // Basic
    std::cout << "Templates " << std::endl;
    std::cout << "Integer " << getAverage<int>(1,2,3) << std::endl;
    std::cout << "Float " << getAverage<float>(1.3,2.4,3.5) << std::endl;

    // Multiple object
    Devices dv1;
    dv1.m_component = eTransitor;
    Devices dv2;
    dv2.m_component = eOpamp;
    Devices dv3;
    dv3.m_component = eRelay;
    combineComponent<Devices>(dv1, dv2, dv3);

    queueX<int> queueX;
    queueX.push(1);
    queueX.push(2);
    queueX.push(3);
    queueX.push(4);

    std::cout << queueX.top() << std::endl;

    return 0;
}