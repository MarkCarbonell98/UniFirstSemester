//template <class T>
#include <iostream>

//template <typename T>

template <class T> void swap(T& a, T& b) {
    T t = a;
    a = b; b = t;
}

template<class T> T max(T a, T b) {
    if(a > b) return a;
    else return b;
}

class Inkrementierer {
    public: 
        Inkrementierer(int n) {inkrement = n;}
        int operator()(int n) {return n + inkrement;}
    private:
        int inkrement;
};

class Quadrat {
    public:
        int operator()(int n) {return n*n;}
};

template<class T> void schleife(T& func) {
    for(int i = 1; i < 10; i++) {
        std::cout << func(i) << "_" << std::endl;
    }
    std::cout << "_" << std::endl;
}

// statischen polymorphismus
//dynamischen Polymorphismus
//premature optimization is the root of all evil ?
//profiling
//statishen Typbindung
//dynamischer Typbindung

//parametrisierte klassen
// Klassenschablonen (class templates)

// template <class T> {};

int main() {
    int a = 10, b = 20;
    //automatische template instanzierung
    swap(a,b);
    Inkrementierer ink(10);
    Quadrat quadrat;
    schleife(ink);
    schleife(quadrat);
    printf("a = %d b = %d", a,b);
    return 0;
}