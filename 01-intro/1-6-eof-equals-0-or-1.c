#include <stdio.h>

int main() {
  printf("Check whether getchar() != EOF is 0 or 1\n");
  printf("========================================\n");
  
  printf("%b", getchar() != EOF);

  return 0;
}