#ifndef POINT__HH
#define POINT__HH

#include <iostream>

class Point {
    private:
        double _x, _y;
    public:
        Point() : _x(0.0), _y(0.0) {}

        Point(double x, double y) : _x(x), _y(y) {}

        Point(const Point& a) : _x(a._x), _y(a._y) {}

        double x() const {
            return _x;
        }

        double y() const {
            return _y;
        }

        Point& operator=(const Point& b) {
            _x = b._x;
            _y = b._y;
            return *this;
        }

        Point operator+(const Point& b) {
            Point c = Point(_x+b.x(), _y+b.y());
            return c;
        }

        Point operator-(const Point& b) {
            Point c = Point(_x-b.x(), _y-b.y());
            return c;
        }

        Point& operator+=(const Point& b) {
            _x += b._x;
            _y += b._y;
            return *this;
        }

        Point& operator-=(const Point& b) {
            _x -= b._x;
            _y -= b._y;
            return *this;
        }

        Point operator*(const double d) {
            return Point(_x*d, _y*d);
        }

        friend Point operator*(const double d, Point& a) {
            return a * d;
        }

        Point& operator*=(const double d) {
            _x *= d;
            _y *= d;
            return *this;
        }

        
        friend std::ostream& operator<<(std::ostream &out, const Point &a) {
            out << "(" << a.x() << "," << a.y() << ")";
            return out; 
        };

};

#endif // POINT__HH