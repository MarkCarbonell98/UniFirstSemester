#include <iostream>

template<class T> 
class Container {
    public:
        class Iterator {
            public:
                Iterator();
                bool operator!=(Iterator x);
                bool operator==(Iterator x);
                Iterator operator++(); //prefix
                Iterator operator++(int ); //postfix
                T& operator*() const;
                T * operator->() const;
                friend class Container<T>;
        };
        Iterator begin() const;
        Iterator end() const;
};

int main(int argc, char const *argv[])
{
    Container<int> c;
    for(Container<int>::Iterator i = c.begin(); i!= c.end(); ++i){
        std::cout << *i << "\n";
    }
    return 0;
}
