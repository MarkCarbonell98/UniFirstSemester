#ifndef FREQUENCIES_HH
#define FREQUENCIES_HH
#include <iostream>
#include <cctype>
#include <iterator>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <sstream>
#include <unordered_map>

template<typename Map>
class Frequencies {
    public:
        typedef typename Map::key_type the_keys;

        Frequencies()

        public:
    LetterFrequencies(Map newMap) : _map(newMap) {}
    
    template <typename T1>
    double mean(const T1 &v)
    {
        typename T1::value_type sum = 0;
        for (auto e : v)
        {
            sum += e;
        }

        return sum / v.size();
    }

    template <typename T1>
    double median(const T1 &v)
    {
        std::vector<typename T1::value_type> v2;
        for (auto e : v)
            v2.push_back(e);

        std::sort(v2.begin(), v2.end());

        if (v.size() % 2 == 0)
        {
            return .5 * (v2[v.size() / 2 - 1] + v2[v.size() / 2]);
        }
        else
        {
            return v2[(v.size() + 1) / 2 - 1];
        }
    }

    template <typename T1>
    double moment(const T1 &v, int k)
    {
        typename T1::value_type sum = 0;
        for (auto e : v)
            sum += std::pow(e, k);

        return sum / v.size();
    }

    template <typename T1>
    double std_dev(const T1 &v)
    {
        typename T1::value_type m = mean(v);
        typename T1::value_type sum = 0;
        for (auto e : v)
            sum += (m - e) * (m - e);

        return std::sqrt(sum / v.size());
    }

    template <typename T1>
    void statistics(const T1 &v)
    {
        std::cout << "mean: " << mean(v) << std::endl;
        std::cout << "median: " << median(v) << std::endl;
        std::cout << "second moment: " << moment(v, 2) << std::endl;
        std::cout << "std_dev: " << std_dev(v) << std::endl;
    }


    Map get_frequencies()
    {
        auto source = streamLetterSource(std::cin);
        Map newMap;

        while (true)
        {
            auto data = source.next();
            if(!data.second)
                break;
            
            if(std::isalpha(data.first)) {
                newMap[data.first] += 1;
            }

        }
        return newMap;
    }

    void print_frequencies(const Map &frequencies)
    {
        std::size_t total = 0;

        for (auto entry : frequencies)
            total += entry.second;

        for (auto entry : frequencies)
            std::cout << entry.first << ": " << static_cast<double>(entry.second) / total << std::endl;
    }

    template <typename Source>
    void readData(Source &source)
    {
        while(true) {
            auto data = source.next();
            if(!data.second)
                break;
            _map[data.first] += 1;
        }

        for(auto item : _map) 
            std::cout << item.first << " " <<  item.second <<  std::endl; 
    }
        
    private:
        typename Map::key_type _input;
        Filter _filter;

};

template<typename Data>
class Filter {
    public:
        Filter();

        Data transform(const Data& data) {
            Data transformedData = data;
            if(!this->remove(data)) {
                std::toupper(data.first);
            }
            return data;
        };

        bool remove(const Data& data) {
            if(((sizeof data.first) != 24) && ((sizeof data.first) != 1)) {
                return false;
            }
            return true;
        };
};

#endif // FREQUENCIES_HH