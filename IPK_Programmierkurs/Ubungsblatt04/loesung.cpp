#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//diese funktion ist nicht Teil der Aufgabe
namespace myOwnFunctions {
    double askInput() {
        double a = 0.0;
        cout << "Please insert a value" << endl;
        cin >> a;
        if(cin.fail()) {
            cin.clear();
            cin.sync();
            cout << "The input is not valid, try again" << endl;
            throw invalid_argument("sorry :(");
        }
        return a;
    }

    double abs(double x) {
        if(x < 0) {
            x = -1*x;
        } 
        return x;
    }
}

namespace power {
    
    double iterative(double q, int n) {
        double power = 1.0;
        for(int i = 0; i < n; i++) {
            power = q * power;
        }
        return power;
    }

    int recursive(int q, int n) {
        int m = 0;
        if(n == 0) return 1;
        if(n % 2 == 0) {
            m = recursive(q, n/2);
            return m*m;
        }
        else return q*recursive(q, n -1);
        return 0;
    }

    int recursive_with_steroids(int q, int n) {
        if(n == 0) return 1;
        if(n & 1) {
            return q * recursive_with_steroids(q, n/2) * recursive_with_steroids(q, n / 2);
        }
        else return recursive_with_steroids(q, n / 2) * recursive_with_steroids(q, n / 2);

        return 0;
    }
}

//aufgabe  3c
double root_iterative(double q, int n, int steps) {
    if(q == 1) {
        return 1;
    }
    double guess = (q/2), result, counter = 0;

    while(counter < steps) {
        result = ((guess + (q/guess))/n);
        guess = result;
        counter++;        
    }
    return result;
}

//aufgabe 3c
double root_iterative_powered(double q, int n , int steps) {
    double guess = (q/2), result, counter = 0, frac = 1/(n + 0.0);
    while(counter < steps) {
        result = guess  + frac * ((q/power::iterative(guess, n - 1)) - guess);
        guess = result;
        counter++;
    }

    return result;
}

//aufgabe 3c
void test_root(double q, int n, int steps) {
    if(q == 1) {
        cout << "q = 1 \n ~a = 1 \n n = " << n << "\n q - a^~n = 0 " << endl;
        return;
    }

    double guess = (q/2), result, counter = 1;

    while(counter < steps) {
        cout << "\n \n" << "Step number " << counter << endl;
        result = ((guess + (q/guess))/n);
        guess = result;
        // cout << "q = " << finalResult << "\n n = " << n << "\n ~a = " << result << "\n ~a^n = " << potenzOfGuess << "\n q - ~a^n = " << q - potenzOfGuess << endl;

        printf("q = %g \n n = %d \n ~a = %g \n ~a^n = %g \n q - ~a^n = %g \n finalResult %g \n", q, n, guess, power::iterative(guess, n), q - power::iterative(guess, n), root_iterative(q,n,steps));
        counter++;
    }
    return;
}


int main() {

    cout << "Attention! The first value you may enter is the exponent, is the second one the base!" << endl;
    cout << "Result of iterative(a,b) = ..." << endl;
    cout << power::iterative(myOwnFunctions::askInput(),myOwnFunctions::askInput()) << endl; 

    cout << "Result of recursive(a,b) = " << endl;
    cout << power::recursive(myOwnFunctions::askInput(),myOwnFunctions::askInput()) << endl; 

    cout << "Result of recursive_with_steroids(a,b) = " << endl;
    cout << power::recursive_with_steroids(myOwnFunctions::askInput(),myOwnFunctions::askInput()) << endl; 

    cout << "Result of root_iterative(a,b,c) = " << endl;
    cout << root_iterative(myOwnFunctions::askInput(),myOwnFunctions::askInput(),myOwnFunctions::askInput()) << endl; 

    cout << "Result of root_iterative_powered(a,b,c) = " << endl;
    cout << root_iterative_powered(myOwnFunctions::askInput(),myOwnFunctions::askInput(),myOwnFunctions::askInput()) << endl;

    cout << "Result of test_root(a,b,c) = " << endl;
    cout << "Test Root starts running" << endl;
    test_root(myOwnFunctions::askInput(),myOwnFunctions::askInput(),myOwnFunctions::askInput()); 

    return 0;
}