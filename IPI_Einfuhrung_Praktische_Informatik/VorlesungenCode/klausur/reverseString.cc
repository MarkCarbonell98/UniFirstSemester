#include <iostream>
#include <string>

std::string reverse(std::string &input) {
    return input.length() == 1 ? input[0] : reverse(input.substr(, 0)); 
}

int main(int argc, char const *argv[])
{
    std::string test = "Marcos es increible";
    std::cout << reverse(test);
    return 0;
}
