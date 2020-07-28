#include <iostream>
#include <signal.h>
#include <unistd.h>

void signal_handler( int signal_num ) 
{ 
  std::cout << "The interrupt signal is (" << signal_num << "). \n"; 
  exit(signal_num);   
}

void func1()
{
  signal(SIGILL, signal_handler);   

  int count = 0; 
  while(++count)
  { 
      sleep(1);
      std::cout << "Running..." << std::endl; 
      if( count == 5 )  
         raise(SIGILL); 
  } 
  std::cout << "END" << std::endl; 
}

void sigintHandler(int sig_num) 
{ 
    signal(SIGINT, sigintHandler); 
    std::cout << "Only can kill with -9 signal number " <<  sig_num  << std::endl;
    fflush(stdout); 
}

void func2()
{
    signal(SIGINT, sigintHandler);
}

int main()  
{ 
  func1(); //  custom signal handling..
  func2(); // program not exit with ctrl+c

  getchar();

  return 0;
} 