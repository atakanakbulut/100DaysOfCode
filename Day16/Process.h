#ifndef PROCESS_H
#define PROCESS_H

#include <mutex>
#include <iostream>
#include <thread>

class Process
{

public:
    Process() = default;
    void doProcess()
    {
        while (true) // 12 thread
        {
            m_mutex.lock();
            std::cout << "Thread running..." << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            m_mutex.unlock();
        }
    }
private:
    std::mutex m_mutex;
};

#endif