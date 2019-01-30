#include <iostream>
#include "fcpp.hh"

int main(int argc, char const *argv[])
{
    //useful to give a built int type a new name.
    //typedef ist synonym von int
    typedef int myInt;

    myInt x = 4;
    int y = 3;
    std::cout << x << " " << y << "\n";
    x = y;
    std::cout << x << " " << y;

    typedef double Punkt3d[3];

    Punkt3d a,b;
    double counter = 0.0;
    for(int i = 0; i < 3; i++) {
        a[i] = counter;
        b[i] = counter;
        std::cout << a[i] << " " << b[i];
        counter++;
    }
    return 0;
}
