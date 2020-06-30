#include "Queue.h"

template<class T>
Queue<T>::Queue(): front(NULL), end(NULL), queueSize(0)
{
}

template<class T>
bool Queue<T>::isEmpty()
{
    return(queueSize == 0);
}

template<class T>
void Queue<T>::enqueue(T data)
{
    Node *newOne = new Node;
    newOne->data = data;
    newOne->next = NULL;
    if(isEmpty())
    {
        front = newOne;
    }
    else
    {
        end->next = newOne;
    }
    
    end = newOne;
    queueSize++;
    
    std::cout << "New queue size is " << queueSize << std::endl; 
}

template<class T>
void Queue<T>::dequeue()
{
    if(isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
        Node *temp = front;
        if(front == end)
            {
                front = NULL;
                end = NULL;
            }
        else
        {
            front = front->next;
        }
    delete temp;
    queueSize--;
    }

    std::cout << "New queue size is " << queueSize << std::endl; 
}
