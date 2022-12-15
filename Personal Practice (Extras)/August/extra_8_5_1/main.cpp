#include <iostream>
using namespace std;

//Write a recursive function from 1 to n. Focus on using recursion and closing the stack.
void printNums(int n) { //Void because we are printing.
  if (n == 0) {
    return;
  } else {
    printNums(n - 1);
    cout << n << endl;
  }
}


int main() {
  printNums(19);
  
  return 0;
}