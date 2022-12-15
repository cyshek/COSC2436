#include <iostream>
using namespace std;

//This is a sorting algorithm that takes the leftmost element in the unsorted part of the array and finds the smallest element to swap. Smallest element and current element are compared and may be swapped if element is smaller.
void selection_sort (int* arr, int size) {
  int small, temp;
  for (int i = 0; i < size - 1; i++) {
    small = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[small]) {
        small = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[small];
    arr[small] = temp;
  }
}

int main() {
  int array [] = {5, 6, 3, 2, 4, 1};
  selection_sort(array, 6);
  for (auto i: array) {
    cout << i << " ";
  }
}