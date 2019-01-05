#include "fcpp.hh"

using namespace std;

// aufgabe 2a

int binomialkoeffizient(int n, int k) {
    return cond(k == 0 || k == n, 1, binomialkoeffizient(n-1,k-1) + binomialkoeffizient(n-1, k));
}

//n = 33,
//k = 16 dauert langer als 10sek

// O(n) = n^2
// die Funktion muss zweimal laufen pro n die eingesetzt wird. Deswegen n*n = n^2 was die komplexitat des Algorithmus betragt.



//beim n = 34 und k = 18 die Menge an Speicher dass die returned zahl maximal haben kann, wurde uberwinden. Das führt zu eine Invertierung von die Bits des Zahles, was natürlich eine negative Zahl ergibt. 


// aufgabe 2c	  
long long int factorial(long long int n) {
    return cond(n <= 1, 1, n*factorial(n - 1));
}

// O(n) = n

long long int binomialkoeffizient_efficient(long long int n,long long int k) {
    return cond(k > n, -1, factorial(n)/(factorial(k) * factorial(n - k)));
}
//O(n) = 3n

//Man stellt fest dass den algorithmus binomialkoeffizient_efficient nicht den richtigen wert mit hoheren werten zuruckgibt, da der Menge an Speicher des ints kleiner ist als die der binomialkoeffizient Funktion, die langsamer ist, aber liefert grossere Ergebnisse mit Korrektheit. 


//Aufgabe 2d


//beispiel des algorithmus im code 
/*
                     funktion erhalt nur ein parameter(der anzahl an zeilen)
    void printPascal(int n) {

                           dann lauft die Funktion einmal pro zeile, also line < n,
                           line also entspricht der nummer die wir als n beim die binomialkoeffizient_efficient funktion spater brauchen werden
        for(int line = 0; line < n; line++) {

                            dann ist i der zahl dass wir jetzt drucken mussen
            for(int i =0; i <= line; i++) {

                            drucken wir die zahlen
                printf("%d ", binomialkoeffizient_efficient(line, i));
            }
               und die zeile (pro line)
            printf("\n");
        }
        return;
}

*/

// O(n) = 3n^3
// weil das algorithmus muss zu erst n mal laufen pro n Linien dass es drücken muss. Das multipliziert man mit der anzahl an Zahlen dass jeder Linie haben wird, je hoher die anzahl an zahlen je langer werden die Linien, dh n*n. Und als letztes ruft er die binomialkoeffizient_efficient Funktion dass eine Komplexitaet von 3n hat.  

//dh die gesamte Komplexität betragt n*n*3n = 3n^3


int main() {
    print("The binomial coefficient is: ");
    print(binomialkoeffizient(enter_int(),enter_int()));

    print("The efficient binomial coefficient is:");
    print(binomialkoeffizient_efficient(enter_int(), enter_int()));

    return 0;
}