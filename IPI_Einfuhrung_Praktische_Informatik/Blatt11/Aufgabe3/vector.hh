#ifndef VECTOR_HH
#define VECTOR_HH

#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

template<typename T1, typename T2>
class Vector{
    private:
        std::vector<typename T1::value_type> _data;
        T2 _length;
    public:

        Vector() {
            _data = {};
            _length = 0;
        }

        Vector(const Vector &input) {
            _data = input._data;
            _length = input._length;
        }

        Vector& operator=(const Vector input) {
            _data = input._data;
            _length = input._length;
        }

        Vector(T1 input, T2 length) : _length(length) {
            for(auto i : input) {
                _data.push_back(i);
            }
        }

        Vector& add(Vector input) {
            for(T2 i = 0; i < _length; i++) {
                _data[i] += input._data[i];
            }
            return (*this);
        }   

        Vector& scalarMultiplied(const double a) {
            for(T2 i = 0; i < _length; i++) {
                _data[i] *= a;
            }
            return (*this);
        }

        typename T1::value_type maximum() const {
            typename T1::value_type max;
            for(T2 i = 1; i < _length; i++) {
                if(_data[i -1] > _data[i]) {
                    max = _data[i-1];
                } else {
                    max = _data[i];
                }
            }
            return max;
        }

        typename T1::value_type& operator[](int i) {
            return _data[i];
        };

        void print() const {
            std::cout << "(";
            for(T2 i = 0; i < _length; i++) {
                std::cout << _data[i] << ", ";
            }
            std::cout << ") " << std::endl;
        }

        typename T1::value_type begin() {
            return _data[0];
        }

        typename T1::value_type end() {
            return _data[_length-1];
        }
};
#endif// VECTOR_HH