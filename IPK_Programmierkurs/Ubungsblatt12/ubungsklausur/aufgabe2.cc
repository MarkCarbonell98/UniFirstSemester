#include <iostream>
#include <vector>
#include <algorithm>

class Building {
    public:
        std::string name() const;
        std::string city() const;
        int height() const;

};
std::vector<Building> sortedByHeight(const std::vector<Building>& vec){
    std::vector<Building> newVec = {{}};
    for(auto e : vec)
        newVec.push_back(e);

    std::sort(newVec.begin(), newVec.end(), [&](Building a,Building b) -> bool {
        return a.height() > b.height();
    });

    return newVec;
}

// template<typename T>
// std::vector<T> sortMe(const std::vector<T>& vec) {
//     std::sort(vec.begin(), vec.end(), [&vec](int i) {
//         return vec[i].height() > vec[i-1].height();
//     })
// }
template<typename T>
void printVector(T v) {
    for(auto i : v)
        std::cout << i << ", ";
}

int main(int argc, char const *argv[])
{
    Building a,b,c;
    std::vector<Building> test;
    test.push_back(a);
    test.push_back(b);
    test.push_back(c);
    sortedByHeight(test);
    printVector(test);
    std::vector<int> vec = {{1,6,4,2,3,4,43,43,4,34,37,8,97,8,0}};
    std::sort(vec.begin(), vec.end(), [&](int a, int b) -> bool {
        return  a < b;
    });
    printVector(vec);
    return 0;
}
