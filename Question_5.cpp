#include <iostream>
#include <thread>

void function1()
{
    std::cout<<"Hello World1";
}

void function2()
{
    std::cout<<"Hello World2";
}

int main()
{
    std::thread worker1(function1);
    std::thread worker2(function2);
    
    return 0;
}