#include <iostream>

int main(int argc, char** argv)
{
  if (argc != 2)
    {
      std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
      return 1;
    }
  char* check = nullptr;
  double v = strtod(argv[1],&check);
  if (check == argv[1])
    {
      std::cerr << "Not a valid number: " << argv[1] << std::endl;
      return 2;
    }
  std::cout << v * v << std::endl;
  return 0;
}
