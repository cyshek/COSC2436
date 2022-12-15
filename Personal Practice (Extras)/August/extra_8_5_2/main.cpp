#include <iostream>
using namespace std;

//Add integers from 1 to n. Return type is integer becuase we are adding integers and not printing.
int addNums(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n + addNums(n - 1);
  }
}

int main() {
  cout << addNums(5);
  return 0;
}