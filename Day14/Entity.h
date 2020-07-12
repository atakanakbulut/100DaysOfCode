#pragma once

#include <vector>
#include <iostream>

template<class Entity>
struct S
{
    std::vector<Entity> vec;
    S(std::initializer_list<Entity> l) : vec(l)
    {
        std::cout << "Constructor called initializer list size " << l.size() << std::endl; 
    }

    void append(std::initializer_list<Entity> l)
    {
        std::cout << "Append new initializer list size " << l.size() << std::endl;
        vec.insert(vec.end(), l.begin(), l.end());
    }

    std::pair<const Entity*, std::size_t> c_arr() const
    {
        return {&vec[0], vec.size()};
    }
};

template <typename T>
void templated_fn(T) {}

