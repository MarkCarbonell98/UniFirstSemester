#include <iostream>

class ComplexNumber {
    private:
        double re, im;
    public:
        ComplexNumber(double newRe, double newIm) : re(newRe), im(newIm) {}

        void setRe(double newRe) {
            re = newRe;
        };
        void setIm(double newIm) {
            im = newIm;
        };

        double getRe() const {
            return re;
        };
        double getIm() const {
            return im;
        };

        ComplexNumber operator+(const ComplexNumber& z2) const {
            ComplexNumber result(0.0,0.0);
            result.setRe(z2.getRe() + re);
            result.setIm(z2.getIm() + im);
            return result;
        }
}; //Klasse

int * f() {
    const int n = 1000;
    int p[n];
    p[0] = 0;
    for(int i = 0; i < n; i++) {
        p[i+1] = p[i];
    }
    return p; //
}


int main(int argc, char const *argv[])
{
    // int * p = f();
    // std::cout << p[998] << std::endl;

    const int n = 10;
    int p[n];
    p[0] = 0;
    for(int i = 0; i < n; i++) {
        std::cout << p[i] << std::endl;
        std::cout << p[i+1] << std::endl;
        p[i+1] = p[i];
    }


    ComplexNumber c(10, 20), a(5,5), b(10,10);
    c = b + a;
    std::cout << c.getRe() << " " << c.getIm() << std::endl;
    std::cout << (c+a).getRe() << std::endl;
    std::cout << (c+a).getIm() << std::endl;
    return 0;
}


