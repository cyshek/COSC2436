#include <iostream>
using namespace std;

//This is a sorting algorithm that compares each pair of adjacent elements. If element on the left is greater than the element on the right, we swap them.
void bubble_sort (int* arr, int size) {
  int temp;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] > arr[j]) {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
}

int main() {
  int array [] = {5, 6, 3, 2, 4, 1};
  bubble_sort(array, 6);
  for (auto i: array) {
    cout << i << " ";
  }
}