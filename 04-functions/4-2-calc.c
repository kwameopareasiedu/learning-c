#include <stdio.h>
#include "calc/calc.c"

#define BUF_SIZE 32

int main() {
  printf("Compute arithmetic operations using the Polish-notation\n");
  printf("-------------------------------------------------------\n");
  printf("Enter an operation:\n");
  char buffer[BUF_SIZE];

  while (get_stdin_operation(buffer, BUF_SIZE) > 0) {
    double res = calculate(buffer);
    printf("\"%s\" = %.4f\n", buffer, res);
  }

  return 0;
}