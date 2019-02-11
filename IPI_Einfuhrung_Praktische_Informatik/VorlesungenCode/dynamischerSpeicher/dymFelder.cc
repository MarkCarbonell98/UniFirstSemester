#include <fcpp.hh>

struct rational {
    int z;
    int n;
};

int f() { //returns nullptr because the variable p was deleted, but the pointer still lives
    rational * p = new rational;
    p->n = 50;
    delete p;
    return p->n;
}

int f2() {
    rational * p = new rational;
    p->n = 50;
    return p->n;
}

int main(int argc, char const *argv[])
{
    int n = 18;
    int * q = new int[n];
    q[5] = 10;
    delete [] q;
    std::cout << q[0] << "\n";
    std::cout << f() << "\n";
    
    std::cout << f2() << "\n";
    return 0;
}
