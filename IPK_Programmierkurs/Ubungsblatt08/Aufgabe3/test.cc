#undef NDEBUG
#include <cassert>
#include "point.hh"


int main(int argc, char** argv) {
    std::array<double, 3> testArray = {{1,2,3}};
    Point<double, 3> p1;
    Point<double, 3> p2(testArray);

    assert(p1.x(0) == 0);
    assert(p1.x(1) == 0);
    assert(p1.x(2) == 0);
    assert(testArray[1] == p2.x(1));
    assert(testArray[0] == p2.x(0));
    assert(testArray[2] == p2.x(2));
    assert(std::abs(p2.norm() - 3.7416573867739413295) < 0.001);
    assert(testArray[0] == p2[0]);
    assert(testArray[1] == p2[1]);
    assert(testArray[2] == p2[2]);

    return 0;
}