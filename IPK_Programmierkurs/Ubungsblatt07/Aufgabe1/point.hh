#ifndef POINT_HH
#define POINT_HH

#include <iostream>
#include <algorithm>
//aufgabe 1a

class Point {
        double _x,_y;
    public:
        Point();
        Point(double x, double y );
        double x() const;
        double y() const;
        void set_x(double new_x);
        void set_y(double new_y);
};


#endif