#include <iostream>
#include <vector>
#include <unordered_map>

class Entitiy;

class DeviceManager
{
private:
    std::unordered_map<std::string, std::vector<Entitiy*>> dm;
public:
    const auto &getDevices() const
    {
        return dm;
    }
};

int main()
{
    std::cout << "Auto" << std::endl;
    std::vector<std::string> stringList;
    stringList.push_back("Gray");
    stringList.push_back("Black");
    stringList.push_back("Orange");

    // with standart iterator
    for(std::vector<std::string>::iterator it = stringList.begin(); it != stringList.end(); it++ )
    {
        std::cout << "Standart Iterator " <<*it << std::endl;
    }

    // with auto 
    for(auto it = stringList.begin(); it != stringList.end(); it++)
    {
        std::cout << "Auto " <<*it << std::endl;
    }

    DeviceManager dm;
    
    // without auto 
    // std::unordered_map<std::string, std::vector<Entitiy*>> &deviceMan = dm.getDevices();

    // with auto
    auto &deviceMan = dm.getDevices();


    return 0;
}