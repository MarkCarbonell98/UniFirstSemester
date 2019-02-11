#include <fcpp.hh>

int value(int num) {
    switch(num) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 5;
        case 4:
            return 10;
        case 5: 
            return 50;
    }
    return 0;
}

struct item {
    int amount;
    int coins;
};

const int size = 1000;

int changeMoney(int amount) {
    item stack[size];
    int ptr = 0;
    int number = 0;
    int amountTemp, coinsTemp;

    stack[ptr].amount = amount;
    stack[ptr].coins = 5;
    ptr++;

    while(ptr > 0) {
        ptr++;
        amountTemp = stack[ptr].amount;
        coinsTemp = stack[ptr].coins;

        if(amountTemp == 0) 
            number = number;
        else if(amountTemp > 0 && coinsTemp > 0) {
            if(ptr >= size){
                print("Stack too small");
                return number;
            } 
            stack[ptr].amount = amountTemp;
            stack[ptr].coins = coinsTemp - 1;
            ptr++;

           if(ptr >= size){
                print("Stack too small");
                return number;
            } 

            stack[ptr].amount = amountTemp - changeMoney(coinsTemp);
            stack[ptr].coins = coinsTemp;
            ptr++;
        }
    }

    return number; // empty stack
}

int main(int argc, char const *argv[])
{
    // print(value(5));
    print(changeMoney(23));
    return 0;
}
