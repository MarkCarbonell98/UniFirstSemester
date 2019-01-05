#ifndef POINT_HH
#define POINT_HH

#include <iostream>

class Point {
    double _x, _y;
    public:
        Point();
        Point(double x, double y);
        double x() const;
        double y() const;
};

#endif