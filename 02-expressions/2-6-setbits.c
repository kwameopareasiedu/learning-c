#include <stdio.h>
#include "utils/bitops.c"

int main() {
  printf("Set the last 'n' bits of 'x' at index 'p' from the right with the last 'n' bits of 'y'\n");
  printf("======================================================================================\n");
  int x = 93, p = 3, n = 3, y = 211;
  int res = setbits(x, p, n, y);

  printf("x: %d (%b), y: %d (%b), pos: %d, num: %d = %d (%b)\n", x, x, y, y, p, n, res, res);

  return 0;
}
