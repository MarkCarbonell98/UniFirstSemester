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

template <typename Map>
class LetterFrequencies
{
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
    Map _map;
};
