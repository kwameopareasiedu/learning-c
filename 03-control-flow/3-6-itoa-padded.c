#include <stdio.h>

#define BUF_LEN 32

void itoa(int num, char buf[], int min_width);

void reverse(char str[], int len);

int main() {
  printf("Convert integer to left-padded string\n");
  printf("=====================================\n");
  int num = 94891839;
  char buf[BUF_LEN];

  itoa(num, buf, 16);
  printf("itoa2: %d = \"%s\"\n", num, buf);

  return 0;
}

void itoa(int num, char buf[], int min_width) {
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

  // Pad numbers
  if (i < min_width) {
    for (int j = i; j < min_width; j++) {
      buf[i++] = ' ';
    }
  }

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