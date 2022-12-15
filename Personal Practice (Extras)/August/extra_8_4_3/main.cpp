#include <iostream>
using namespace std;

//Remember about the compiler calling the stack



//Prints name 4 times recursively. This time we are calling a void fucntion.
void printName (string name, int repeat) {
  if (repeat == 0) {
    return;
  } else {
    
    cout << name << endl;
    printName(name, repeat-1);
  }
  
}

int main() {
  printName("Cyrus", 4);
  return 0;
}