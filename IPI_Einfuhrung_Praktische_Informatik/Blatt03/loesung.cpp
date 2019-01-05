#include "fcpp.hh"

using namespace std;

// bool istTeilbar(int zahl, int teiler) {
//     return cond(zahl % teiler % == 0, true, false);
// }

int findDivisors(int zahl, int start) {
    return cond((zahl % start == 0), start, findDivisors(zahl, start -1));
} 

int addDivisors(int zahl, int teiler) {
    return cond(teiler == 1, 1, addDivisors(zahl, findDivisors(zahl, teiler) - 1) + findDivisors(zahl, teiler));
}

bool vollkomen(int zahl) {                                  //4      //3
    return cond(zahl % 2 == 1, false, zahl == addDivisors(zahl , zahl - 1));
}

/*
    loesung
    int teiler(int zahl, int teiler) {
        return cond(zahl % teiler == 0, teiler, 0);
    }

    int summe(int zahl, int test) {
        return cond(test >= 1, teiler(zahl, test) + summe(zahl, test -1), 0);
    }

    bool vollkommen(int zahl) {
        return cond(summe(zahl, zahl -1) == zahl, true, false);
    }
*/



//anfang aufgabe 4
int quadrat(int x) {
    return x*x;
}

int potenz(int x = 2, int exp = 5) {
    return cond(exp >= 1,
            cond(exp == 1,
            x,
            cond(exp % 2 == 1,
            x*quadrat(potenz(x,exp/2)),
            quadrat(potenz(x, exp/2)))
            , 1)
            );
    // if(exp >= 1) {
    //     if(exp == 1) {
    //         return x;
    //     } else {
    //         if(exp % 2 == 1) {
    //             return x*quadrat(potenz(x, exp/2))
    //         } else {
    //             return quadrat(potenz(x, exp/2))
    //         }
    //     }
    // } 
    // return 1;
}

int main() {
    //aufgabe 3
    print("Please insert an integer to check if its a Vollkommene Zahl");
    print(vollkomen(6));

    //aufgabe 4
    print("Please insert a base and an exponent if you want to change the actual, default is potenz(2,5)");
    print(potenz(2,5));

    // Aufgabe 4b)
    /*
        falls potenz(5,4) applikativ dann wurden die zahlen 5 und 4 genauso an
        die funktion weitergeben wie bei der normalen Reihenfolge. Falls in der 
        potenz(2+2*4/4, 8*3) geschrieben wurde, dann wurde die applikative Reihenfolge die Argumente der Funktion auswerten und dann die Ergebnisse der bewertung (namlich 4 und 24) and die Funktion weitergeben.

        Unter die selben umstanden wurde die normale Reihenfolge sich daran unterscheiden weil sie die Argumente der funktion weitergeben wurde 
        als 2+2*4/4 stets 4 und 8*3 stets 24. Die Losung wurde dann in der funktion potenz() berechnet. 

        normal 5*5*5*5
        applikativ quadrat(5) * quadrat(5);

        In dem Fall potenz(5,4) macht die Reihenfolge gar kein Unterschied.
    */
    return 0;
}