#ifndef _TEMPLATED_H_
#define _TEMPLATED_H_

#include <iostream>

template <class T>
T getAverage(T a, T b, T c)
{
    T result = ( (a + b + c) / 3 );
    return result;
}    

template <class T>
T combineComponent(T a, T b, T c)
{
    (void) a;
    (void) b;
    (void) c;
    T t;
    return t;
}

#endif