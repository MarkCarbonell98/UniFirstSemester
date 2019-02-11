#include <iostream>
#include <fcpp.hh>

char* alphabet() {
    char buffer[27];
    for(int i = 0; i < 26; i++) buffer[i] = i + 100;
    buffer[26] = 0;
    return buffer;
}

int main(int argc, char const *argv[])
{
    char * c = alphabet();
    std::cout << *c;
    
    return 0;
}
