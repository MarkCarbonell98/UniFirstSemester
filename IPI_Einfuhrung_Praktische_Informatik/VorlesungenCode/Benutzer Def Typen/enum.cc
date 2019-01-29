//the enum keyword
#include "fcpp.hh"
#include <string>

enum State {newState, used, old, damaged};
void printState (State x) {
    if(x == newState) print("neu");
    if(x == used) print("gebraucht");
    if(x == old) print("alt");
    if(x == damaged) print("kaputt");
} 

int main(int argc, char const *argv[])
{
    printState(old);
    printState(newState);
    const int n = 8;
    char s[3*(n+1)];
    for(auto letter : s) {
        std::cout << letter << std::endl; //zufallszahlen;
    }

    //the size of a field must be known before compilation.
    return 0;
}

