
#include "statistics.hh"
// #include "io.cc"

//IMPLEMENTIERUNG AUFGABE 1A

// PROGRAMME ZU FINDEN IM VERZEICHNIS VON AUFGABE 2

// std::vector<double> readvector(std::vector<double> input) {

//     for(auto element : input) {
//         std::cout << element << std::endl;
//     }

//     return input;
// } 

// std::vector<double> uniform(int randomNumber, int quantity, double smallest, double biggest) {

//     std::vector<double> result = uniform_distribution(randomNumber, quantity, smallest, biggest);

//     for(auto element : result) {
//         std::cout << element << std::endl;
//     }

//     return result;
// }

// std::vector<double> normal(int randomNumber, int quantity, double average, double deviation) {
//     std::vector<double>result = normal_distribution(randomNumber, quantity, average, deviation);

//     for(auto element : result) {
//         std::cout << element << std::endl;
//     }
//     return result;
// }

// AUFGABE 1B

double mean(const std::vector<double>& v) {
    double accumulator = 0.0, result;
    int n = v.size();
    if(n == 0) return 0;

    for(int i = 0; i < n; i++) {
        accumulator += v[i];
    }
    result = (1/(n+0.0))*accumulator;
    return result;
} 

// AUFGABE 1C
double median(const std::vector<double>& v) {
    int size = v.size();
    if(size == 0) return 0;
    std::vector<double> result = v;
    std::sort(result.begin(), result.end());
    
    printf("Result: ");
    if(size % 2 == 1) {
        return result[(size -1)/2];
    } else {
        return .5*(result[(size/2) - 1] + result[size/2]);
    }
}

//AUFGABE 1D
double moment(const std::vector<double>& v, int k) {
    int n = v.size();
    double result = 0.0;
    for(auto i : v) {
        result += pow(i, k);
    }
    return (1/(n+0.0))*result;
}

//AUFGABE 1E
double standard_deviation(const std::vector<double>& v) {
    int n = v.size();
    double outerResult = 0.0, innerResult = 0;

    for(auto i : v) {
        innerResult += pow(i - mean(v), 2);
    }
    outerResult = (1/(n+0.0))*innerResult;
    return sqrt(outerResult);
}

bool check_relationship(const std::vector<double>& v) {
    double std_dev = pow(standard_deviation(v),2);
    double quadratic_moment = moment(v, 2);
    double quadratic_mean = pow(mean(v), 2);

    if(std_dev == (quadratic_moment - quadratic_mean)) {
        printf("The relationship is true!");
        return true;
    } else {
        printf("The relationship is NOT true!");
        return false;
    }
}

//AUFGABE 3A

std::map<char,int> get_frequencies() {
    std::map<char,int> result;
    while(true) {
    unsigned char c;
        std::cin >> c;
        if(!std::cin) 
            break;
        result[c]++;
    }
    return result;
}

//AUFGABE 3B

void print_frequencies(const std::map<char,int>& frequencies) {
    for(auto i : frequencies) {
        printf("The letter %c appears %i times \n", i.first, i.second);
    }
    return;
}


int main() {

    // //AUFGABE 1A
    // std::vector<double> testVector = uniform_distribution(random_seed(), 50,1,60);

    // printf("\nOutput of readvector:  \n \n" );

    // readvector(testVector);

    // // GO TO STATISTICS.HH AND UNCOMMENT THE FOR LOOPS INSIDE OF NORMAL() AND UNIFORM() TO CHECK THE FUNCTIONS OUTPUT
    // printf("\nOutput of uniform:  \n \n" );

    // uniform(1,20,1,20);

    // // GO TO STATISTICS.HH AND UNCOMMENT THE FOR LOOPS INSIDE OF NORMAL() AND UNIFORM() TO CHECK THE FUNCTIONS OUTPUT
    // printf("\nOutput of normal:  \n \n" );

    // normal(random_seed(), 50, 25, 4);

    // //AUFGABE 1B
    // printf("\nOutput of mean:  \n \n" );

    // std::cout << mean(testVector) << std::endl;

    // //AUFGABE 1C
    // printf("\nOutput of median:  \n \n" );

    // std::cout << median(testVector) << std::endl;

    // //AUFGABE 1D
    // printf("\nOutput of moment:  \n \n" );

    // std::cout << moment(testVector, 3) << std::endl;

    // //AUFGABE 1E
    // printf("\nOutput of standard_deviation:  \n \n" );

    // std::cout << standard_deviation(testVector) << std::endl;

    // check_relationship(testVector);

    get_frequencies();
    std::map<char,int> freqs = get_frequencies();

    print_frequencies(freqs);

    return 0;
}
