#include "vector.hh"

//aufgabe b
int main(int argc, char const *argv[])
{

//vektoren als bsp
    std::vector<double> test1 = {1,2,3};
    std::vector<double> test2 = {4,5,6};
    Vector<std::vector<double>, double> a(test1, test1.size()), b(test2, test2.size());
    a.print();
    b.print();
    std::cout << a.maximum() << ' ' << b.maximum() << std::endl;
    std::cout << a[1] << ' ' << b[1] << std::endl;

    std::cout << a.begin() << std::endl;
    std::cout << a.end() << std::endl;

    a.scalarMultiplied(10);
    b.scalarMultiplied(2);

    a.print();
    b.print();

    b.add(a);

    b.print();

    a.add(b);

    a.print();

    std::cout << a.maximum() << ' ' << b.maximum() << std::endl;

//listen
    std::list<double> list1 = {1,2,3};    
    std::list<double> list2 = {4,5,6}; 
    Vector<std::list<double>, double> c(list1, list1.size()), d(list2,list2.size());   
    c.scalarMultiplied(10);
    d.scalarMultiplied(10);

    c.print();
    d.print();
    std::cout << c.maximum() << ' ' << d.maximum() << std::endl;
    std::cout << c[1] << ' ' << d[1] << std::endl;

    std::cout << c.begin() << std::endl;
    std::cout << d.end() << std::endl;

    c.add(d);

    c.print();

    d.add(c);

    d.print();

    //Danke dir Markus! :D


    return 0;
}
