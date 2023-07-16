#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
  printf("Print size of data types\n");
  printf("========================\n");

  printf("Signed Integer:: Size: %lu bytes, Min: %d, Max: %d\n", sizeof(int), INT_MIN, INT_MAX);
  printf("Unsigned Integer:: Size: %lu bytes, Min: %d, Max: %u\n\n", sizeof(unsigned int), 0, UINT_MAX);

  printf("Signed Character:: Size: %lu bytes, Min: %d, Max: %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
  printf("Unsigned Character:: Size: %lu bytes, Min: %d, Max: %d\n\n", sizeof(unsigned char), 0, UCHAR_MAX);

  printf("Float:: Size: %lu bytes, Min: %f, Max: %f\n\n", sizeof(float), FLT_MIN, FLT_MAX);

  printf("Double:: Size: %lu bytes, Min: %f, Max: %f\n\n", sizeof(double), DBL_MIN, DBL_MAX);

  return 0;
}