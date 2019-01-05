#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <iostream>
#include <cmath>
#include <vector> 
#include <algorithm>

// template<typename T1, typename T2>
template<typename T1>
double mean(const T1& v) {
    typename T1::value_type sum = 0;
    for(auto e : v) {
        sum += e;
    }

    return sum / v.size();
}

template<typename T1>
double median(const T1& v) {
    std::vector<typename T1::value_type> v2;
    for(auto e : v)
        v2.push_back(e);


    std::sort(v2.begin(), v2.end());

    if(v.size() % 2 == 0) {
        return .5 * (v2[v.size()/2 - 1] + v2[v.size()/2]);
    } else {
        return v2[(v.size() + 1)/2 - 1];
    }
}

template<typename T1> 
double moment(const T1& v, int k) {
    typename T1::value_type sum = 0;
    for(auto e : v) 
        sum += std::pow(e,k);

    return sum / v.size();
}

template<typename T1>
double std_dev(const T1& v) {
    typename T1::value_type m = mean(v);
    typename T1::value_type sum = 0;
    for(auto e : v) 
        sum += (m-e)*(m-e);

    return std::sqrt(sum/v.size());
}

template<typename T1>
void statistics(const T1& v) {
    std::cout << "mean: " << mean(v) << std::endl;
    std::cout << "median: " << median(v) << std::endl;
    std::cout << "second moment: " << moment(v,2) << std::endl;
    std::cout << "std_dev: " << std_dev(v) << std::endl;
}

#endif