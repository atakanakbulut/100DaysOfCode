#include <iostream>
#include <set>

int main()
{
    std::multiset<int> mset;

    for(auto i = 0; i<10; i++)
    {
        mset.insert(i*10);
    }

    // add iteration begin for more efficiency do operation like binary tree
    auto itr = mset.insert(32);

    // first iterator is 32
    itr = mset.insert(itr, 42); // 42 > 32 efficiency increase
    itr = mset.insert(itr, 53); // 53 > 42 efficiency increase
    itr = mset.insert(itr, 21); // 21 < 53 efficiency same

    mset.emplace(20);
    itr = mset.emplace_hint(itr, 35); // 35 > 20 efficiency increase

    // const iterator
    for(auto itr = mset.cbegin(); itr != mset.cend(); ++itr)
        std::cout << "Const multiset : " << *itr << "\n";
    
    // const reverse iterator
    for(auto itr = mset.rbegin(); itr != mset.rend(); ++itr)
        std::cout << "Reverse const multiset " << *itr << "\n";
    
    // find iterator If successful the function returns an iterator
    // *  pointing to the sought after element
    auto findIterator = mset.find(50);
    std::cout << "mset.find(50) is " << *findIterator << std::endl;

    auto findIterator1 = mset.find(35);
    std::cout << "mset.find(35) is " << *findIterator1 << std::endl;

    // optional 
    std::cout << "Size: " << mset.size() << "Max size "<< mset.max_size() << std::endl;

    // erase
    mset.erase(21); // just this

    std::multiset<int> mset2 = {90, 70, 60, 80, 80};
    for(auto itr = mset2.cbegin(); itr != mset2.cend(); ++itr)
        std::cout << "Multiset 2 :" << *itr << std::endl;

    mset.merge(mset2);

    for(auto itr = mset.cbegin(); itr != mset.cend(); ++itr)
        std::cout << "mset + mset2  :" << *itr << std::endl;
    
    return 0;
}