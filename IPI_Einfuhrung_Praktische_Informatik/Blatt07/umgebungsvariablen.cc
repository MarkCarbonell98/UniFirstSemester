#include <iostream>

int g = 0; //globale variable

int a_mod_b(int a, int b)
{
    int m = a % b; //lokale variable von a_mod_b
    return m; //1 
}
int ggT(int a, int b)
{
    g = g + 1; //globale variable wird zugewisen
    int Null = 0; //lokale variable
    if (b == Null) //argumenten sind auck Lokal
        return a; //2
    else return ggT(b, a_mod_b(a, b)); 
}

int main(void)
{
    int a = 2; //lokale var
    int b = 14; //lokale var
    {
        int a = 7; // existiert nur in diesem scope
        int g = ggT(b, a); //existiert nicht da g schon eine globale variable ist (kompilerfehler)
        b = g; //???
    }
    a = g; // a ist gleich zu var g;
    return 0; //3
}