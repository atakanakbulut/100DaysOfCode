// #pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>

template<class T>
class Queue
{
    public:
    Queue();
    bool isEmpty();
    void enqueue(T data);
    void dequeue();
    void getQueueSize();
    void pritQueue();

    private:
    struct Node
    {
        T data;
        Node *nextItem;
    };
    
    Node *end;
    Node *front;
    int queueSize;
};

#endif