#ifndef ASYNC_H
#define ASYNC_H

#include <iostream>
#include <future>
#include <thread>
#include <unistd.h>

class Async
{
public:
    Async();
    ~Async();
    void application();
    static void startDeferred(std::chrono::seconds sec, std::string type);
    static void startAsync(std::chrono::seconds sec, std::string type);
    static int startAsyncWithValue();
    void run();
private:
    std::future<void> iotaFuture;
    std::promise<int> promiseObject;
    /* data */
};

#endif