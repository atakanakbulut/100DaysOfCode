#include <iostream>
#include <memory>
#include <unistd.h>

#include "Entity.h"

int main()
{
 //   std::shared_ptr<Entity> entityInstance(new Entity);

    Entity *ent = new Entity();
    ent->runApplication();

    sleep(1000);
    int val;
    std::cin >> val;
    return 0;
}