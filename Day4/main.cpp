#include <iostream>
#include <map>
#include <algorithm>

int main()
{
    std::map<std::string, std::string> map;
    map.insert(std::make_pair("Atakan", "Akbulut"));
    map.insert(std::make_pair("Atik", "Akbulut"));
    map["Name"] = "Surname";

    std::map<std::string, std::string>::iterator it = map.begin();

    while (it != map.end())
    {
        std::cout << "First: "<< it->first << " Second: " << it->second << std::endl;
        it++;
    }

    if(map.insert(std::make_pair("Atakan", "Akbulut")).second == false)
    {
        std::cout << "Element already exist " << std::endl;
    }

    if(map.find("Atik") != map.end())
        std::cout << "Atik Exist" << std::endl;

    if(map.find("Bulut") != map.end())
        std::cout << "Bulut Exist" << std::endl;

    std::for_each(map.begin(), map.end(), [](const auto &pair) 
    {
    std::cout << "zKey: " << pair.first 
              << " zValue: " << pair.second << std::endl;
    });

    map.erase("Atik");

        for(const auto& s: map)
        std::cout << "xKey: " << s.first << " xValue: "<< s.second << "\n";
    std::cout << "\n";

    std::map<std::string, std::string> temp;

    std::cout << "Temp size " << temp.size() << " map size " << map.size() << std::endl;
    std::swap(temp, map);
    std::cout << "Temp size " << temp.size() << " map size " << map.size() << std::endl;
    
    std::map<std::string, std::string> mergeMap;
    std::map<std::string, std::string> totalMap;

    mergeMap.insert(std::make_pair("TEST0", "TEST1"));

    totalMap.merge(mergeMap);
    totalMap.merge(temp);

    // merged
    std::cout << "Merged map " << std::endl;
    std::for_each(totalMap.begin(), totalMap.end(), [](const auto &pair) 
    {
    std::cout << "mKey: " << pair.first 
              << " mValue: " << pair.second << std::endl;
    });

    return 0;
}