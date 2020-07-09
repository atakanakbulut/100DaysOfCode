#include <iostream>
#include <memory> // smart pointers
#include <vector>

class Entity
{

public:
    Entity(unsigned int id, std::string objectName) :m_objectId(id), m_objectName(objectName) { } // = default;
    ~Entity() {std::cout << m_objectId << m_objectName <<  " Dest. Called" << std::endl;}
    void printInfo() {std::cout << m_objectId << " " << m_objectName <<  " Dest. Called" << std::endl;}
private:
    std::string m_objectName;
    unsigned int m_objectId;
    
};

void changeOwnership(std::unique_ptr<Entity> &src_obj, std::unique_ptr<Entity> &dst_obj)
{
    dst_obj = (std::move(src_obj));
}

int main()
{
    {
        // ....
        Entity *e1 = new Entity(1, "Normal ptr");
        delete e1;        
        // we need delete command
    }

    {
        // ....
        std::unique_ptr<Entity> e2(new Entity(2, "Unique ptr"));
        // operation completed. Now smart ptr will delete to ptr automatically
        // otherwise unique_ptr cannot copy but we can transfer it
    }

    std::unique_ptr<Entity> srcobj(new Entity(99, "src"));
    std::unique_ptr<Entity> dstobj;

    srcobj->printInfo();
 
    // lets moves
    changeOwnership(srcobj, dstobj);

    // moved, now print another object
    dstobj->printInfo();


    // lets use with vector
    std::vector<std::unique_ptr<Entity>> EntityVector;

    EntityVector.push_back(std::make_unique<Entity>(1, " Vector1"));
    EntityVector.push_back(std::make_unique<Entity>(2, " Vector2"));
    EntityVector.push_back(std::make_unique<Entity>(3, " Vector3"));
    EntityVector.push_back(std::make_unique<Entity>(4, " Vector4"));
    EntityVector.push_back(std::make_unique<Entity>(5, " Vector5"));

    for (const auto& c : EntityVector)
    {
        c->printInfo();
    }
    
    return 0;
}