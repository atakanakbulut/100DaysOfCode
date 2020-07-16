#ifndef INTERPROCESS_H
#define INTERPROCESS_H

#include <unistd.h>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <queue>
#include <functional>

class InterProcess
{
public:
    InterProcess();
    ~InterProcess();
    void application();

private:
    std::queue<int> rawData;
    std::condition_variable cState;
    std::mutex locker;
    void transmittingData();
    void receivingData();

    std::shared_ptr<std::thread> m_RxThreadInstance; 
    std::shared_ptr<std::thread> m_TxThreadInstance;
};

#endif