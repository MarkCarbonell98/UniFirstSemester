#ifndef VECTOR_HH
#define VECTOR_HH

#include <vector>
#include <iostream>
#include <iterator>
template<typename T1, T2>
class Vector{
    private:
        std::vector<T1> _data;
        T2 _length;
    public:
        Vector(T2, length);
        Vector(std::vector<T1> input, T2 length);
        Vector& add(const Vector a) const;
        Vector& times(const double scalar) const;
        T1& maximum() const;
        T1& operator[](int i);
};
#endif// VECTOR_HH