#ifndef SMARTPOINTER_HH
#define SMARTPOINTER_HH
//smart pointers

#include <iostream>
template<class T>
class ptr {
    struct reference {
        int count;
        T * obj;
        reference(T * q) {count = 1; obj = q;}
    };
    reference * p;
    void report() {
        std::cout << p->count<< std::endl;
    }

    void increment() {
        p->count++;
        report();
    }

    void decrement() {
        p->count--;
        report();
        if(p->count == 0) {
            delete p->obj;
            delete p;
        }
    }

    public:
        ptr() {p = 0;}
        ptr(T* q){
            p = new reference(q);
            report();
        }

        ptr(const ptr<T>& y)
        {
            p = y.p;
            if(p!= 0) increment();
        }

        ~ptr() {
            if( p != 0 ) decrement();
        }

        ptr<T>& operator=(const ptr<T>& y)
        {
            if(p != y.p) {
                if(p!= 0) decrement();
                p = y.p;
                if(p!= 0) increment();
            }
            return *this;
        }

        T& operator*(){return *(p->obj);}

        T& operator->(){return p->obj;}
};

#endif// SMARTPOINTER_HH