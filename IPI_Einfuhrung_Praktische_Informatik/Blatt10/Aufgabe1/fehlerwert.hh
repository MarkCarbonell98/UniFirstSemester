#ifndef FEHLERWERT_HH
#define FEHLERWERT_HH

#include <iostream>
#include <cmath>

class FehlerWert {
    private: 
        double _wert, _absolute;
    public:
        FehlerWert();
        FehlerWert(double a, double b);
        FehlerWert& operator=(const FehlerWert& a);
        FehlerWert operator+(const FehlerWert& a);
        FehlerWert operator*(const FehlerWert& a);
        double wert() const;
        double relativ() const;
        double absolut() const;
};

#endif// FEHLERWERT_HH