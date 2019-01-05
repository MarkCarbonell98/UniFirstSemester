#undef NDEBUG
#include <cassert>
#include <cmath>
#include "polygon.hh"
#include "point.hh"

const double PI = 3.14159;

void read_point_vector(std::vector<Point> input) {
    for(unsigned int i = 0; i <= input.size() - 1; i++) {
        printf("\n x = %g, y = %g \n", input[i].x(), input[i].y());
    }
}

std::vector<Point> generate_points(double number) {
    
    std::vector<Point> points;
    double x,y;
    for(unsigned int i = 0; i <= number - 1; i++) {
        x = std::cos((i/number) * 2*PI);
        y = std::sin((i/number) * 2*PI);
        Point p(x,y);
        points.push_back(p);
    }
    return points;
}

double calculate_polygons_area(double number) {
    if(number <= 2) {
        throw std::invalid_argument("The number you entered is too small");
    }
    double area;
    area = (number/2) * std::sin((2*PI)/number);
    return area;
}

void compare_polygons() {
    for(unsigned int i = 3; i <= 10; i++) {
        printf("The ammount of points for this polygon is: %i \n", i);
        std::vector<Point> points = generate_points(i);
        printf("The points are: ");
        read_point_vector(points);
        Polygon polygon(points);
        std::cout << " my formula: " << polygon.volume() << "\n" << std::endl;
        std::cout << " exercise formula: "<< calculate_polygons_area(i) << std::endl;
        delete &polygon;
    }
}

int main() {
    Point p(10,5);
    std::vector<Point> v;
    v.push_back(p);
    Polygon polygon(v);
    assert(p.x() == 10);
    assert(p.y() == 5);
    assert(polygon.corner(1).x() == 10);
    assert(polygon.corner(1).y() == 5);

    //Comparing all polygons in one function
    compare_polygons();
    
    return 0;
}

