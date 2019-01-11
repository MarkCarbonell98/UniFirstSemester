#ifndef SHAPE_HH
#define SHAPE_HH

#include <iostream>
#include <cmath>

const double pi = 3.14159;

class Shape{
    public:
        virtual ~Shape() {};
        virtual double area() = 0;
        virtual double diameter() = 0;
        virtual double circumference() = 0;
};

#endif// SHAPE_HH