#include "Entity.h"


Entity::Entity()
{
    // std::swap(m_ThreadInstance1, m_ThreadInstance2); swap memory
}

Entity::~Entity()
{
    std::cout << "dtor called"<< std::endl;
    m_isThreadRunning1 = false;
    m_isThreadRunning2 = false;

    if(!m_ThreadInstance3->joinable())
    {
        m_ThreadInstance3->join();
    }
    m_ThreadInstance1->join();
    m_ThreadInstance2->join();

}

void Entity::runApplication()
{
    std::cout << "ctor called" << std::endl;
    m_ThreadInstance1.reset(new std::thread(std::bind(&Entity::runThreadApplication1, this))); // thread run
    m_ThreadInstance2.reset(new std::thread(std::bind(&Entity::runThreadApplication2, this))); // thread run
    m_ThreadInstance3.reset(new std::thread(std::bind(&Entity::runThreadApplication3, this))); // thread run
    
    m_ThreadInstance3->detach(); // thread will wait least 5 sec if we try join metot we definetly get core dump 
    if(!m_ThreadInstance3->joinable()) // so that we should use joinable methode
    {
        std::cout << "\nNot joinable" << std::endl;
    }
    else
    {
        m_ThreadInstance3->join();
    }
    
    m_ThreadWeakInstance1 = m_ThreadInstance1;
    m_ThreadWeakInstance2 = m_ThreadInstance2;
    m_ThreadWeakInstance3 = m_ThreadInstance3;

    std::cout << std::thread::hardware_concurrency()<< " concurrency supported by ryzen 5 3600" << std::endl;

}

void Entity::runThreadApplication1()
{
    m_isThreadRunning1 = true;

    while (m_isThreadRunning1)
    {
        m_threadMutex1.lock();

        std::cout << "\nthread running id:  " << std::this_thread::get_id() << std::endl << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        m_threadMutex1.unlock();
    }
}

void Entity::runThreadApplication2()
{
        std::chrono::duration<double, std::milli> elapsedtime;
        m_isThreadRunning2 = true;

        while(m_isThreadRunning2)
        {
            m_threadMutex2.lock();
            auto start = std::chrono::high_resolution_clock::now();
            std::this_thread::sleep_for(std::chrono::seconds(1));
            auto end = std::chrono::high_resolution_clock::now();
            elapsedtime += end-start;
            if(elapsedtime.count() > 10000 )
            {
                std::cout << std::endl << std::this_thread::get_id() << " I Worked 30 sec \n" << std::flush;
                m_isThreadRunning2 = false;
            }
            m_threadMutex2.unlock();
        }
}

void Entity::runThreadApplication3()
{
    std::this_thread::sleep_for(std::chrono::seconds(5)); // wait 5 sec and create atakan.file
    std::ofstream outfile ("atakan.file");
    outfile << "my text here!" << std::endl;
    outfile.close();
    std::cout << "\n File created.. " << std::endl;
}