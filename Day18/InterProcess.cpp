#include "InterProcess.h"

static bool dataReceiveMode = true;
static bool dataTransmitMode = false;

InterProcess::InterProcess()
{
}

InterProcess::~InterProcess()
{
}

void InterProcess::application()
{
    m_RxThreadInstance.reset(new std::thread(std::bind(&InterProcess::receivingData, this)));
    m_TxThreadInstance.reset(new std::thread(std::bind(&InterProcess::transmittingData, this)));
}

void InterProcess::receivingData()
{
    while (true)
    {   
        std::unique_lock<std::mutex> lk(locker);
        cState.wait(lk, []{return dataReceiveMode;});
        std::cout << "\n\n== Data receiving... ==" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));

        if(rawData.size() < 100)
        {
            for(auto i = 0; i < 100; i++)
            rawData.push(i);
        }
        
        dataReceiveMode = false;
        dataTransmitMode = true;
        std::cout << "Data received OK! Now notify for data's transmit..." << std::endl;
        lk.unlock();
        cState.notify_one();
    }
}

void InterProcess::transmittingData()
{
    while (true)
    {
        std::unique_lock<std::mutex> lk(locker);
        cState.wait(lk, []{return dataTransmitMode;});
        std::cout << "\n\n == Data Transmitting... ==" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "Data:: " << std::endl;
        while (!rawData.empty()) 
        { 
            printf(" x%.2X", rawData.front());
            rawData.pop();
        }
        std::cout << std::endl;

        dataReceiveMode = true;
        dataTransmitMode = false;
        lk.unlock();
        cState.notify_one();
    }
}