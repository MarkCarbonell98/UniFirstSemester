#include "Aufgabe2a.hh"

IntList::IntList() : _first(nullptr), _count(0) {}

IntList::~IntList() {
    if(!this->isEmpty()) {
        listItem * i = _first;
        for(int index = 0; index < _count; i = i->_next) {
            listItem * j = i->_next;
            delete i;
            i = j;
            index++;
        }
        delete _first;
        delete &_count;
    } else {
        delete _first;
        delete &_count;
    }

}

int IntList::getCount() {
    return this->_count;
}

bool IntList::isEmpty() {
    return this->_count == 0;
} 

void IntList::print() {
    int deepCounter = 1;
    printf("\n List _count  = %d \n", _count);
    for(listItem* i = _first; i != nullptr; i = i->_next) {
        printf("value = %d pointer = %p deepCounter = %d \n", i->_value, i->_next, deepCounter);
        ++deepCounter;
    }
}

void IntList::insert(int element, int position) {
    if(position == 0) {
        throw std::invalid_argument("You can't insert at index 0");
    }

    //if the first element of the list is defined
    if(this->isEmpty()) {
        int count = 1;
        listItem * start = new listItem();
        _first = start;
        for(listItem * i = _first; true; i = i->_next) {
            if(count == position) {
                i->_value = element;
                i->_next = nullptr;
                break;
            }
            listItem * newElement = new listItem();
            i->_next = newElement;
            count++;
        }
        _count = count;
        //if it is not defined
    } else {
        int count = 0;
        for(listItem* i = _first; count < position; i = i->_next) {
            count++;
            if(count >= _count) {
                if(count == position) {
                    i->_value = element;
                    i->_next = nullptr;
                    _count = count;
                    break;
                }
                listItem * newItem = new listItem();
                i->_next = newItem;
            } else if(_count > position) {
                if(count == position) {
                    i->_value = element;
                    break;
                }
            }
        }
    }
}

void IntList::remove(int position) {
    if(position > _count || position == 0) {
        throw std::invalid_argument("You can't delete an element that does not exist");
    }
    int count = 0;
    if(position == 1) {
        _first = _first->_next;
        _count--;
    }

    if(position == _count) {
        for(listItem * i = _first; i != nullptr; i = i->_next) {
            ++count;
            if(count == position -1) {
                i->_next = nullptr;
            }
            _count--;
        }
    }

    if(position > 1 && position < _count) {
        for(listItem * i = _first; count != position; i = i->_next) {
            ++count;
            if(count == position-1) {
                i->_next = i->_next->_next;
                break;
            }
        }
        _count--;
    }
}

int IntList::getElement(int position) {
    if(position > _count || position < 0) {
        throw std::invalid_argument("You can't delete an element that does not exist");
    }

    int count = 0;
    for(listItem * i = _first; count != position; i = i->_next) {
        ++count;
        printf("%d \n" , count);
        if(count == position) {
            return i->_value;
        }
    }
    return -1;
}



int main() {
    IntList* list = new IntList();
    list->insert(1,1);
    list->insert(2,2);
    list->insert(3,3);
    list->print();
    list->remove(2);
    list->print();

    printf("\n %d %d %d \n", list->getCount(), list->isEmpty(), list->getElement(2));
}