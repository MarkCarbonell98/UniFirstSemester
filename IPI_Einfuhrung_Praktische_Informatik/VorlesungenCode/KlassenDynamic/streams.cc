//streams are objects too
#include <iostream>

int main(int argc, char const *argv[])
{
    int n = 10;
    std::cout << n << std::endl;
    (std::cout.operator<<(n)).operator<<(std::endl);
    //std::ostream& operator<<(std::ostream& a)...;
    return 0;
}
