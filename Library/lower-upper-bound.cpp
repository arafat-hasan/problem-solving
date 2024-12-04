#include <stdio.h>

int lower_bound(int arr[], int size, int target) {
  int low = 0;
  int high = size;

  while (low < high) {
    int mid = low + (high - low) / 2;
    if (target <= arr[mid]) high = mid;
    else low = mid + 1;
  }

  if(low < size && arr[low] < target) low++;

  return low;
}

int upper_bound(int arr[], int size, int target) {
  int low = 0;
  int high = size;

  while (low < high) {
    int mid = low + (high - low) / 2;
    if (target >= arr[mid])  low = mid + 1;
    else high = mid;
  }

  if(low < size && arr[low] <= target) low++;

  return low;
}

void printBound(int arr[], int size, int target) {

  printf("Given array is\n");
  for(int i = 0; i < size; i++) printf("%d ", arr[i]);
  printf("\n");

  if (lower_bound(arr, size, target) == size) {
    printf("Lower bound doesn't exist\n");
  }
  else {
    int idx = lower_bound(arr, size, target);
    printf("Lower bound of %d is at index %d, value %d\n", target, idx, arr[idx]);
  }

  if (upper_bound(arr, size, target) == size) {
    printf("Upper bound doesn't exist\n");
  }
  else {
    int idx = upper_bound(arr, size, target);
    printf("Upper bound of %d is at index %d, value %d\n", target, idx, arr[idx]);
  }

  printf("\n\n");

}

int main() {
  int arr[] = {4, 6, 6, 6, 10, 12, 18, 20};
  int size = sizeof(arr) / sizeof(arr[0]);

  int target = 6;
  printBound(arr, size, target);


  int arr2[] = {6, 6, 6, 10, 12, 18, 20 };
  size = sizeof(arr2) / sizeof(arr2[0]);

  target = 1;
  printBound(arr2, size, target);

  int arr3[] = {6, 6, 6, 10, 12, 18, 20 };
  size = sizeof(arr3) / sizeof(arr3[0]);

  target = 100;
  printBound(arr3, size, target);

  return 0;
}
