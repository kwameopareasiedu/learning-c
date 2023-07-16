#include <stdio.h>

#define BUF_SIZE 32

void itob(int num, char buf[], int base);

void reverse(char str[], int len);

int main() {
  printf("Convert an integer to a specified base\n");
  printf("======================================\n");

  int num = 84783, base = 16;
  char buf[BUF_SIZE];

  itob(num, buf, base);
  printf("%d (10) = %s (%d)\n", num, buf, base);
  return 0;
}

void itob(int num, char buf[], int base) {
  int i = 0, is_negative = num < 0;

  if (is_negative) num = -num;

  do {
    int rem = (num % base);

    if (rem < 0) {
      rem *= -1;
      num += rem;
      num *= -1;
    }

    char start = rem >= 10 ? 'A' : '0';
    rem %= 10;

    buf[i++] = (char) (rem + start);
  } while ((num /= base) > 0);

  if (is_negative) buf[i++] = '-';

  buf[i] = '\0';

  reverse(buf, i);
}

void reverse(char str[], int len) {
  int mid = len / 2;
  char temp;

  for (int i = 0; i < mid; i++) {
    temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }
}