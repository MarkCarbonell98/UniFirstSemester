#include <iostream>
#include "losung.hh"
#include <fstream>
#include "sanitizeword.hh"

int main(int argc, char const *argv[])
{
    LetterFrequencies<std::map<char,int>> frequencies;
    Frequencies.addPlugin(std::make_shared<PrintTotalCount<Map>>())
    for(int i = 1; i < argc; i++) {
        sdt::ifstream stream(argv[i]);
        auto source = streamLetterSource(stream);
        frequencies.print_frequencies(source); 
    }
    return 0;
};

