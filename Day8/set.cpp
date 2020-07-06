#include <iostream>
#include <set>

int examples()
{
    std::set<int> iSet;
    std::set<int>::iterator it = iSet.begin();
    std::set<int>::iterator it1, it2;
    std::pair<std::set<int>::iterator, bool> ptr;


    // INSERT //

    ptr = iSet.insert(20);
    if(ptr.second)
    {
        std::cout << "The element was newly inserted" << std::endl;
    }
    else
    {
        std::cout << "The element was already present" << std::endl;
    }

    for (it1 = iSet.begin(); it1!=iSet.end();  ++it1) 
        std::cout << *it1 << " "; 
    
    iSet.insert(it, 25);
    iSet.insert(it, 26);

    std::cout << "\nThe set elements after 2nd insertion are : "; 
    for (it1 = iSet.begin(); it1!=iSet.end();  ++it1) 
        std::cout << *it1 << " ";

    int arr[3] = { 30, 35, 40 }; 
        iSet.insert(arr, arr+3); 

    std::cout << "\nThe set elements after 3nd insertion are : "; 
    for (it1 = iSet.begin(); it1!=iSet.end();  ++it1) 
        std::cout << *it1 << " "; 

    // INSERT // 

    // EMPLACE //

    ptr = iSet.emplace(24);
    ptr = iSet.emplace(37);
    ptr = iSet.emplace(37); // just one

    std::cout << "\n\n Emplace : ";
    for (it1 = iSet.begin(); it1!=iSet.end();  ++it1) 
        std::cout << *it1 << " ";

    iSet.emplace_hint(it,23); 

    std::cout << "\n\n Emplace Hint : ";
    for (it1 = iSet.begin(); it1!=iSet.end();  ++it1) 
        std::cout << *it1 << " ";

    // EMPLACE //

    return 0;
}


// normal print
void printSetValue(std::set<int> val)
{
    std::cout << "Normal print: ";
    for(auto itr = val.cbegin(); itr != val.cend(); ++itr)
        std::cout << *itr << " ";
    std::cout << std::endl;
}

// reverse value and print
void printReverseSetValue(std::set<int> val)
{
    std::cout << "Reverse print: ";
     for(auto itr = val.crbegin(); itr != val.crend(); ++itr)
        std::cout << *itr << " ";
    std::cout << std::endl;
}

int main()
{
    std::set<int> st1;

    // this part for mroe efficient 
    auto it = st1.begin();


    // if new insert value  lower last insert value ->  efficient same
    // if new insert value  bigger last insert value ->  efficient increase

    it = st1.insert(it, 8);
    it = st1.insert(it, 3); 
    it = st1.insert(it, 10);
    it = st1.insert(it, 1);

    // its added like binary tree
    printSetValue(st1);
    it = st1.emplace_hint(it, 35);
    printSetValue(st1);
    it = st1.emplace_hint(it, 7); // insert to between values
    printSetValue(st1);

    // reverse print
    printReverseSetValue(st1);

    // find value and print
    auto itr = st1.find(10); // not include other container class
    std::cout << "set1.find(10): " << *itr << std::endl;

    // erase
    printSetValue(st1);
    st1.erase(8);
    printSetValue(st1);

    // operational
    std::cout <<"Size: " << st1.size() << " Max size " << st1.max_size() << std::endl;

    return 0;
}