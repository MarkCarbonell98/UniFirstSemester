#include "fehlerwert.hh"

FehlerWert::FehlerWert() : _wert(0.0), _absolute(0.0) {}

FehlerWert::FehlerWert(double a, double b) : _wert(a) , _absolute(b) {}

double FehlerWert::wert() const {
    return _wert;
}

double FehlerWert::absolut() const {
    return _absolute;
}

FehlerWert& FehlerWert::operator=(const FehlerWert& a) {
    this->_wert = a.wert();
    this->_absolute = a.absolut();
    return (*this);
}

FehlerWert FehlerWert::operator+(const FehlerWert& a) {
    FehlerWert result;
    result._absolute = std::sqrt(pow(a.absolut(),2) + pow(this->_absolute,2));
    result._wert = this->_wert + a.wert(); 
    return result;
}

FehlerWert FehlerWert::operator*(const FehlerWert& a) {
    double relativeError = std::sqrt(pow(_absolute/_wert, 2) + pow(a.absolut()/a.wert(),2));
    FehlerWert result;
    result._wert = a.wert() * this->_wert;
    result._absolute = relativeError * (result._wert);
    return result;
}

double FehlerWert::relativ() const {
    return this->_absolute/this->_wert;
}