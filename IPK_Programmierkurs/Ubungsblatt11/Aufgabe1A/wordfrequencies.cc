#include <iostream>
#include <map>
#include <string>
#include "sanitizeword.hh"


std::map<std::string,int> get_frequencies()
{
  std::map<std::string,int> f;

  while (true)
    {
      std::string s;
      // read in character
      std::cin >> s;
      // abort if input closed
      if (not std::cin)
        break;

      f[sanitize_word(s)] += 1;
    }

  return f;
}


void print_frequencies(const std::map<std::string,int>& frequencies)
{
  std::size_t total = 0;

  for (auto entry : frequencies)
    total += entry.second;

  for (auto entry : frequencies)
    std::cout << entry.first << ": " << static_cast<double>(entry.second)/total << std::endl;
}


int main()
{
  print_frequencies(get_frequencies());
}
