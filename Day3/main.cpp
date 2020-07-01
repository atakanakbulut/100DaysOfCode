#include <iostream>
#include <array>
#include <algorithm>
#include <ostream>
#include <iterator>
#include <cstdlib>
#include <typeinfo>

#include "Object.h"

/*
    Requires C++17
*/


int main()
{
    std::array<int, 10> arr{13,23,333,42,52,654,7, 321};
    std::array<int, 10> arr2 = {1,2,3,4,5,6,7,8,9,10};
    std::array<int, 10> arr3 = {1,2,3};

    // sort algorithm
    std::sort(arr.begin(), arr.end());
    std::for_each(arr.begin(), arr.end(), [](int x) { std::cout << x <<" "; });
    std::cout << "\n";

    // swap to context
    std::swap(arr, arr2);
    
    for(const auto& s: arr)
        std::cout << s << ' ';

    // size
    std::cout << "Size " << arr2.size() << std::endl;

    // fill all items
    arr3.fill(10);

    for(const auto& s: arr3)
        std::cout << s << ' ';
    std::cout << "\n";

    // at first end
    std::cout << "Array at 2: " << arr2.at(2) << std::endl;

    // reverse and print output 
    std::reverse_copy(arr2.begin(), arr2.end(), 
                      std::ostream_iterator<int>(std::cout, " "));    

    std::array<Object, 10> *obj;
    (void) obj;

    // type name 
    std::cout << "\n type name " <<typeid(std::array<int, 10>::size_type).name() << '\n';

    for(std::array<int, 10>::size_type i = 0; i < 10; i++)
    {
        // it
    }
    return 0;
}