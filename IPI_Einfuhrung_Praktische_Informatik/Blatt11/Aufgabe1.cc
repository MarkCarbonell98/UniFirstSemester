#include <iostream>

class A {
    public:
        int ap;
        void X();
    private: 
        int aq;
        void aX();
};

class B : public A {
    public:
        int bp;
        void Y();
    private:
        int bq;
        void bY();
};

class C : public B {
    public:
        int cp;
        void Z();
    private:
        int cq;
        void cZ();
};

void B::Y() {
    bq = bp;
    aq = ap;
    bY();
}

void C::cz() {
    ap = 1;
    bp = 2;
    cq = 3;
    X();
    Y();
    aX();
}

int main() {
    A a; B b; C c;

    a.X();
    b.bY();
    c.cp = 4;
    c.bp = 1;
    c.ap = 2;
    c.aq = 5;
    b.ap = c.ap;
    return 0;
    /*
        Aufgabe1.cc: In member function 'void B::Y()':
Aufgabe1.cc:32:5: error: 'int A::aq' is private within this context
     aq = ap;
     ^~
Aufgabe1.cc:8:13: note: declared private here
         int aq;
             ^~
Aufgabe1.cc: At global scope:
Aufgabe1.cc:36:12: error: no 'void C::cz()' member function declared in class 'C'
 void C::cz() {
            ^
Aufgabe1.cc: In function 'int main()':
Aufgabe1.cc:49:10: error: 'void B::bY()' is private within this context
     b.bY();
          ^
Aufgabe1.cc:18:14: note: declared private here
         void bY();
              ^~
Aufgabe1.cc:53:7: error: 'int A::aq' is private within this context
     c.aq = 5;
       ^~
Aufgabe1.cc:8:13: note: declared private here
         int aq;
             ^~
    */
}