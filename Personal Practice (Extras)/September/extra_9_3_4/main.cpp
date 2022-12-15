#include <iostream>
using namespace std;

//Searches given array for value recursively. If value is present in the array, function will return the correct index, else return -1
int linearSearchRec(int* arr, int size, int val) {
  if (val == arr[size - 1] || size < 0) {
    if (size < 0) {
      return -1;
    } else {
      return size - 1;
    }
  }
  return linearSearchRec(arr, size - 1, val);
}
int main() {
  int arr [] = {1, 2, 3, 4, 5, 6, 7};
  cout << "Index found: " << linearSearchRec(arr, 7, 5);
}

