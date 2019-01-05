#include "statistics.hh"
#include "uniform.hh"

std::vector<double> uniform(int randomNumber, int quantity, double smallest, double biggest) {

    std::vector<double> result = uniform_distribution(randomNumber, quantity, smallest, biggest);

    for(auto element : result) {
        std::cout << element << std::endl;
    }

    return result;
}