#include "TwoDBoolArray.hh"

void printArray(TwoDBoolArray arr, int length) {
    // for(int i = 0; i < length; i++) {
    //     printf("arr[%d] = %d \n", i, arr[i][]);
    // }
} 

TwoDBoolArray::TwoDBoolArray(int n = 0, int m = 0) : _m(m), _n(n) {
    daten = daten[m*n];
    for(int i = 0; i < m*n; i++) {
        daten[i] = false;
    }
    // if(n > 0 && m > 0) {
    //     for(int i = 0; i < n;i++) {
    //         TwoDBoolArray::RowProxy row(daten, _m, _n);
    //         for(int j = 0; j < m; j++) {
    //             row[i*j] = false;
    //         }
    //         daten[i] = row[i];
    //     }
    // } else {
    //     daten = daten[m*n];
    // }
}

TwoDBoolArray::TwoDBoolArray(const TwoDBoolArray& other) {
    daten = other.daten;
    _m = other._m;
    _n = other._n;
}

TwoDBoolArray& TwoDBoolArray::operator=(const TwoDBoolArray& other) {
    daten = other.daten;
    _m = other._m;
    _n = other._n;
    return (*this);
}

TwoDBoolArray::~TwoDBoolArray() {
    for(int i = 0; i < _m*_n;i++) {
        delete &daten[i];
    }
    delete[] daten;
    delete &_m, &_n;
}

int TwoDBoolArray::rows() {
    return _m;
}

int TwoDBoolArray::cols() {
    return _n;
}

TwoDBoolArray::RowProxy::RowProxy(bool * daten, int zeilenindex, int spaltenzahl)  : _daten{daten}, _zeilenindex(zeilenindex), _spaltenzahl(spaltenzahl) {}

bool& TwoDBoolArray::RowProxy::operator[](int j) {
    return _daten[j];
}

TwoDBoolArray::RowProxy TwoDBoolArray::operator[](int i) {
    TwoDBoolArray::RowProxy result(daten, i, _n);
    return result;
}

// std::ostream& operator <<(std::ostream stream, TwoDBoolArray& array) {
//     for(int i = 0; i < array.cols(); i++) {
//         stream << "\n";
//         for(int j = 0; j < array.rows();j++) {
//             stream << array[i][j];
//         }
//     }
//     return stream;
// }

// std::istream& operator>>(std::istream& stream, TwoDBoolArray& array) {
//     std::string str;
//     std::string content = "";
//     while(std::getline(stream, str)) {
//         content += str;
//         content.push_back('\n');
//         stream >> content;
//     }
//     return stream;
// }
