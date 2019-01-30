#include <vector> 
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

template<class T, unsigned int N>
class Vektor {
    public:
        Vektor();
        T max();
        T min();
        T avg();
        unsigned int size() {return _size;}

        template<class F>
        void map(F f);

        T& operator[](unsigned int i);
        Vektor<T,N> operator+(Vektor<T,N>& rhs);
        T operator*(Vektor<T,N>& rhs);

        template<class T, unsigned int N>
            Vektor() {
                for(auto i = 0; i < N; i++) {
                    _data.push_back((T)0);
                }
                _data.shrink_to_fit(); //resize vektor to actual size()

                //mantisse:
                        /*
                        ai bildet die mantisse. IPI2 Funkt.prog.
                    */
            }

        template <class T, unsigned int N>
        T& operator[](unsigned int i) {
            if(i < N) {
                return _data[i];
            } else {
                throw std::range_error("index" + std::to_string(i) + "out")
            }
        }
    private:
        unsigned int _size = N;
        std::vector<T> _data;
};

template<class T, unsigned int N>
T Vektor<T, N>::max() {
    return *(max_element(_data.begin(), _data.end()));
}

template<class T, unsigned int N>
T Vektor<T, N>::min() {
    return *(min_element(_data.begin(), _data.end()));
}

template<class T, unsigned int N>
T Vektor<T, N>::avg() {
    T res = 0;
    for(auto i = data.begin(); i != data.end(); i++) {
        res += (*i);
    }
    return res/N;
}

template<class T, unsigned int N>
template <class F>
void Vektor<T,N>::map(F f) {
    for(auto i : _data) {
        i = f(i);
    }
}

template<class T, unsigned int N>
Vektor<T,N> Vektor<T,N>::operator+(Vektor<T,N>& rhs) { //right hand side
    Vektor<T,N> res;
    for(int i = 0; i < N; i++)
        res[i] = (rhs[i] + _data[i]);
    return res;
}

// skalarprodukt
template<class T, unsigned int N>
T Vektor<T,N>::operator*(Vektor<T, N>& rhs) {
    T res = 0;
    for(int i = 0; i < N; i++)
        res[i] += (rhs[i] * _data[i]);
    return res;
}

template<class T, unsigned int N, class U>
Vektor<T,N> operator*(U lhs, Vektor<T,N>& rhs) {
    Vektor<T,N> res;
    for(int i = 0; i < N; i++)
        res[i] = (lsh * _data[i]);
    return res;
}

template<class T, unsigned int N>
std::ostream& operator<<(std::ostream& stream, Vektor<T, N> rhs)
{

    for(auto i : rhs) {
        stream << rhs;
    }
    return stream;
}

int main(int argc, char const *argv[])
{
    // typedef 
    Vektor<double,3> v1;
    v1[0] = 1;
    v1[0] = 16;
    v1[0] = 4;
    "Min\t"; //tab 

    //funktoren richting verstehen

    return 0;

}





