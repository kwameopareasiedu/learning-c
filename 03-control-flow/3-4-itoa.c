#include <stdio.h>
#include <limits.h>

#define BUF_LEN 32

void itoa(int num, char buf[]);

void itoa2(int num, char buf[]);

void reverse(char str[], int len);

int main() {
  printf("Convert integer to string\n");
  printf("=========================\n");
  int num = INT_MIN;
  char buf[BUF_LEN];

  itoa(num, buf);
  printf("itoa: %d = \"%s\"\n", num, buf);
  itoa2(num, buf);
  printf("itoa2: %d = \"%s\"\n", num, buf);

  return 0;
}

void itoa(int num, char buf[]) {
  int i = 0, is_negative = num < 0;

  /*
   * In a 2's complement system the negative of a number
   * is computed by (~num) + 1. If num == INT_MIN (-2147483648),
   * using 2's complement is the same number since the starting
   * bit is the sign.
   * Taking the mod to base 10 gives a result -8 which when added
   * to '0' results in the character '('. This is why this itoa
   * cannot handle the largest negative number.
   */
  if (is_negative) num = -num;

  do {
    buf[i++] = (char) ((num % 10) + '0');
  } while ((num /= 10) > 0);

  if (is_negative) buf[i++] = '-';

  buf[i] = '\0';

  reverse(buf, i);
}

void itoa2(int num, char buf[]) {
  int i = 0, is_negative = num < 0;

  if (is_negative) num = -num;

  do {
    int rem = (num % 10);

    if (rem < 0) {
      rem *= -1;
      num += rem;
      num *= -1;
    }

    buf[i++] = (char) (rem + '0');
  } while ((num /= 10) > 0);

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