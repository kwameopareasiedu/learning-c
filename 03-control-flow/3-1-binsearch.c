#include <stdio.h>
#include <time.h>

#define LARGE_ARR_SIZE 100000
#define MICROSECONDS_PER_SECOND 1000000

int binsearch(int target, const int items[], int length);

int fastbinsearch(int target, const int items[], int length);

int main() {
  printf("Search for item using two binary searches and measure time\n");
  printf("==========================================================\n");
  int items[LARGE_ARR_SIZE], target = 76290, result;
  long double exec_time_micro;
  clock_t start, end;

  for (int i = 0; i < LARGE_ARR_SIZE; i++) {
    items[i] = i + 1;
  }

  start = clock();
  result = binsearch(target, items, LARGE_ARR_SIZE);
  end = clock();
  exec_time_micro = MICROSECONDS_PER_SECOND * (long double) (end - start) / CLOCKS_PER_SEC;
  printf("binsearch: Found %d at index %d in %.2Lf microseconds\n", target, result, exec_time_micro);

  start = clock();
  result = fastbinsearch(target, items, LARGE_ARR_SIZE);
  end = clock();
  exec_time_micro = MICROSECONDS_PER_SECOND * (long double) (end - start) / CLOCKS_PER_SEC;
  printf("fastbinsearch: Found %d at index %d in %.2Lf microseconds\n", target, result, exec_time_micro);

  return 0;
}

int binsearch(int target, const int items[], int length) {
  int start = 0, end = length - 1, mid;

  while (start <= end) {
    mid = (start + end) / 2;

    if (target < items[mid])
      end = mid + 1;
    else if (target > items[mid])
      start = mid + 1;
    else {
      return mid;
    }
  }

  return -1;
}

int fastbinsearch(int target, const int items[], int length) {
  int start = 0, end = length - 1, mid;

  while (1) {
    mid = (start + end) / 2;

    if (start > end) {
      break;
    } else if (target < items[mid])
      end = mid + 1;
    else if (target > items[mid])
      start = mid + 1;
    else {
      return mid;
    }
  }

  return mid;
}