#include <iostream>
#include "fcpp.hh"

int main(int argc, char const *argv[])
{
    //chars liefern ein Wert zwischen -128 && 127
    char c1 = '.';
    char c2 = 'b';
    char c3 = c1+c2;
    std::cout << c3;
    char c[10] = "Hallo!";
    for(int i = -128; i <= 127; i++) 
        print(i, (char) i, 0);

    char name[32] = "Marcos Carbonell";
    for(int i = 0; name[i] != 0; i++) 
        print(name[i]);
    print(name);
    return 0;
}
