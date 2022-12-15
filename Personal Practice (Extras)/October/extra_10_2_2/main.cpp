#include <iostream>
using namespace std;

//This is a program that sorts an integer array of size 5 using merge sort. Relies on mergeSort function to continuously divide the array. Merge function is used to sort the pieces and build the array back together.
void merge(int low, int high, int mid, int* arr) {
  int i = low;   //starting index for left subarray
  int j = mid + 1;  //starting index for right subarray
  int k = low;    //starting index for temporary

  int temp[5];    //temporary

  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j]) {
      temp[k] = arr[i];  //arr[i] is smaller than arr[j]
      i++;
      k++;
    } else {
      temp[k] = arr[j];  //arr[j] is smaller than arr[i]
      j++;
      k++;      
    }
  }

  while (i <= mid) {
    temp[k] = arr[i];  //copying all elements from left subarray to temp as it is
    i++;
    k++;    
  }

  while (j <= high) {
    temp[k] = arr[j];  //copying all elements from right subarray to temp as it is
    j++;
    k++;    
  }

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i];
  }
}

void mergeSort (int low, int high, int* arr) {
  int mid;  
  if (low < high) {
    mid = (low + high) / 2;
    mergeSort(low, mid, arr);
    mergeSort(mid + 1, high, arr);
    merge(low, high, mid, arr);
  }
}

int main() {
  int array [] = {45, 3, 12, 56, 4};
  int low = 0;
  int high = 4;

  mergeSort(low, high, array);

  for (int i = 0; i < 5; i++) {
    cout << array[i] << " ";
  }
}