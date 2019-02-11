#include <iostream>

int main(int argc, char const *argv[])
{
    struct Rational {int n; int d;};
    struct Complex {float re; float im;};
    
    //Union of two user-defined types
    union Combination {
        Rational p;
        Complex c;
    };

    enum Kind {rational, complex};

    struct Mixed {
        Kind a;
        Combination com;
    };
    return 0;
}
