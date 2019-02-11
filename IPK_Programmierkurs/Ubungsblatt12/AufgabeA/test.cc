#include "point.hh"
#include "sdlwrapper.hh"

int main(int argc, char const *argv[])
{
    double d = 5;
    Point test1(1.2, 3.1), test2(3,4);
    Point a = test1;
    Point b = test2;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a = a + b;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a = a - b;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a += b;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a -= b;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a = d * b;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a = b * d;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a *= d;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    SDLCanvas("test", 1000,1000);
    return 0;
}
