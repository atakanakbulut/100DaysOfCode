#include <iostream>
#include <unistd.h>
#include <memory> // smart pointers
#include <thread>
#include <binders.h>
#include <mutex>

class Entity
{   
    public:
        Entity(unsigned int id) : m_getObjId(id) {} // = default;

        void show()
        {
            std::cout << "Entitiy show() to " << m_getObjId << " This ptr " << this << std::endl;
        }

        unsigned int getObjectId()
        {
            return m_getObjId;
        }

    private:
        unsigned int m_getObjId;

};

// Thread usage
class Work
{
    public:
        Work() = default;

        void printObjectInfo() 
        {
            std::cout << "Object address is " << this << std::endl;
        }

        void doProcess1()
        {
            while(true)
            {
                m_mutex.lock();
                m_threadCounter++;
                usleep(1000000);
                std::cout << "WORK " << std::this_thread::get_id() <<  " counter " << m_threadCounter << std::endl;
                m_mutex.unlock();
            }
        }

        void runThread1()
        {
            m_threadInstance1 = std::make_shared<std::thread>((std::bind(&Work::doProcess1, this)));
        }

        std::shared_ptr<std::thread> m_threadInstance1;
        std::shared_ptr<std::thread> m_threadInstance2;


    private:
        unsigned int m_threadCounter;    
        std::mutex m_mutex;
};

int main()
{
    std::shared_ptr<Entity> p1(new Entity(1));
    p1->show();
    std::cout << "p1 " <<p1->getObjectId() << "==>" << p1.get() << std::endl;

    std::shared_ptr<Entity> p2(new Entity(2));
    p2->show();
    std::cout << "p2 " << p2->getObjectId() << "==>" << p2.get() << std::endl;

    std::cout << "now p3 is show to p1 same time" << std::endl;
    std::shared_ptr<Entity> p3(p1);
    p1->show();
    p3->show();
    std::cout << "p3 "  << p3->getObjectId() << "==>" << p3.get() << std::endl;

    // thread usage;
    std::shared_ptr<Work> src(new Work);
    std::cout << "src object address " << std::endl;
    src->printObjectInfo();
    src->runThread1();
    
    // wait 3 sec before check thread
    sleep(3);

    // now we try running thread object copy/share to another one
    std::shared_ptr<Work> dst(src);

    std::cout << "lets check did we share object should be same address" << std::endl;
    std::cout << "dest object address "<< std::endl;
    dst->printObjectInfo();
    src->printObjectInfo();
    
    int a;
    std::cin >> a;

    return 0;
}