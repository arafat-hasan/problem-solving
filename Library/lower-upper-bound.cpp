#include <stdio.h>

int lower_bound(int arr[], int size, int target)
{
  int mid;

  int low = 0;
  int high = size;

  while (low < high) {
    mid = low + (high - low) / 2;

    if (target <= arr[mid]) high = mid;
    else low = mid + 1;
  }

  if(low < size && arr[low] < target) {
    low++;
  }

  return low;
}

int upper_bound(int arr[], int size, int target)
{
  int mid;

  int low = 0;
  int high = size;

  while (low < high) {
    mid = low + (high - low) / 2;

    if (target >= arr[mid])  low = mid + 1;
    else high = mid;
  }

  if(low < size && arr[low] <= target) {
    low++;
  }

  return low;
}

void printBound(int arr[], int size, int target)
{
  int idx;

  if (lower_bound(arr, size, target) == size) {
    printf("Lower bound doesn't exist");
  }
  else {

    idx = lower_bound(arr, size, target);
    printf("Lower bound of %d is %d at index %d\n", target, arr[idx], idx);
  }

  if (upper_bound(arr, size, target) == size) {
    printf("Upper bound doesn't exist");
  }
  else {

    idx = upper_bound(arr, size, target);
    printf("Upper bound of %d is %d at index %d\n", target, arr[idx], idx);
  }
}

int main()
{
  int arr[] = { 4, 6, 6, 6, 10, 12, 18, 20 };
  int size = sizeof(arr) / sizeof(arr[0]);

  int target = 6;

  printBound(arr, size, target);
  return 0;
}
