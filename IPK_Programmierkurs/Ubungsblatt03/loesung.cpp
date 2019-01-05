#include <iostream>
#include <cmath>
#include <limits.h>


//this statements makes that the compiler automatically associates each function declared in this scope with the std:: class (just use it, don't ask much ;)
using namespace std;

//function to calculate the numbers x1 and x2
//the boolean only works to decide whether the function has to run 
// with b - root or with b + root
double formel(double a, double b, double c, bool positive) {
    double result = 0.0, root = 0.0;
    if(positive) {
        // sqrt() returns the quadratic root of its argument and pow() 
        //raises its first argument to the potence of the second (b^2) in this case
        root = sqrt(pow(b,2) - 4 * a * c);
        result = -b + root;
        result /= 2 * a;
        cout << result << endl;
    } else {
        root = sqrt(pow(b,2) - 4 * a * c);
        result = -b - root;
        result /= 2 * a;
        cout << result << endl;
    }
    return result;
}

//this is the function that organizes the results of the formel() function and 
//gives feedback depending on its results and the input
double mitternachstsFormel(double a, double b, double c, bool positive) {
    double result = 0.0;

    //if a is 0 then theres no polynom to calculate, and you cant divide through 0
    if(a == 0) {
        cout << "We can't divide through 0, please try again with other numbers" << endl;
        return 0;
    }

    //if this happens then we have an infinite number of solutions
    if(a == 0 && b == 0) {
        cout << "There is an infinite numbers of possible solutions, please try again with other numbers" << endl;
        return 0;
    }

    //if the boolean passed to this function is true, then we calculate b + root
    if(positive) {
        //here we use our formel function which makes the math for us
        result = formel(a,b,c, true);
    
    //else we calculate b - root
    } else {
        result = formel(a,b,c, false);
    }

    //this checks if the result is not at the limits of the numbers that cpp can handle, if it was bigger or equal to those numbers then it would mean that the solution is either infinite or complex
    if(result >= INT_MAX || result <= INT_MIN) {
        cout << "The solution is complex, please try again with other numbers " << endl;
        return 0;
    } 

    //is the result is nan which stands for Not A Number this is probably due to the fact that it returned null as a value, therefore there are no nullstellen to be calculated and the whole function returns 0;
    if(isnan(result)) {
        cout << "There are no nullstellen, please try again with other numbers" << endl;
        return 0;
    }

    //we return the result at the end
    return result;
}

//this is the function that puts the entire puzzle together with aufgabe 1
int aufgabe1() {

    // first we define automatic values for the inputs we'll ask from the user (doubles in this case, but they can also be integers)
    auto a = 0.0, b = 0.0, c = 0.0;
    auto x2 = 0.0, x1 = 0.0;
    cout << "please insert all variables a b c and in that specific order" << endl;

    //from here on we ask the user for input
    cout << "a = " << flush;
    cin >> a;
    cout << "b = " << flush;
    cin >> b;
    cout << "c = " << flush;
    cin >> c;

    //now we use our mitternachtsFormel to define the value of x1 and x2,
    // in case of a=b=0 or infinite solutions, it will log the information to the command line and will return 0
    x2 = mitternachstsFormel(a,b,c, true);
    x1 = mitternachstsFormel(a,b,c, false);

    //showing the information to the user (which means our result);
    cout << "the results (nullstellen) are: X1 = " << x1 << " and X2 = " << x2 << endl;
    return 0;
}

//the collatz function of aufgabe 2
//this is default argument, if the user doesnt call the function with a number there, its default value will be 0 and the program won't break
void collatz(int zahl = 0){
    //in case it is 0 we just ask the user to give his input
    if(zahl == 0) {
        cout << "it looks like the number is 0, please enter another number" << endl;
        cin >> zahl;
    }
    
    //now the magic starts, this looop will run until the number equals eigher 1,0,-1,-5 or -17
    while(zahl != 1 && zahl != 0 && zahl != -1 && zahl != -5 && zahl != -17) {

        //if the number is pair then we divide it between two and print it to the console
        if(zahl % 2 == 0) {
            zahl /= 2;
            cout << "the number is even: " << zahl << endl;
        } else {
            //else we multiply it by three and then add one to it (and also log it to the console)
            zahl *= 3;
            zahl++;
            cout << "the number is odd: " << zahl << endl;
        }
    }
    //in the end we print our final result to the console
    cout << "the final result is:" << zahl << endl;
    return;
} 


//this is our fibonacci folge 
int fibonacciFolge() {
    //first we declare the variables that she'll use, all integers
    int first = 0, second = 1, naechster = 0, n;

    //this will be used as the N described in the Aufgabe
    cout << "Please enter a positive number: " << flush;
    cin >> n;

    //here we start using first and second to start the Folge (the first numbers will always be 0,1,1)
    cout << "Fibonacci Folge: " << first << ", " << second << ", " << flush;

    naechster = first + second; //3

    // for as long as n naechster is smalles than the input n, 
    while(naechster <= n) {
        // the loop will print naechster to the console
        cout << naechster << ", " << flush;

        // redefine first as second
        first = second;
        //redefine second as naechster
        second = naechster;
        //redefine naechster as the adittion of first and second
        naechster = first + second;
    }
    //we'll exit the loop when naechster becomes greater than n, and it wont be printed to the console anymore
    return 0;
}

//bonus aufgaben:
/*
    Bonus aufgabe 1 bezieht sich nur auf den Fall dass wir eine Rekursive version von fibonacciFolge schreiben ungefahr so: 

    int fib(int x) {
    if (x == 0)
        return 0;

    if (x == 1)
        return 1;

    return fib(x-1)+fib(x-2);
    }

    wo der O(n) Komplexiaet bei O(2^n) liegt. Weil jedes mal das das algorithmus lauft muss es fib(n - 1) und fib(n - 2) auch berechnen pro elementare Einheit von N (also 1)  Wegen mathematische grunden, das input steigt exponentiel je hoher das input von N ist.

    In diesem Fall, ist diese Frage fur uns uninteresant, da fibonacciFolge eine Laufzeit von 0(n) hat, was deutlich schneller ist als O(2^n);

    Die zweite Bonusaufgabe ist schon beantwortet da unserem fibonacciFolge schon optimal funktioniert. 
}

*/

int main() {
    cout << "starting aufgabe 1" << endl;
    //call aufgabe1 function (also linked to formel() and mitternachstFormel() functions)
    aufgabe1();
    cout << "Aufgabe 1 is finished" << endl;
    cout << "starting Collatz (aufgabe 2)" << endl;
    //call collatz for the input 53
    collatz(53);
    cout << "finished Collatz (aufgabe 2)" << endl;
    cout << "starting fibonacci folge (aufgabe 3)" << endl;
    //call fibonacci
    fibonacciFolge();
    return 0;
}

//hope it was useful to you guys, have fun and a nice day ;) 

