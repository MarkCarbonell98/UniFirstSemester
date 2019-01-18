#ifndef VECTOR_HH
#define VECTOR_HH

#include <vector>
#include <iostream>
#include <iterator>
template<typename T1, typename T2>
class Vector{
    private:
        std::vector<T1> _data;
        T2 _length;
    public:
        Vector(std::vector<T1> input, T2 length) : _length(length) {
            for(std::size_t i = 0; i < _data.size(); i++) {
                _data[i].push_back(input[i]);
            }
        }

        Vector& add(const Vector input) const {
            for(std::size_t i = 0; i < _data.size(); i++) {
                _data[i] += input[i];
            }
            return (*this);
        }   

        Vector& scalarMultiplied(const double a) const {
            for(std::size_t i = 0; i < _data.size(); i++) {
                _data[i] += a;
            }
            return (*this);
        }
        T1& maximum() const {
            T1 max;
            for(std::size_t i = 1; i < _data.size(); i++) {
                if(_data[i -1] > _data[i]) {
                    max = _data[i-1];
                } else {
                    max = _data[i];
                }
            }
            return max;
        }

        T1& operator[](int i) {
            return _data[i];
        };

        void print() const {
            std::cout << "(";
            for(std::size_t i = 0; i < _data.size(); i++) {
                std::cout << _data[i] << ", ";
            }
            std::cout << ") " << std::endl;
        }
};
#endif// VECTOR_HH