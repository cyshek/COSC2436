#include <iostream>
using namespace std;

//This is a program that implements quick sort on an array. Partition function is used to find the sorted position of the pivot. Sorted array is outputted to the console.
int partition (int low, int high, int* arr) {
  int pivot = arr[low];
  int i = low;
  int j = high + 1;  //Since do while decrements it initiallly

  while (i < j) {
    do {
      i++;
    } while (arr[i] <= pivot);
    do {
      j--;
    } while (arr[j] > pivot);
    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[low], arr[j]);
  return j;
}

void quickSort (int low, int high, int* arr) {
  int j;
  if (low < high) {
    j = partition(low, high, arr);
    quickSort(low, j, arr);
    quickSort(j + 1, high, arr);
  }
}

int main() {
  int arr [] = {10, 16, 8, 12, 15, 6, 3, 9, 5};
  quickSort(0, 8, arr);
  cout << "Sorted Array: ";
  for (int i = 0; i < 9; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}