#include <fcpp.hh>

struct rational {
    int z;
    int n; 
    double total() {
        return (double)z/n;
    }
};

int main(int argc, char const *argv[])
{
    int m;
    rational * p = new rational;
    p->z = 10;
    p->n = 3;
    std::cout << p->total();
    return 0;
}
