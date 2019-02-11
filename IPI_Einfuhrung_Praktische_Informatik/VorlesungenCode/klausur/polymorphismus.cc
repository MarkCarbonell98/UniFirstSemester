#include <iostream>

class Shape {
    protected:
        int _width, _height;
    public:
        Shape(int a = 0, int b = 0) {
            _width = a; _height = b; 
        }
        virtual int area() = 0;
};

class Rectangle : public Shape {
    public:
        Rectangle(int a = 0, int b = 0) : Shape(a,b) {}

        int area() {
            std::cout << "Rectangle area: ";
            return _width * _height; 
        }
};

class Triangle : public Shape {
    public:
        Triangle(int a = 0, int b = 0) : Shape(a,b) {}

    int area() {
        std::cout << "Triangle area: ";
        return (_width * _height)/2;
    }
};

int fibIterativ(int a) {
    int last = 0;
    int actual = 1;
    int temp = 1;
    for(int i = 0; i < a; i++) {
        temp = actual + last;
        actual = last;
        last = temp;
    }
    return temp;
}

int main(int argc, char const *argv[])
{
    Rectangle r(10,10);
    Triangle t(10,10);
    std::cout << r.area() <<"\n";
    std::cout << t.area() << "\n";

    Shape * shape;
    shape = &r;
    std::cout << shape->area() << "\n";

    shape = &t;
    std::cout << shape->area() << "\n";

    std::cout << fibIterativ(6);
    
    return 0;
}
