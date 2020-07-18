#include <iostream>

#include "Master.h"
#include "PureClass.h"
#include "IAdapter.h"
#include "Adapter.h"

int main()
{
    std::cout << "Abstract class" << std::endl;
    Master *m = new Master();
    auto data = m->getData();
    IAdapter *adap = new Adapter();

    return 0;
}