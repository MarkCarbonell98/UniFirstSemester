#include "point.hh"
//aufgabe 1a
Point::Point() : _x(0), _y(0) {}

Point::Point(double x, double y) : _x(x), _y(y) {}

double Point::x() const {
    return _x;
}

double Point::y() const {
    return _y;
}

//these funcitons are only for practice purposes
void Point::set_x(double new_x) {
    _x = new_x;
}

void Point::set_y(double new_y) {
    _y = new_y;
} 





