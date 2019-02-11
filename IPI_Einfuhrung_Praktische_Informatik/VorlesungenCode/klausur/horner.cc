#include <iostream>

//aufgabe1

                                                                

double horner(double coeffs[], int deg, double x) {
    //deg is the arr length, x is the multiplication factor
    return deg == 0 ? coeffs[0] : coeffs[deg] + x * horner(coeffs, deg-1, x);
}

double horner_it(double coeffs[], int deg, double x) {
    double result = coeffs[0];
    for(int i = 1; i <= deg; i++) {
        result = result * x + coeffs[i] ;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    double coeffs[] = {4,0,3,-2,3};
    std::cout << horner(coeffs, 4, 2);
    std::cout << horner_it(coeffs, 4, 2);
    return 0;
}
