#include <iostream>
using namespace std;

//Searches given array for value iteratively. If value is present in the array, function will return the correct index, else return -1
int linearSearch (int* arr, int size, int val) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (val == arr[i]) {
      return count;
    }
    count++;
  }
  return -1;
}

int main() {
  int arr [] = {1, 2, 3, 4, 5, 6, 7};
  cout << "Index found: " << linearSearch(arr, 7, 5);
}

