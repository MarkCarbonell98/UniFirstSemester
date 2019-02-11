#include <iostream>

#include <cmath>

const double pi = 3.141523452345;

class FloatArray {
    public:
        virtual ~FloatArray() {};
        virtual float& operator[](int i) = 0;
        virtual int numIndices() = 0;
        virtual int minIndex() = 0;
        virtual int maxIndex() = 0;
        virtual bool isMember(int i) = 0;
};

class Shape {
    public:
        virtual ~Shape() {};
        virtual double area() = 0;
        virtual double diameter() = 0;
        virtual double circumference() = 0;

};

double circumference_area(Shape& shape) {
    return shape.circumference() / shape.area();
}

class Circle : public Shape {
    public:
        Circle(double r) {radius = r;}
        virtual double area()
        {
            return pi * radius * radius;
        }
        virtual double diameter() {
            return 2*radius;
        }
        virtual double circumference(){
            return 2 * pi * radius;
        }
        private:
            double radius;
};

class Rectangle : public Shape {
    public:
        Rectangle(double aa, double bb) {
            a = aa; b = bb;
        }
        virtual double area() {return a *b;}
        virtual double diameter() {
            return sqrt(a*a + b*b);
        }
        virtual double circumference()
        {
            return 2 * (a + b);
        }
    private:
        double a,b;
};

class A {
    public:
        virtual void f() {std::cout << "this runs from a";}
};

class B : public A {    
    public:
        virtual void f() {std::cout << "this runs from b";}
};

void function(A& a) {a.f();}
void function(B& b) {b.f();}

//bsp, virtual destructor
// void g(FloatArray * p) {
//     delete p;
// }

int main(int argc, char const *argv[])
{
    Rectangle square(1.0, 1.0);
    Circle circle(1.0);
    Circle unit_area_circle(1.0/sqrt(pi));
    //functions that behave like objects = functors
    std::cout << "Relationship circumference-area ";
    std::cout << circumference_area(square) << std::endl; 
    std::cout << circumference_area(circle) << std::endl; 
    std::cout << circumference_area(unit_area_circle) << std::endl; 

    A a;
    B b;
    function(a);
    function(b);

    return 0;
}
