#include <iostream>
using namespace std;

// Computes the factorial of a given number. The factorial function is called recursively.

int factorial (int n) {
  if (n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  cout << factorial(5) << endl;
  return 0;
}