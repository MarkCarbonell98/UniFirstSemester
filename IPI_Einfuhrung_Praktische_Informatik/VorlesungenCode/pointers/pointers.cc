#include <iostream>

struct rational {
    int n;
    int d;
};

int main(int argc, char const *argv[])
{
    rational q;
    rational * p = &q;
    p->n = 5;
    p->d = 4;
    std::cout << q.n << q.d;
    
    return 0;
}
