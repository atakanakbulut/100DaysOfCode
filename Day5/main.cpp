#include <iostream>
#include <algorithm>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, std::string> umap = { {"RED","#FF0000"}, {"GREEN","#00FF00"}, {"BLUE","#0000FF"} };
    std::unordered_map<std::string, std::string> umap2 = { {"Test1","#FF0000"}, {"Test2","#00FF00"}, {"Test3","#0000FF"}, {"Test4","#0000FF"} };
    std::unordered_map<int, char> umap3{{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}};

    auto print = [](std::pair<const int, char>& n) { 
        std::cout << " " << n.first << '(' << n.second << ')'; 
    };

    std::unordered_map<std::string, std::string> umapContainer;
    
    // insert
    umap.insert(std::make_pair("GRAY", "#808080"));

    // Iterate and print keys and values of unordered_map
    for( const auto& n : umap ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }

    std::cout << "Gray color's value is" <<umap["GRAY"] << std::endl;
    
    if(umap.insert(std::make_pair("RED", "FF0000")).second == false)
    {
        std::cout << "Element already exist " << std::endl;
    }

    // usage with foreach
    std::for_each(umap2.begin(), umap2.end(), [](const auto &pair) 
    {
    std::cout << "Key: " << pair.first 
              << " Value: " << pair.second << std::endl;
    });

    // swap 2 map
    std::swap(umap, umap2);

    // merge to container
    umapContainer.merge(umap2);
    umapContainer.merge(umap);


    std::cout << "Merged map size " << umapContainer.size() << std::endl;
    for( const auto& n : umapContainer ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }

    std::cout << "Bucket RED " << umapContainer.bucket("RED") << std::endl;
    std::cout << "Bucket Test3 " << umapContainer.bucket("Test3") << std::endl;
    std::cout << "Bucket Size " << umapContainer.bucket_count() << std::endl;

    if(umapContainer.find("Test2") != umapContainer.end())
        std::cout << "Test2 Exist" << std::endl;

 
    auto nh = umap3.extract(1);
    nh.key() = 4; 
 
    std::cout << "After extract and before insert:";
    std::for_each(umap3.begin(), umap3.end(), print);
    std::cout << '\n';
 
    // Insert node handle back
    umap3.insert(move(nh));
 
    std::cout << "End:";
    std::for_each(umap3.begin(), umap3.end(), print);
    std::cout << '\n';


    return 0;
}