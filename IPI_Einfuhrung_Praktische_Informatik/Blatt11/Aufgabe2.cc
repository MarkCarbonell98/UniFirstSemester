class A {
    public: 
        void a();
        virtual void va() = 0;
        virtual void a(int n);
    private:
        void c();
};

class B : public A {
    public:
        void b();
        virtual void vb();
        void a(double d);
        void a(int i);
        virtual void va();
};

class C : public B {
    public:
        virtual void c();
        void a(float);
        virtual void a();
        virtual void va();
};

int main() {
    // A a; // Fehler 1, eine abstrakte Klasse darf keine Objekte erzeugen
    B b;
    C c; 
    A* pa=&b; B* pb=&c; 
    float x = 1.2;
    pa->a(); // wurde von A aufgerufen und implementiert
    pa->va();  // wurde von A aufgerufen und implementiert
    pa->a(1);  // wurde von A aufgerufen und implementiert
    // pa->c();  // Fehler 2, c ist private in A::c()
    // pa->b(); // Fehler 3, b ist A::b() nicht definiert
    // pa->vb(); // Fehler 4, vb ist in A::vb() nicht definiert
    pa->a(x); //wurde von A aufgerufen und implementiert
    // pb->a(); //Fehler 5, a() must ein argument bekommen. (int)
    pb->va(); // wurde von B aufgerufen und implementiert
    pb->a(1); // wurde von B aufgerufen und implementiert
    // pb->c();  //Fehler 6 c() ist private in A::c()
    pb->b();  //wurde von B aufgerufen und implementiert
    pb->vb();  //wurde von B aufgerufen und implementiert
    pb->a(x); //wurde von B aufgerufen und implementiert
    pa = &c;
    pa->a(); // wurde von A aufgerufen und implementiert
    pa->va(); // wurde von A aufgerufen und implementiert
    pa->a(1); // wurde von A aufgerufen und implementiert
    // pa->c(); //Fehler 7, c ist in A::c() private
    // pa->b(); // Fehler 8, b() ist in A::b() nicht definiert 
    // pa->vb(); // Fehler 9, vb() hat kein member in A::vb
    pa->a(x); // Fehler 10, da x von typ float ist, aber a nimmt nur ints als input
}

// Vorlesung Abstrakte klassen 10 (Klausur)
// einige Definitionen
// codezeilen hinzufugen

