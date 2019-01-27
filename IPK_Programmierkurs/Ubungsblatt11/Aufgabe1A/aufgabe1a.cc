#include "Aufgabe1.hh"
#include <fstream>

int main(int argc, char const *argv[])
{

    std::map<char, bool> data = {{'a', true}, {'b', false}};
    LetterFrequencies<std::map<char, bool>> a(data);
    auto test1 = streamLetterSource(std::cin);
    a.readData(test1);

    std::unordered_map<std::string, bool> moreData = {{"name1", true}, {"name2", false}};
    LetterFrequencies<std::unordered_map<std::string,bool>> b(moreData);
    auto test = streamWordSource(std::cin);
    b.readData(test);


    std::map<char, bool> charInit = {{'a', false}};
    std::map<std::string, bool> stringInit = {{"string",false}};
    LetterFrequencies<std::map<char,bool>> reader1(charInit);
    LetterFrequencies<std::map<std::string,bool>> reader2(stringInit);
    for(int i = 1; i < argc; ++i) {
        std::ifstream f(argv[i]);
        auto source = streamLetterSource(f);
        if(sizeof(source.next().first) <= 2) {
            reader1.readData(source.next());
        } else {
            reader2.readData(source.next());
        }
    }
}
