#include <iostream>
using namespace std;

//This is a sorting algorithm that compares an unsorted value with a sorted value, shifting the sorted value to the right if the unsorted value is < than the sorted value. Integer array is sorted using insertion and printed.
void insertion_sort (int* arr, int size) {
  int value, index;
  for (int i = 1; i < size; i++) {
    value = arr[i];
    index = i;
    while (index >= 0 && arr[index - 1] > value) {
      arr[index] = arr[index - 1];
      index--;
    }
    arr[index] = value;
  }
}

int main() {
  int array [] = {5, 6, 3, 2, 4, 1};
  insertion_sort(array, 6);
  for (auto i: array) {
    cout << i << " ";
  }
}