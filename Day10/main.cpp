#include <iostream>
#include <tuple>

std::tuple<int, std::string> getValues1()
{
    return std::make_tuple(1, "Tuple 1");
}

std::tuple<int, std::string> getValues2()
{
    return std::tuple{2, "Tuple 2"};
}

std::tuple<int, std::string, double> getValues3()
{
    return std::tuple{3, "Tuple 3", 3.4};
}

std::tuple<int, std::string, double> getValues4()
{
    return std::tuple{4, "Tuple 4", 7.4};
}

int main()
{
    std::tuple<int, std::string> tpl1 = getValues1();
    std::cout << std::get<0>(tpl1)<< " " << std::get<1>(tpl1) << std::endl;

    // tuple cannot get dynamic value
    const int a = 0; // valid
    // int a = 0; // invalid
    std::cout << std::get<a>(tpl1)<< " " << std::get<1>(tpl1) << std::endl;

    std::tuple<int, std::string> tpl2 = getValues2();
    std::cout << std::get<0>(tpl2)<< " " << std::get<1>(tpl2) << std::endl;

    auto [t1, t2, t3] = getValues4();

    std::cout << "t1 " << t1 << " t2 " << t2 << " t3 " << t3 << std::endl;


    std::tuple<std::string, std::string> tplinit("One","Two");
    std::cout << std::get<0>(tplinit) << " " << std::get<1>(tplinit) << std::endl;

    std::string ss = std::get<0>(tplinit);

    return 0;
}