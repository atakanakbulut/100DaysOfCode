#include <iostream>
#include <vector>
#include <initializer_list>

#include "Entity.h"

int main()
{
    S<int> s = {1, 2, 3, 4, 5}; // copy list-initialization
    s.append({6, 7, 8}); // initializer list appent to vector
    
    // lets check vector's state
    std::cout << "The vector size is now " << s.c_arr().second << " ints:\n";

    // now print elements
    for(auto v : s.vec)
        std::cout << v << " ";
    std::cout << std::endl;

    for (int x : {-1, -2, -3}) // the rule for auto makes this ranged-for work
        std::cout << x << ' ';
    std::cout << '\n';
    
    auto al = {10, 11, 12}; 

    templated_fn<std::initializer_list<int>>({1, 2, 3, 4, 5});
    templated_fn<std::vector<int>>(al);

    return 0;
}
