#include <stdio.h>
#include "utils/bitops.c"

int main() {
  printf("Invert 'n' bits of 'x' starting at index 'p' from the right\n");
  printf("===========================================================\n");
  int x = 91, p = 4, n = 4;
  int res = invertbits(x, p, n);

  printf("x: %d (%b), pos: %d, num: %d = %d (%b)\n", x, x, p, n, res, res);

  return 0;
}