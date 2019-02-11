#include <iostream>
#include <ctime>

clock_t last_t;
double stamp() {
    clock_t current = clock();
    double duration = ((double) (current - last_t)) / CLOCKS_PER_SEC;
    last_t = current;
    return duration;
}

int main(int argc, char const *argv[])
{
    std::cout << stamp() << "\n";
    //templates are faster than virtual functions
    return 0;
}
