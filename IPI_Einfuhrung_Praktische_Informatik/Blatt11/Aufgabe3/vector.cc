#include "vector.hh"

Vector::Vector(T2 length) : _data(length), _length(length) {}

Vector::Vector(std::vector<T1> input, T2 length) : _length(length) {
    for(std::size_t i = 0; i < _data.size(); i++) {
        _data[i] = input[i];
    }
}

Vector& Vector::add(const Vector a) const {
    
}