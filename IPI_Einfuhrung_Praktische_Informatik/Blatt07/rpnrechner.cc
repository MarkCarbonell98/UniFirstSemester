#include "fcpp.hh"
#include <cstring> // fuer strlen, Laenge eines C-Strings
#include <stack>

// Definieren Sie hier Ihren Stack und legen Sie eine Instanz als globale
// Variable an

struct Stack {
  int numbers[100];
  int counter;
};

Stack stack;

void push(int element) {
  stack.value[stack.top] = element;
  return stack.top +1;
}

int pop() {
  stack.top = stack.top -1;
  return stack.value[stack.top];
}



// Funktion, die auf dem Stack eine Rechenoperation durchfuehrt
// Rueckgabewert: ob die Berechnung durchgefuehrt werden konnte
bool rechne( char operation )
{
  if(stack.top < 2) {
    print("No valid operation");
    return false;
  }

  int zahl1 = pop();
  int zahl2 = pop();
  if(operand == '-') push(zahl2 - zahl1);
  if(operand == '+') push(zahl2 + zahl1);
  if(operand == '*') push(zahl2 * zahl1);
  if(operand == '/') push(zahl2 / zahl1);
  
  return true;
}

int main( int argc, char *argv[] )
{
  stack.top = 0;
  char* arg = argv[1];
  bool leseZahl = false;
  int zahl = 0;

  for(int i = 0; i <= strlen(arg); i++) {
    char zeichen = arg[i];
    if(zeichen >= '0' && zeichen <= '9') {
      leseZahl = true;
      zahl = zahl * 10 + (zeichen - '0');
    } else {
      if (leseZahl) {
        push(zahl);
        leseZahl = false;
        zahl = 0;
      }

      if(zeichen == '+' || zeichen == '*' || zeichen == '/' || zeichen == '-') {
        if(!rechne(zeichen)) {
          return false;
        }
      }
    }
    
    if(leseZahl) {
      push(zahl);
      leseZahl = false;
      zahl = 0;
    }

    if(stack.top == 1) {
      print("Result : ");
      print(pop());
    }
    else {
      print("no valid operation!");
    }
    return true;
  }

  return 0;
}
