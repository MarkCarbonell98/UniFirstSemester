#include <iostream>


int x = 3;
double a = 4.3;
int main(int argc, char const *argv[])
{
    int y = 1;
    float a = 5.0;
    {
        int y = 4;
        int a = 8;
        a = 5 * y;
        ::a = 3.14;
    }
    return 0;
}
