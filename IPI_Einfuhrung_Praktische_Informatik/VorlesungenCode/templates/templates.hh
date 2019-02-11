#ifndef TEMPLATES_HH
#define TEMPLATES_HH

#include <iostream>
template<class T, int dim>
//member functions must also be parametrised with templates, the return type should also be specified. array<T>&

//constructor and destructor dont require parameters
class array {
    public:
        array(int s, T f) : _length(s), _value(f) {};
        void print() {
            std::cout << _length << " " << _value;
        }

        template<class T>
        array(const array<T>& a);

        template<class T>
        array<T>& operator=(const array<T>&);
        ~array();

        template<class T>
        T& operator[](int i);
    private:
        int _length;
        T * _value;
};


#endif// TEMPLATES_HH