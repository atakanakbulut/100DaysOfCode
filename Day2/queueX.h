#include <iostream>
#include <queue>

template <typename T, class Q = std::queue<T>>
class queueX
{
    public:
        void push(T&& o)
        {
            queue.push(std::move(o));
        }

        const T& top()
        {
            return private_top(queue);
        }

    private:
        Q queue;

        template <typename Queue>
        static
        auto private_top(Queue& queue) -> decltype(queue.top())
        { 
            return queue.top();
        }

        template <typename Queue>
        static
        auto private_top(Queue& queue) -> decltype(queue.front())
        { 
            return queue.front();
        }

};