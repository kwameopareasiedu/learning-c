#include <stdio.h>
#include "utils/bitops.c"

int main() {
  printf("Rotate x by 'n' bits to the right\n");
  printf("=================================\n");
  int x = 6, n = 2;
  int res = rightrot(x, n);

  printf("x: %d (%b), num: %d = %d (%b)\n", x, x, n, res, res);

  return 0;
}