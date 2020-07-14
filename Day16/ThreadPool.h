#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <iostream>
#include <thread>
#include <memory>
#include <mutex>
#include <vector>
#include <functional>
#include <chrono>
#include <sched.h>

#define MAXIMUM_THREAD_COUNT 12

class ThreadPool
{
public:
    ThreadPool() = default;
    ~ThreadPool();
    void runThreadPool();
    void runDualThread();
    void cpuAffinity(unsigned int cpu_id);
    
private:
    void sameFunction();
    void affinityFunction();

    std::vector<std::shared_ptr<std::thread>> m_thread; // 2 thread use same function
    std::vector<std::shared_ptr<std::thread>> m_threadPool; // 12 thread pool 
    std::shared_ptr<std::thread> m_threadAffinity; // run over spesific 12. thread

    std::mutex m_mutex;
};

#endif