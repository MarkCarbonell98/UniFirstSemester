#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int n = 10;
    // static int i = 0;
    int sum = 0;
    for(int j = 1; j <= n; j = j+ 1) {
        sum = sum + j;
    }

    std::cout << sum << std::endl;
    return 0;
}

//der compiler hangt da es eine uninisialisierte Variable i im code steht

/*
    ergibt on compile: 

    $ g++ -Wall legalbutwrong.cc
legalbutwrong.cc: In function 'int main(int, char**)':
legalbutwrong.cc:7:22: warning: 'i' is used uninitialized in this function [-Wuninitialized]
     for(int j = 1; i <= n; j = j+ 1) {

das passiert weil der variable ist nicht mit der Static keyword definiert. 
deswegen crash der Compiler weil er nicht weiss was fuer ein Wert an i zu setzen.

Die losung ist einfach i mit j in der for-loop zu ersetzen und dann ergibt das Program das erwunschte Ergebnis von 55

:) danke euch 
*/