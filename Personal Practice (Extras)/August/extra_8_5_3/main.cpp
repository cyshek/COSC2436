#include <iostream>
using namespace std;

//Print elements of an array recursively. Prints the array from first element to last element.
int i = 0;
void printArr (int* arr, int size) {
  if (i == size) {
    return;
  } else {
    cout << arr[i] << " ";
    i++;
    printArr(arr, size);
  }
}

int main() {
  int arr[] = { 1, 4, 67, 859, 45, 3 };
  int n = sizeof(arr) / sizeof(arr[0]);
  printArr(arr, n);

  return 0;
}