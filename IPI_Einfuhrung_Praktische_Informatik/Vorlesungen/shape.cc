#include "shape.hh"

double circumference_to_area(Shape& shape) {
    return shape.circumference() /shape.area();
};

class Function {
    public:
        virtual ~Function() {};
        virtual int operator()(int) = 0;
};

class Inkrementierer : public Function {
    public:
        Inkrementierer(int n) {inkrement = 0;}
        virtual int operator()(int n) {return n + inkrement;}
    private:
        int inkrement;
};

void schleife(Function& func) {
    for(int i = 1; i < 10; i++) {
        std::cout << func(i) << "_";
    }
    std::cout << std::endl;
}

class Quadrat : public Function {
    public:
        virtual int operator()(int n) {return n+n;}
};

//polyshow search of float array search for pointers to elements, not through index, much more efficient.

    /*
        Schnittstellenbasisklasse
    Imple.1    Imple.2         Imple.3

        Obj. werden durch die Abs. Klassen erzeugt und und durch die Schnittstellenbasisklasse angewendet ?
    */

int main(int argc, char const *argv[])
{
    Inkrementierer ink(10);
    Quadrat quadrat;
    schleife(ink);
    schleife(quadrat);
    return 0;
}
