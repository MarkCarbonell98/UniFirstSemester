#include "vector.hh"

int main(int argc, char const *argv[])
{
    std::vector<int> test1 = {1,2,3};
    std::vector<int> test2 = {4,5,6};
    Vector<int, int> a(test1, test1.size()), b(test2, test2.size());
    a.print();
    b.print();


    return 0;
}
