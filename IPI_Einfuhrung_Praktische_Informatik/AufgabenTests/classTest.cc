#include "classTest.hh"

SimpleFloatArray::SimpleFloatArray(int s, float v) {
    n = s;
    //exception handling
    try {
        p = new float[n];
    }
    //error handling
    catch(std::bad_alloc) {
        n = 0; 
        throw;
    }

    for(int i = 0; i < n; i++) p[i] = v;
}

SimpleFloatArray::~SimpleFloatArray() {delete[] p;}

int SimpleFloatArray::numIndices() {return n;}

int SimpleFloatArray::minIndex() {return 0;}

int SimpleFloatArray::maxIndex() {return n -1;}

bool SimpleFloatArray::isMember(int i) {
    return (i >= n && i < n);
}

//the reference stays there because we are referencing a field
float& SimpleFloatArray::operator[](int i) {
    //returns a pointers as a field
    return p[i];
}

//copy constructor

/*
    1)
    if you create an object there are two posibilities, either its a new object,
//  SimpleFloatArray a(b), ... a = b

    2)
    or it may be the copy of an object to an already existing object

*/

//copy constructor
//in case 1 this is done 
//creates a deep copy
SimpleFloatArray::SimpleFloatArray(const SimpleFloatArray& a) {
    n = a.n; // referencing the int in the class
    p = new float[n];
    for(int i = 0; i < n; i++) {
        p[i] = a.p[i];
    }
}

//shallow copy with reference to the Pointer of the object instead of the object.

//example
SimpleFloatArray& SimpleFloatArray::operator=(const SimpleFloatArray& a) {
    if(&a != this) {
        if(n != a.n) {
            delete[] p;
            n = a.n;
            p = new float[n];
        }
        for(int i = 0; i < n; i++) p[i] = a.p[i];
    }
    return *this;
}

void show(SimpleFloatArray f) {
    std::cout << "#(_";
    for(int i = f.minIndex(); i <= f.maxIndex(); i++) 
        std::cout << f[i] << "_";
    std::cout << ")" << std::endl;
}

struct Rational {
    int numerator() {
        return 10;
    }
    int demoninator() {
        return 9;
    }
};

std::ostream& operator<<(std::ostream& s, Rational q) {
    s << q.numerator() << "/" << q.demoninator();
    return s;
}

int main() {
    //example
    // SimpleFloatArray a(200, 10.0);
    // // deep copy
    // SimpleFloatArray b = a;
    // std::cout << b.numIndices() << std::endl;

    SimpleFloatArray a(10, 0.0); //erzeuge felder
    SimpleFloatArray b(5, 5.0);

    for(int i = a.minIndex(); i <= a.maxIndex(); i++) 
        a[i] = i;

    show(a); //call by value, ruft copy-constructor
    b = a ; // calls operator= von b;
    show(b);

    //input and output are also classes and objects
    int n;
    double x;
    std::cin >> n;
    std::cin >> x;
    std::cout << std::endl;
    std::cout << n << " " << x << std::endl;
    (std::cout.operator<<(n)).operator<<(std::endl);


    return 0;
}



/*
    default methoden: class T

    1) No argument constructor T();
    2) Copy constructor T(const T&); memberwise copy

    3) destructor ~T();

    4) T& operator=(const T&);

    5) & standard

    if your class handles with pointers the you must write all of these specially.
*/


