#include <stdio.h>

#define BUF_SIZE 32

void itoa(int num, char out[]);

int itoa_r(int num, int is_negative, char out[]);

int main() {
  printf("Convert an integer to a string using recursion\n");
  printf("==============================================\n");
  int num = 12345;
  char buf[BUF_SIZE];

  itoa(num, buf);

  printf("itoa: %d = \"%s\"\n", num, buf);

  return 0;
}

void itoa(int num, char out[]) {
  int is_negative = num < 0;
  if (is_negative) num *= -1;
  int idx = itoa_r(num, is_negative, out);
  out[idx + 1] = '\0';
}

int itoa_r(int num, int is_negative, char out[]) {
  if (num < 10) {
    if (is_negative) {
      out[0] = '-';
      out[1] = (char) ('0' + num);
      return 1;
    }

    out[0] = (char) ('0' + num);
    return 0;
  }

  int idx = itoa_r(num / 10, is_negative, out) + 1;
  out[idx] = (char) ('0' + num % 10);
  return idx;
}