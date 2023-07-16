#include <stdio.h>
#include <ctype.h>

#define READ_SUCCESS 0
#define READ_FAILED 1

int getint(int *pn);

int main() {
  printf("Get the next integer from the input stream\n");
  printf("==========================================\n");
  printf("Enter a numeric value:\n");
  int nextInt = 0;

  int status = getint(&nextInt);

  if (status == READ_SUCCESS) {
    printf("Successfully read number %d\n", nextInt);
  } else {
    printf("Failed to read next integer");
  }

  return 0;
}

int getint(int *pn) {
  int c, is_negative;

  // Skip white space
  while (isspace(c = getchar()));

  // Ignore non-numbers
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetc(c, stdin);
    return READ_FAILED;
  }

  is_negative = c == '-';

  // Get next number after sign
  if (c == '+' || c == '-') {
    c = getchar();

    if (!isdigit(c)) {
      ungetc(c, stdin);
      return READ_FAILED;
    }
  }

  // Get the next digits
  for (*pn = 0; isdigit(c); c = getchar()) {
    *pn = 10 * *pn + (c - '0');
  }

  if (is_negative) {
    *pn *= -1;
  }

  if (c != EOF) {
    ungetc(c, stdin);
  }

  return READ_SUCCESS;
}