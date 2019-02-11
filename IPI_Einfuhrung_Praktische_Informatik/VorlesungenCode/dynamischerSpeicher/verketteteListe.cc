#include <iostream>

struct listElem {
    listElem * next;
    int value;
};

struct list {
    int count;
    listElem * head;
};

void empty_list(list * l) { // pass pointer because the element must be changed
    l->head = 0;
    l->count = 0;
}

listElem* find(list l, int x) {
    for(listElem * p = l.head; p != 0; p=p->next) {
        if(p->value == x) return p;
    }
    return 0;
}

void insert(list * l, listElem * where, listElem * inserted) {
    if(where == 0) {
        inserted->next = l->head;
        l->head = inserted;
        l->count++;
    } else {
        inserted->next = where->next;
        where->next = inserted;
        l->count++;
    }
} 

listElem * remove(list * l, listElem * where) {
    listElem * p;
    while(where == 0) {
        p = l->head;
        if(p!=0) {
            l->head = p->next;
            l->count--;
        }
        return p;
    }

    p = where->next;
    if(p != 0) {
        where->next = p->next;
        l->count--;
    }
    return p;
}



typedef list * l; //

// int main(int argc, char const *argv[])
// {
//     list * l = new list();
//     listElem * elem = new listElem();
//     elem->next = nullptr;
//     elem->value = 1000;

//     insert(l, elem, elem);
//     insert(l, elem, elem);
//     insert(l, elem, elem);
//     insert(l, elem, elem);

//     std::cout << l->count << " " << l->head << "\n";
//     return 0;
// }




