#include "fcpp.hh"

using namespace std;

//Aufgabe 2

//a

float determinante(float a,float b,float c, float d) {
    return((a*d) - (b*c));
}

double determinante_double(float a,float b,float c, float d) {
    return((a*d) - (b*c));
}

//b
float power(int n, int k) {
    return cond(k<=0, 1, n*power(n,--k));
}

float assoziativ_beweis(int n) {

    for(int i = 6; i <= n; i++) {
        print("i = ", i, 0);
        print("A + (B + C) is equal to", (power(10, i) + power(-10, i)) + power(10, -i), 0);

        print("(A + B) + C is equal to", power(10, i) + (power(-10, i) + power(10, -i)), "\n", 0);
    }
    return 0;
}

//aufgabe 3
int imkreis(int n) {
    int result = 0;
    for(int i = 0; i <= n; i++) {
        result += floor((n*n)/(4*i + 1)) - floor((n*n)/(4*i + 3));
    }
    return 1+ 4*result;
}

//in diese form koennte man eine naehrung an PI mit hilfe dieser Leibnitz Serie berechnen, 
// mann musste nur der Zahler von die beiden Bruchen andern sodass: 
// 2/((4*n+1)/(4*n+3)) steht. Die floor Funktions mussen entfernt werden und der Gesamte result muss am ende mal 4 multipliziert werden. Man muss also der +1 entfernen.

double naehrung_an_pi(double n) {
    double result = 0;
    for(int i = 0; i <= n; i++) {
        result += 0.0 + 2/((4*n+1)*(4*n+3));
    }
    return 4*result;
}




int main() {
    print(determinante(100, 0.01, -0.01, 100));

    print(determinante_double(100, 0.01, -0.01, 100));


    // //das Ergebnis stimmt nicht weil float bietet nur 7 Dezimalzahlen von Präsizion da ers nur 32 Bits speichern kann wo 8 fur das Exponent des Zahles reserviert sind und double bietet 64 bits von Speicher, dh, ungefahr 15 dezimalzahlen von Präsizion für Floating Point Numbers.

    // // => das Ergebnis geht nicht weil 10000.0001 grösser ist als das was ein Float speichern kann, dann rundet der Compiler die zahl automatisch um Rechnungsfehlern zu vermeiden. Das kann ausgeschaltet werden wenn man im Kommandozeile mit dem gcc compiler die Flag -ffloat--store eingibt.

    // assoziativ_beweis(14);

    //Ab n = 11 ist die Assoziativität verloren. Das ist wegen was im Aufgabe 1a schon erklärt wurde. Das handelt sich um die Form wie Floating Point Numbers gespeichert und gerechnet wurden. Zwischen jeder Schritt macht der Compiler auch kleine rundungen nach jeder Berechnung dass das Finale Ergebnis beeinflussen wie im assoziativ_beweis() schon bewiesen wurde.
<<<<<<< HEAD
    int result1 = 0, result2 = 0;
    for(int n = 0; n <= 20; n++) {
        print("The ammount of elements in the circle are: ", imkreis_improved(n),n, 0);
        // printf("calculateDivisor: %i, calculateAnotherDivisor: %i \n", calculateDivisor(n), calculateAnotherDivisor(n));
        printf("Calculate Term(n) = %i, n = %i \n", calculateTerm(n,n), n);
        // result1 += 4*n+1;
        // result2 += 4*n+3;
        // printf("result1: %i result2: %i \n", result1, result2);
    }
=======

    print("The ammount of elements in the circle are: ", imkreis(enter_int()));
>>>>>>> 034c490841d650c0d03f6d4a192e7b4d9b8a04d6

    return 0;
}

/*
    int test(int x, int y, int n) {
        return cond(x*x+y*y <= n*n, 1, 0);
    }

    int laufex(int x, int y, int n) {
        return cond(x <= n, test(x,y,n) + laufex(x+1, y, n), 0);
    }

    int block(int y, int n) {
        return cond( y <= n, test(-n, y, n) + laufex(-n+1, y, n) + block(y+1, n)),0);
    }

    int imkreis(int n) {
        return block(-n, n);
    }
*/