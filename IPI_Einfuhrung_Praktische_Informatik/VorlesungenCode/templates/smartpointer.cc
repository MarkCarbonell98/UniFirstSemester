#include "smartpointer.hh"
#include <iostream>

int g(ptr<int> p){
    return *p;
}

int main(int argc, char const *argv[])
{
    ptr<int> q = new int(17);
    std::cout << *q << std::endl;
    int x = g(q);
    std::cout << x << std::endl;
    ptr<int> z = new int(22);
    q = z;
    std::cout << *q << std::endl;
    return 0;
}


