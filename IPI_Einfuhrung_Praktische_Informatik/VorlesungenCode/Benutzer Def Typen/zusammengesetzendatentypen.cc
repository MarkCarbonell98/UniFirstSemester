#include <iostream>

int main(int argc, char const *argv[])
{
    struct Rational {
        int zaehler;
        int nenner;
    };

    Rational p;
    p.nenner = 5;
    p.zaehler = 56;
    std::cout << p.nenner << " " << p.zaehler;

    
    return 0;
}
