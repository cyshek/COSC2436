#include <iostream>
using namespace std;

//Searches given array for value recursively using binary search. If value is present in the array, function will return the correct index, else return -1.
int binarySearchRecursive (int* arr, int low, int high, int val) {
  if (low > high) {
    return -1;
  }
  int mid = low + (high - low) / 2;
  if (arr[mid] == val) {
    return mid;
  } else if (arr[mid] < val) {
    return binarySearchRecursive(arr, mid + 1, high, val);
  } else {
    return binarySearchRecursive(arr, low, mid - 1, val);
  }
  return -1;
}

int main() {
  int arr [] = {1, 2, 3, 4, 5, 6, 7};
  cout << "Index found: " << binarySearchRecursive(arr, 0, 7, 4);
}

