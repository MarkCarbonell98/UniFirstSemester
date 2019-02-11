#include <iostream>

template<class T>
void swap(T& a, T& b) {
    T t = a;
    a = b;
    b = t;
}

template<class C> 
void bubblesort(C& a) {
    for(int i = a.maxIndex(); i >= a.minIndex(); i--)
        for(int j = a.minIndex(); j < i; j++)
            if(a[j+1] < a[j])
                std::swap(a[j+1], a[j]);
}

int main(int argc, char const *argv[])
{
    int a = 2, b = 3;
    swap(a,b);
    std::cout << a << " " << b;
    return 0;
}
