#include "statistics.hh"
#include "normal.hh"


std::vector<double> normal(int randomNumber, int quantity, double average, double deviation) {
    std::vector<double>result = normal_distribution(randomNumber, quantity, average, deviation);

    for(auto element : result) {
        std::cout << element << std::endl;
    }
    return result;
}