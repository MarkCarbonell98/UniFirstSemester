#include <iostream>
int fib(int n) {
    int a = 0;
    int b = 1;
    int i = 0;
    for(i = 0; i < n; i=i+1) {
        int t = a+b; a = b; b = t;
    }
    return a;
}

double myFunc(double x) {
    return x*x;
}

double myFuncDeriv(double x) {
    return 2*x;
}

double myMethod(double d) {
    double s = d, e = 1, f = 1e-10;
    while(abs(e) > f) {
        e = myFunc(s)/myFuncDeriv(s);
        s -= e;
    }
    return s;
}
int main(int argc, char const *argv[])
{
    int var1 = 5;
    double a = 1e-10;
    std::cout  << a << std::endl;
    int * var2 = &var1;
    std::cout << fib(6) << std::endl;
    std::cout << *var2 << std::endl;
    std::cout << &var1 << std::endl;
    std::cout << var1 << std::endl;

    std::cout << myMethod(100) << std::endl;
    return 0;
}
