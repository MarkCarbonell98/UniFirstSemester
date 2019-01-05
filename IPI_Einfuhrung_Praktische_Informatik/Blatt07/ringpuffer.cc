#include <iostream>
#include <array>

int circular_puffer()
{
    int array[10];
    size_t length = sizeof(array) / sizeof(array[0]);
    int in = 0, out = 0, iteration_counter = 0;
    for (unsigned int i = 0; true; i++)
    {
        if (i == length)
        {
            i = 0;
            iteration_counter++;
        }

        int input;
        if (iteration_counter > 0)
        {
            std::cout << "Warning, now you are going to erase numbers out of the circular puffer! \n"<< std::endl;
        }
        std::cin >> input;
        if (input == 0)
        {
            if (iteration_counter == 0)
            {
                std::cout << "Out = " << 0 << std::endl;
                return out;
            }
            else
            {
                out = i;
                std::cout << "Out = " << array[out] << std::endl;
                return out;
            }
        }

        if (input < 0)
            break;

        if (iteration_counter > 0)
        {
            out = i;
            std::cout << "Out = " << array[out] << std::endl;
        }

        in = i;
        array[i] = input;
        std::cout << "In = " << array[in] << std::endl;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    std::cout << "Please insert numbers into the array :)" << std::endl;
    circular_puffer();
    return 0;
}