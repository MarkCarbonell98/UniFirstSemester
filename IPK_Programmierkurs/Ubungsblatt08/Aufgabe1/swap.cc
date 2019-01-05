#include <iostream>

//char** argv <==> char* argv[]
template<typename Template>
void swap(Template& template1, Template& template2) {
    Template main_template = std::move(template1);
    template1 = std::move(template2);
    template2 = std::move(main_template);
}

int main(int argc, char **argv)
{
    int a = 1;
    int b = 2;
    std::cout << "a = " << a << " b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << " b = " << b << std::endl;
    double c = 3;
    double d = 4;
    std::cout << "c = " << c << " d = " << d << std::endl;
    swap(c, d);
    std::cout << "c = " << c << " d = " << d << std::endl;
    // swap(a,c); //kompiliert nicht 
    
    return 0;
}