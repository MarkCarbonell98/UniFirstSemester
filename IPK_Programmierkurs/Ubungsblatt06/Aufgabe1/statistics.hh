#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "io.cc"
#include <algorithm>
#include <map>
#include <utility>

// HEADER FUNCTIONS AUFGABE 1A

std::vector<double> readvector(std::vector<double> input) {

    for(auto element : input) {
        std::cout << element << std::endl;
    }

    return input;
} 

std::vector<double> uniform(int randomNumber, int quantity, double smallest, double biggest) {

    std::vector<double> result = uniform_distribution(randomNumber, quantity, smallest, biggest);

    // for(auto element : result) {
    //     std::cout << element << std::endl;
    // }

    return result;
}

std::vector<double> normal(int randomNumber, int quantity, double average, double deviation) {
    std::vector<double>result = normal_distribution(randomNumber, quantity, average, deviation);

    // for(auto element : result) {
    //     std::cout << element << std::endl;
    // }
    return result;
}

#endif


