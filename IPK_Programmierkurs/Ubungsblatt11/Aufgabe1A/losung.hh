// #pragma once //only use this header once.

#ifndef LOSUNG_HH
#define LOSUNG_HH

#include <cctype>
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

/**
 * Source of letters from a stream.
 *
 * Use it like this:
 *
 * auto source = streamLetterSource(std::cin);
 *
 * while (true)
 * {
 *   auto data = source.next();
 *   if (not data.second)
 *     break;
 *   // work with letter in data.first
 * }
 */
template <typename Stream>
class StreamLetterSource
{

  public:
    // The type of data returned from next
    // Item::second tells you whether the data is valid,
    // Item::first contains the actual data if it is valid
    using Item = std::pair<char, bool>;

    StreamLetterSource(Stream &stream)
        : _stream(stream)
    {
    }

    // Get the next data item from the source.
    Item next()
    {
        unsigned char c;
        _stream >> c;
        return Item(c, bool(_stream));
    }

  private:
    Stream &_stream;
};

/**
 * Construct a StreamLetterSource for a given stream
 */
template <typename Stream>
StreamLetterSource<Stream> streamLetterSource(Stream &stream)
{
    return {{stream}};
}

/**
 * Source of words from a stream.
 *
 * Use it like this:
 *
 * auto source = streamWordSource(std::cin);
 *
 * while (true)
 * {
 *   auto data = source.next();
 *   if (not data.second)
 *     break;
 *   // work with word in data.first
 * }
 */
template <typename Stream>
class StreamWordSource
{

  public:
    // The type of data returned from next
    // Item::second tells you whether the data is valid,
    // Item::first contains the actual data if it is valid
    using Item = std::pair<std::string, bool>;

    StreamWordSource(Stream &stream)
        : _stream(stream)
    {
    }

    // Get the next data item from the source.
    Item next()
    {
        std::string s;
        _stream >> s;
        if (not bool(_stream))
            return Item("", false);

        std::string out;
        std::copy_if(begin(s), end(s), back_inserter(out), [](auto c) {
            return std::isalpha(c);
        });
        std::transform(begin(out), end(out), begin(out), [](auto c) {
            return std::tolower(c);
        });
        return Item(std::move(out), true);
    }

  private:
    Stream &_stream;
};

/**
 * Construct a StreamLetterSource for a givn stream
 */
template <typename Stream>
StreamWordSource<Stream> streamWordSource(Stream &stream)
{
    return {{stream}};
}

template <typename Map,typename Filter>
class LetterFrequencies
{
  public:
    template<typename Source>
    void readData(Source & source) {
        while(true) {

            auto data = source.next();
            if(!data.second)
                break;

            auto transformed = _filter.transform(data.second);
            if(!_filter.remove(transformed)) {
                _map[std::toupper(data.first)]++;

            }
            // if(std::isalpha(c)) {
            //     _map[std::toupper(data.first)]++;
            // }
         }
    
    void printFrequencies() {
        std::size_t total = 0;

        for (auto entry : _map)
            total += entry.second;

        for (auto entry : _map)
            std::cout << entry.first << ": " << static_cast<double>(entry.second)/total << std::endl;

        for(auto plugin : _plugins) {
            std::cout << std::endl<< "output " <<
        }
    }

    Filter(const &Filter fil) : _filter(fil) {}
    _plugins.push_back(AnalisysPlugin plug);


    private:
        Map _map;
        Filter _filter;
        std::vector<std::shared_ptr<AnalysisPlugin>Map>>> _plugins
};

class Filter {
    public:
        Data transform(const Data& data);

        Filter();


};

class LetterFilter {
    public:
        char transform(char c) const {
            return std::toupper(c);
        }

        bool remove(char c) {
            return std::isalpha(c);
        }
};

class StringFilter {
    public:
        char transform(std::string c) const {
            return sanitize_word(c);
        }

        bool remove(std::string c) {
            return false;
        }
};

template<typename Map>
class AnalisysPlugin {
    public:
        using Data = typename Map::key_type;

        virtual ~AnalysisPlugin() {

            virtual std::string name() const  = 0;
            virtual void printStatistics(const Map& map);
        }
};

template<typename Map>
class printCal {
    //override = prevents overriding from basis classes with the same signature;
    //call exactly this class member functions
    //overrides virtual functions
    std::string name() const override {
        return "Frequencies";
    }

    void PrintStatistics(const Map& map ) override {
        std::vector<typename Map::value_type, typename Map::mapped_type> list;

        //key_type = string
        //mapped_type = value

        //mapped_type
        //value_type
        //compare_type

        // std::copy(map.begin(), map.end(), std::back_inserter(list))
        for(auto& entry: map)
            list.emplace(entry.first,entry.second);

        std::sort(list.begin(), list.end(), [](auto & entry1, auto & entry2) {
            return entry1 > entry2;
        })

        for(std::size_t i = 0; i < std::min(_top, list.size()); ++i) {
            std::cout << list[i]->first << "\n";
        }

        PrintMostFrequent(std::size_t top) 
            : _top(top) 
        {}
    }
};

#endif //LOSUNG_HH
