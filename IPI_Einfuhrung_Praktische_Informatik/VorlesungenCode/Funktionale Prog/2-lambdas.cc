#include "fcpp.hh"

typedef int (*F) (int n); //funktor

//similar to function.apply() js
int apply(F f, int arg) {
    return f(arg);
}

int main(int argc, char *argv[])
{
    print(apply([](int n){return n+5;}, readarg_int(argc, argv, 1))); // 1 2 3 4 5 => 6 7 8 9 10
    return 0;
}
