#include "ThreadPool.h"
#include "Process.h"

ThreadPool::~ThreadPool()
{

}

void ThreadPool::runThreadPool()
{
    for(auto i = 0; i < MAXIMUM_THREAD_COUNT; i++)
    {
        std::cout << "Initliazing " << i << ". Thread... "<< std::endl;
        std::shared_ptr<std::thread> thread;
        std::shared_ptr<Process> process(new Process());
        thread.reset(new std::thread(std::bind(&Process::doProcess, process)));
        m_threadPool.push_back(thread);
    } 
}

void ThreadPool::runDualThread()
{
    for(auto i = 0; i < 2; i++)
    {
        std::shared_ptr<std::thread> thread;
        thread.reset(new std::thread(std::bind(&ThreadPool::sameFunction, this)));
        m_thread.push_back(thread);
    }

}

void ThreadPool::sameFunction()
{
    while (true)
    {
        const std::lock_guard<std::mutex> lock(m_mutex); // automatically unlock
        
        if(m_mutex.try_lock())
        {
            std::cout << "Try lock OK" << std::endl;
        }
        else
        {
            std::cout << "Try lock no OK" << std::endl;
        }

        std::cout << std::this_thread::get_id() << " Thread Running..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }    
}

void ThreadPool::cpuAffinity(unsigned int cpu_id)
{
    m_threadAffinity.reset(new std::thread(std::bind(&ThreadPool::affinityFunction, this)));
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(cpu_id, &cpuset); // core_id assign
    pthread_setaffinity_np(m_threadAffinity->native_handle(), sizeof(cpu_set_t), &cpuset);
}

void ThreadPool::affinityFunction()
{
    while (true)
    {
        // n. core %100 usage
    }  
}
