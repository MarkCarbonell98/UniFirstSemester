#include "point.hh"
#include "polygon.hh"

int main() {
    Point p(0,0), q(10,0), m(0,10);
    printf("x: %g y: %g \n", p.x(), p.y());

    std::vector<Point> v;
    v.push_back(q);
    v.push_back(m);
    v.push_back(p);
    Polygon triangle(v);
    printf("The ammount of corners is: %i, and the second corner is x = %g, y = %g", triangle.corners(), triangle.corner(2).x(), triangle.corner(2).y());

    std::cout << "\n " << triangle.volume() << std::endl;
    
    return 0;
}