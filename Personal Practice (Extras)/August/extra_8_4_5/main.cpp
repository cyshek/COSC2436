#include <iostream>
using namespace std;

//Remember about the compiler calling the stack

//Prints out each digit in order. Takes a divider to determine the output
void numbers(int n, int d) {
  if (n == 0) {
    return;
  } else {
    cout << n/d << endl;
    numbers(n%d, d/10);
  }
}

int main() {
  numbers(472, 100);
  return 0;
}