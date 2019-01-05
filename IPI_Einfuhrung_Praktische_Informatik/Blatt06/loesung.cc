#include "fcpp.hh"
#include <array>
#include <algorithm>
#include <iterator>

using namespace std;

//AUFGABE 1A && 1B

//function to find roots of, feel free to change the argument b, as default
double func(double x, double b = 2) {
    return x*x - b;
}

//Intervallhalbierung function of Aufgabe 1A with iterator counter included
double wurzel_iterative(double a, double b) {
    double error_margin = 1e-15, middle_value = (a+b)/2 + 0.0;
    int iteration_count = 0;
    if(func(a) * func(b) == 0) return a;
    while(abs(a - b) > error_margin) {
        iteration_count++;
        middle_value = (a+b)/2;
        if(func(a) *func(middle_value) < 0) {
            b = middle_value;
        } else if (func(b) * func(middle_value) < 0) {
            a = middle_value;
        } 
    }
    printf("iterations: %i \n", iteration_count);
    printf("result: ");
    return middle_value;
}

//function analog to the function wurzel(double a) seen in the VL, implemented with Intervallhalbierung in a more efficient way.
double wurzel_vorlesung_analog(double base) {
    double result, accumulator = 1.0;
    int iteration_count = 0;
    while(true) {
        iteration_count++;
        result = (base/accumulator + accumulator)/2;
        if(result == accumulator) break;
        accumulator = result;
    }
    printf("Iterations: %i \n", iteration_count);
    return result;
}

//AUFGABE 3

//fill_array asks the user for numerical inputs and fills an array with them according to the functionality asked by Aufgabe 3
int *fill_array() {
    cout << "\nPlease insert a number to push into the array" << endl;
    static int accumulator[10];
    int a;
    int i = 0;
    //i < 10
    while(true) {
        cout << "enter int = " << flush;
        cin >> a;
        if(a == -1){
            exit(EXIT_FAILURE);
        } else if (a == 0) {
            sort(accumulator, accumulator + 10);
            return accumulator;
        } else if(i >= 10) {
            throw invalid_argument("The array is already full");
        } else if(a < -1){
            throw invalid_argument("The array cannot contain negative numbers");
        } else {
            accumulator[i] = a;
        }
        i++;
    }
}

//aufgabe 4
//function to check if the deck is in order.
bool deck_check(int deck[], int n) {
    for(int i = 0; i < n; i++) {
        if(deck[i] != i) return false; 
    }
    return true;
}

//function that fills a deck with cards coded from 0 to 51 as the card values. Length 52 defined in main()
void build_deck(int *deck, size_t length) {
    for(unsigned int i = 0; i <= length - 1; i++) {
        deck[i] = i;
    }
}

// function to print the array contents to the console
void print_array_to_console(int array[], size_t length) {
    printf("\nArray(");
    for(unsigned int i = 0; i <= length - 1; i++) {
            printf("%i, ", array[i]);
    }
    printf(")");
}

//simulates the perfect out shuffle and returns a new array with the desired values
int *perfect_out_shuffle(int deck[], size_t length) {
    int newArray[52];
    unsigned int counter = 1;
    unsigned int middle = (length/2) - 1;
    for(unsigned int i = 0; i <= length - 1; i++) {
        if(i == 0 || i == length - 1) {
            newArray[i] = deck[i];
        } 
        else if(i % 2 == 0) {
            newArray[i] = deck[i/2];
        } else  if ( i % 2 == 1) {
            newArray[i] = deck[middle + counter];
            counter++;
        }
    }
    return newArray;
}

//simulates the perfect in shuffle and returns a new array with the desired values
int *perfect_in_shuffle(int deck[], size_t length) {
    int newArray[52];
    unsigned int even_counter = 0;
    unsigned int odd_counter = 0;
    unsigned int middle = (length/2) - 1;
    for(unsigned int i = 0; i <= length -1; i++) {
        if(i == 0) {
            newArray[i] = deck[middle + 1];
        } else if (i % 2 == 0) {
            newArray[i] = deck[i + (middle - even_counter)];
            even_counter++;
        } else if (i % 2 == 1) {
            newArray[i] = deck[odd_counter];
            odd_counter++;
        }
    }
    return newArray;
}

// implements the last two declared functions into a while loop and checks whether they look like the first deck created. Returns the number of iterations 
int solve_shuffle(int deck[], size_t length) {
    int iteration_count = 0;
    while(!deck_check(deck, length)) {
        iteration_count++;
        int *perfectly_out_shuffled_array = perfect_out_shuffle(deck, length);
        print_array_to_console(perfectly_out_shuffled_array, length);
        if(!deck_check(perfectly_out_shuffled_array, length)) {
            break;
        }

        iteration_count++;
        int *perfectly_in_shuffled_array = perfect_in_shuffle(deck,length);
        print_array_to_console(perfectly_in_shuffled_array, length);
        if(!deck_check(perfectly_in_shuffled_array, length)) {
            break;
        }
    }
    print("\nThe amount of iterations needed were: ", iteration_count, "\n", 0);
    return iteration_count;
}


int main() {
    // AUFGABE 1A
    // printf("please enter b and a (in that order) Ex: 1 and 2 \n");
    // cout << wurzel_iterative(enter_int(), enter_int());

    // printf("\nplease enter a base \n");
    // cout << wurzel_vorlesung_analog(enter_int());

    // // AUFGABE 1B
    // // Die Funktion wurzel_iterative() braucht 52 iterationen um auf das Ergebnis 1.41421 zu kommen. Die Funktion wurzel_vorlesung_analog (mit dem newton Verfahren implementiert) braucht nur 6 Iterationen um auf der selbe Ergebnis zu kommen.

    // // AUFGABE 3
    // //getting the array with the corresponding functionality
    // int *number = fill_array();
    // printf("Array(");
    // size_t theArraylength = 10; 
    //     // printing array to the console
    // for(size_t i = 0; i < theArraylength; i++) {
    //     if(number[i] != 0) {
    //         printf("%i, ", number[i]);
    //     }
    // }
    // printf(")");

    //AUFGABE 4

    //insert numbers here to test the shuffle array function
    int deck[52] = {/*insert numbers 0-51 here to test*/};
    size_t length = sizeof(deck)/sizeof(deck[0]);

    //this function creates an array length 52 with every index corresponding with one card coded as a number in descending order

    //to test the solve_shuffle function, comment both of these functions out and write the test values in the {} of the deck[52] array.
    build_deck(deck, length);
    print_array_to_console(deck,length );
    
    //Here is the while loop for this exercise.
    solve_shuffle(deck, length);
    return 0;
}

/*
   int wcount;
   int icount;
   const double genau = 1.0e-12;

   double abs(double x) {
       if(x>0) return -x;
   }

   bool gut_genug(double xn, double a) {

   }
*/

/*
    schleife for variante

    v = (a,b,i)
    b(v)= b(a,b,i) = i < n;
    h(v) = h(a,b,i) = (b, a+b, i+1);
    while(b(v)) {v = h(v)}

    schleife invariante
    p(n) = (n >= && a = 0 && b = 1 && i = 0)
    q(a,b,i) = b = fib(n)
    inv(a,b,i) = a = fib(i) && b = fib(i + 1)

    1. v0 = (0,1,0)
    inv(0,1,0) = fib(0) = 0 && fib(1) = 1
    2. vj = (aj, bj, ij)
    inv(aj,bj,i,j) = fib(j) = a && fib(j + 1) = b
    H(aj, bi, ij) = (bj,aj + bj, Ij+1)
    Vj+1(bj, aj + bj, Ij+1)
    INVj+1(bj, aj + bj, Ij+1) = fib(ij+1) = bj && fib(ij+2) = aj + bj = fib(j) + fib(Bj+1) 

    INVn(a,b,c) && !B(n)
    fib(i) = a && fib(i + 1) = b && (0 <= i <= n) && !b(n)
    => i = n && fib(n) = a && fib(n+1) = b
*/