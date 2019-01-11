#include <iostream>


char str[5] = "Test"; 

void func() {
    int feld[2]; // lange des arrays keine index bennenung
    feld[0] = 1;
    feld[1] = 2;
    feld[2] = 3;
    int sum = 10, **acc = new int*[10];
    *(acc+2) = &(*(&(sum)));
    acc[0][2] = 1000000;
    printf("%d \n", acc[0][2]);
    float x = 1.2314;
    for(int i = 0; i <= 2; i++) {
        printf("%d, %c \n", feld[i], *str);
    }
}



int main() {
    int zahl = 5;
    func();

    printf("\n \n");
    int ** a, *b;
    int c = 4, *d = &(c);
    a = &d;
    b = *a;
    std::cout << *b << std::endl;
}