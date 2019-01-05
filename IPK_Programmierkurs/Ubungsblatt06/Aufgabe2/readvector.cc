#include "statistics.hh"
#include "readvector.hh"

std::vector<double> readvector(std::vector<double> input) {

    for(auto element : input) {
        std::cout << element << std::endl;
    }

    return input;
} 