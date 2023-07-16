#include <stdio.h>
#include <ctype.h>

#define READ_SUCCESS 0
#define READ_FAILED 1
#define FALSE 0
#define TRUE 1

int getfloat(float *pf);

int main() {
  printf("Get the next floating point value from the input stream\n");
  printf("=======================================================\n");
  printf("Enter a numeric value:\n");
  float next_float = 0;

  int status = getfloat(&next_float);

  if (status == READ_SUCCESS) {
    printf("Successfully read number %f\n", next_float);
  } else {
    printf("Failed to read next integer");
  }

  return 0;
}

int getfloat(float *pf) {
  int c, is_negative = FALSE, has_fp = FALSE, dp = 10;

  // Skip white space
  while (isspace(c = getchar()));

  // Ignore non-numbers
  if (isdigit(c) || c == EOF || c == '+' || c == '-' || c == '.') {
    if (c == '-') is_negative = TRUE;

    // Get next number after sign
    if (c == '+' || c == '-') {
      c = getchar();

      if (!isdigit(c)) {
        ungetc(c, stdin);
        return READ_FAILED;
      }
    }

    // Get the next digits
    for (*pf = 0; isdigit(c) || c == '.'; c = getchar()) {
      if (c == '.') {
        // Decimal encountered more than once
        if (has_fp) break;

        has_fp = TRUE;
        continue;
      }

      if (!has_fp) {
        *pf = 10 * *pf + (float) (c - '0');
      } else {
        *pf += ((float) (c - '0') / (float) dp);
        dp *= 10;
      }
    }

    if (is_negative) {
      *pf *= -1;
    }

    if (c != EOF) {
      ungetc(c, stdin);
    }

    return READ_SUCCESS;
  } else {
    ungetc(c, stdin);
    return READ_FAILED;
  }
}