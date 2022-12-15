#include <iostream>
#include <queue>
using namespace std;

//This is a program that uses a queue to print a heap in level order. Takes in a heap and its size as a parameter.
void print_level_order (int* heap, int size) {
  queue<int> tree; 
  tree.push(0);
  tree.push(-1);
  int counter = 1;

  while (!tree.empty()) {
    int i = tree.front();
    if (i != -1) {
      cout << heap[i] << " ";
      if ((2 * i + 1) < size) {
        tree.push(2 * i + 1);
        counter++;
      }
      if ((2 * i + 2) < size) {
        tree.push(2 * i + 2);
        counter++;
      }
    } else {
      cout << endl;
      if (counter < size) {
        tree.push(-1);
      }
    }
    tree.pop();
  }
}

int main() {
  int arr [] = {10, 9, 6, 5, 1, 2, 3};
  print_level_order(arr, 7);
}