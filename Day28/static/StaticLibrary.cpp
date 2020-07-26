#include <iostream> 
#include "StaticLibrary.h"

StaticLibrary::StaticLibrary(){};
StaticLibrary::~StaticLibrary(){};

void StaticLibrary::fun(void) 
{ 
  std::cout << "Static Library " << std::endl;
} 