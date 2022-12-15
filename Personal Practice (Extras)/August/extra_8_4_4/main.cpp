#include <iostream>
using namespace std;

//Remember about the compiler calling the stack

//print nums from 1 - 10. Calls function recursively.
void printNums (int num) {
  if (num == 11) {
    return;
  } else {
    cout << num << endl;
    printNums(num + 1);
  }
}


int main() {
  printNums(1);
  return 0;
}