#ifndef AUFGABE2A_HH
#define AUFGABE2A_HH

#include <iostream>

class IntList {
    public:

        IntList();

        ~IntList();

        int getCount();

        bool isEmpty();

        void print();

        void insert(int element, int position);

        void remove(int position);

        int getElement(int position);

    private:
        struct listItem {
            listItem* _next;
            int _value;
        };
        listItem* _first;
        int _count;
};

#endif //AUFGABE2A_HH   
