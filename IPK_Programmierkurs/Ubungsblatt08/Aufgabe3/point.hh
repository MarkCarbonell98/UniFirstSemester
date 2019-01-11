#ifndef POINT_HH
#define POINT_HH

#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>
#include <iomanip>

template<typename Coord, int dim>
class Point {
    std::array<Coord, dim> _point;
    public: 
        using Coordinate = Coord;
        static const int dimension = dim;
        Point() {
            for(int i = 0; i < dim; i++)
                _point[i] = 0;
        }

        Point(std::array<Coord, dim> input) {
            for(int i = 0; i < dim; i++)
                _point[i] = input[i];
        }

        Coord& x(int i) {
            return _point[i];
        }

        double norm() const {
            double result;
            for(auto number : _point)
                result += pow(number,2);
            return std::abs(std::sqrt(result));
        }

        Coord& operator[](int i) {
            return _point[i];
        }

        const Coord& operator[](int i) const {
            return _point[i];
        }

        void print_point() {
            for(int i = 0; i < dim; i++)
                std::cout << _point[i] << std::endl;
        }
};


#endif