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
    aq = ap; //Fehler 1. aq ist ein Privat member von A
    bY();
}

void C::cz() { //Fehler 2. Die methode heißt sich Cz(), nicht cz()
    ap = 1;
    bp = 2;
    cq = 3; //Alles was in diese Funktion drin steht ist nicht definiert.
    X();
    Y();
    aX();
}

int main() {
    A a; B b; C c;

    a.X();
    b.bY(); // Fehler 3. bY() ist eine Private Funktion von B 
    c.cp = 4;
    c.bp = 1;
    c.ap = 2;
    c.aq = 5; // Fehler 4. aq ist ein Private member von A.
    b.ap = c.ap;
    return 0;
}