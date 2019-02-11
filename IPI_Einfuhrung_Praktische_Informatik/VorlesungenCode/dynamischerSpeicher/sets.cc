#include <iostream>
#include "verketteteListe.cc"
#include <fcpp.hh>

struct Set{
    list l;
};

Set* empty_list() {
    Set * menge = new Set();
    empty_list(&menge->l);
    return menge;
}

bool in_set(Set * menge, int x) {
    for(listElem * p = menge->l.head; p != 0; p = p->next) {
        if(p->value == x) return true;
    }
    return false;
}

void insert_in_set(Set * s, int x) {
    if(!in_set(s,x)) {
        listElem * p = new listElem();
        p->value = x;
        insert(&s->l, 0, p);
    }
}

void print_set(Set * s) {
    print("{");
    for(listElem * p = s->l.head; p != 0; p = p->next) 
        print(" ", p->value, 0);
    print("}");
}

void remove_from_set(Set * s, int x) {
    if(s->l.head == 0) return;
    if(s->l.head->value == x) {
        listElem* p = remove(&s->l, 0);
        delete p;
        return;
    }

    for(listElem * p = s->l.head
    ; p->next!=0; p = p->next) 
        if(p->next->value == x) {
            listElem * q = remove(&s->l, p);
            delete q;
            return;
    }
}

int main(int argc, char const *argv[])
{
    Set * s = empty_list();
    print_set(s);
    for(int i = 1; i < 12; i++) insert_in_set(s,i);
    print_set(s);
    for(int i = 2; i < 30; i=i+2) remove_from_set(s,i);
    print_set(s);
    return 0;
}


