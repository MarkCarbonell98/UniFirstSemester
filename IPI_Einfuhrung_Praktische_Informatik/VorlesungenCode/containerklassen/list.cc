#include <iostream>

template<class T>
class List {
    public:
        List() : _first(0) {}

        ~List();

        class Link {
            Link * _next;
            public:
                T item;
                Link(T& t) {item = t;}
                Link * next() {return _next;}
                friend class List<T>;
        };

        Link * first() {return _first;}
        void insert(Link* where, T t);
        void remove(Link * where);

    private:
        Link * _first;
        List(const List<T>& i) {}
        List<T>& operator =(const List<T>& i) {}
};

template<class T> List<T>::~List() {
    Link* p = _first;
    while(p != 0)
    {
        Link * q = p;
        p = p->next();
        delete q;
    }
}

template<class T>
void List<T>::insert(List<T>::Link * where, T t) {
    Link* ins = new Link(t);
    if(where == 0) {
        ins->_next = _first;
        _first = ins;
    } else {
        ins ->_next = where->_next;
        where->_next = ins;
    }
}

template<class T>
void List<T>::remove(List<T>::Link * where) {
    Link* p;
    if(where == 0) {
        p = _first;
        if(p != 0) _first = p->_next;
    } else {
        p = where->_next;
        if(p != 0) where->_next = p->_next;
    }
    delete p;
}

int main(int argc, char const *argv[])
{
    List<int> list;
    list.insert(0,17);
    list.insert(0,32);
    list.insert(0,26);

    for(List<int>::Link* i = list.first(); i != 0; i=i->next()) 
        std::cout << i->item << "\n";
    for(List<int>::Link* i = list.first(); i!= 0; i=i->next())
        i->item = 23;
    
    return 0;
}
