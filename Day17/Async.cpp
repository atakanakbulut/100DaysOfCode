#include "Async.h"

Async::Async()
{
}

Async::~Async()
{
}

void Async::application()
{
    bool calledFuture = false;
    while (true)
    {
        std::cout << "Application Running..." << std::endl;
        sleep(5);
        if(!calledFuture)
        {
            iotaFuture.get(); // only 1 time callable
            calledFuture = true;
        }
    } 
}

void Async::startDeferred(std::chrono::seconds sec, std::string type)
{
    std::cout << type << " Receiving data ..." << std::endl;
    std::this_thread::sleep_for(sec);
    std::cout << type << " Data received ..." << std::endl;
}

void Async::startAsync(std::chrono::seconds sec, std::string type)
{
    std::cout << type << " Receiving data ..." << std::endl;
    std::this_thread::sleep_for(sec);
    std::cout << type << " Data received ..." << std::endl;
}

int Async::startAsyncWithValue()
{
    return 1453;
}

void startPromiseObject(int a, std::promise<int> *p)
{
    p->set_value(1 + a);
}

void Async::run()
{   
  // auto result = std::async(std::launch::async, startBigOperation);

  iotaFuture = std::async(std::launch::deferred, startDeferred, std::chrono::seconds(1), "deferred");
  std::future<void> asc = std::async(std::launch::async, startAsync, std::chrono::seconds(1), "async");
  std::future<int> ret = std::async(std::launch::async, startAsyncWithValue);
  sleep(1);
  std::cout << "Return value " << ret.get() << std::endl;

  std::future<int> fut = promiseObject.get_future();
  std::thread th(startPromiseObject, 3, &promiseObject); // return from parameters ..

  std::cout << "Future value from promise " << fut.get()  << std::endl;
  application();
}
