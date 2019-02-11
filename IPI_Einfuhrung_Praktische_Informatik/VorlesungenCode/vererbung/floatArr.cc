#include <iostream>
#include <cassert>

class floatArray {
    private:
        int n;
        float * p;
    public:
        floatArray();

        floatArray(int s, float v) {
            n = s;
            try {
                p = new float[n];
            } catch (std::bad_alloc) {
                n = 0;
                throw;
            }
            for(int i = 0; i < n; i++) p[i] =v;
        }
        //copy constructor (initialisierung von objekt durch ein anderes objekt)
        // copy constructor
        floatArray(const floatArray& a) {
            n = a.n;
            p = new float[n];
            for(int i = 0; i < n; i++) 
                p[i] = a.p[i];
        }
        //zuweisungsop = 
        floatArray& operator=(const floatArray& a) {
            if(&a != this) {
                if(n != a.n) {
                    delete [] p;
                    n = a.n;
                    p = new float[n];
                }
                for(int i = 0; i < n; i++) p[i] = a.p[i];
            }
            return *this; //so dass a = b = c= d geht;
        }

        ~floatArray() {delete [] p;}

        int numIndices() {return n;}

        int minIndex() {return 0;}

        int maxIndex() {return n -1;}

        bool isMember(int i) {return (i>= 0 && i < n);}

        float& operator[](int i) {
            return p[i];
        }

        friend std::ostream& operator<<(std::ostream& a, floatArray b) {
            for(int i = 0; i < b.maxIndex(); i++) 
                a << b[i];
            return a;
        }
};

void show(floatArray f) {
    std::cout << "#( ";
    for(int i = f.minIndex(); i < f.maxIndex(); i ++) 
        std::cout << f[i] << " ";
    std::cout << ")" << "\n";
}

class CheckedFloatArr: public floatArray {
    public: 
        CheckedFloatArr(int s, float f) : floatArray(s,f) {}

        virtual float& operator[](int i) {
             assert(i >= minIndex() && i <= maxIndex());
            return floatArray::operator[](i);
        }
};


int main(int argc, char const *argv[])
{
    floatArray a(10, 2.3), b(5, 5.5);

    for(int i = a.minIndex(); i <= a.maxIndex(); i++) 
        a[i] = i;

    show(a);
    b = a;
    show(b);

    std::cout << a;

    //if virtual is not used the methods used will be defined by the args passed to the functions (per overload)

    //virtual defined functions are always implemented in the derivated class. ALWAYS
    //the signature of virtual functions must be the same as the one of 

    CheckedFloatArr c(10,0);
    show(a);
    std::cout << c[10];
    std::cout << a[10]; // because [] is virtual in checked float arr;


}
