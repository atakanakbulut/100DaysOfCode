#ifndef ENTITY_H_
#define ENTITY_H_

#include <iostream>
#include <thread>
#include <memory>
#include <unistd.h>
#include <binders.h>
#include <functional>
#include <mutex>
#include <chrono>
#include <fstream>  

class Entity
{
private:
    /* data */
public:
    Entity();
    ~Entity();
    void runApplication();
private:
    std::shared_ptr<std::thread> m_ThreadInstance1; 
    std::shared_ptr<std::thread> m_ThreadInstance2;
    std::shared_ptr<std::thread> m_ThreadInstance3; 

    std::weak_ptr<std::thread> m_ThreadWeakInstance1;
    std::weak_ptr<std::thread> m_ThreadWeakInstance2;
    std::weak_ptr<std::thread> m_ThreadWeakInstance3;

    std::mutex m_threadMutex1;
    std::mutex m_threadMutex2;
    bool m_isThreadRunning1;  // should be atomic but added later
    bool m_isThreadRunning2;  // should be atomic but added later

    void runThreadApplication1(); // Standart thread example
    void runThreadApplication2(); // Start thread and work along a 20 sec 
    void runThreadApplication3(); // for detach
};

#endif 