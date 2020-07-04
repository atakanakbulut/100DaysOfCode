#include <iostream>
#include <bits/stdc++.h> 


auto func1(auto a, auto b)
{
    return (a + b / 2);
}

class Entitiy 
{
public:
   virtual ~Entitiy() {}
};

template<class A, class B>
auto findlowerOne(A a, B b) -> decltype(a < b ? a : b)
{
    return (a < b) ? a : b;
}

int main()
{
    auto iValue1 = 5;
    auto fValue1 = 3.5;
    auto sValue1 = "Atakan";
    auto iValue2 = &iValue1;

    std::cout << "iValue1 " << typeid(iValue1).name() << std::endl; 
    std::cout << "fValue1 " << typeid(fValue1).name() << std::endl; 
    std::cout << "iValue2 " << typeid(iValue2).name() << std::endl; 
    std::cout << "sValue1 " << typeid(sValue1).name() << std::endl; 
    std::cout << "Class "   << typeid(Entitiy).name() << std::endl; 


    std::set<std::string> st;
    st.insert({"Atakan", "Akbulut", "Test1", "Test2"});

    for(auto it = st.begin(); it != st.end(); it++)
        std::cout << *it << std::endl;

    std::cout << "func1 " << func1(iValue1, fValue1) <<  std::endl;   

    // decltype function will create variable's type
    decltype(Entitiy()) val; 
    (void) val;

    // with templates
    std::cout << findlowerOne(4, 3.44) << std::endl; 

    return 0;
}