#include <fcpp.hh>

typedef int type;

const int size = 1000;

type stack[size];

int top = 0;

void push(type el) {
    stack[top] = el;
    top++;
} 

bool empty() {
    return top == 0;
}

type pop() {
    top--;
    return stack[top];
}

int main(int argc, char const *argv[])
{
    push(1);
    push(2);
    push(3);
    push(4);

    while(!empty()) {
        print(pop());
    }

    std::cout << stack[0];
    return 0;
}
