#include <stdio.h>
#include <math.h>

#define BUFFER_SIZE 16
#define ZERO 48
#define NINE 57
#define UPPER_A 65
#define UPPER_F 70
#define LOWER_A 97
#define LOWER_F 102
#define UPPER_X 88
#define LOWER_X 120

int get_line(char buffer[], int max_length);

long int htoi(const char input[], int length);

int main() {
  printf("Convert a hex array into an integer\n");
  printf("===================================\n");
  printf("Enter a valid hex number: ");

  char hex_buffer[BUFFER_SIZE];
  int len;

  while ((len = get_line(hex_buffer, BUFFER_SIZE)) > 0) {
    printf("Input: %s\n", hex_buffer);
    long int converted = htoi(hex_buffer, len);
    printf("%s (16) = %ld (10): \n", hex_buffer, converted);

    printf("Enter a valid hex number: ");
  }
}

int get_line(char buffer[], int max_length) {
  int len = 0, c;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      break;
    }

    buffer[len++] = (char) c;

    if (len == max_length - 1) {
      break;
    }
  }

  buffer[len] = '\0';
  return len;
}

long int htoi(const char input[], int length) {
  int starts_with_0x = input[0] == ZERO && (input[1] == UPPER_X || input[1] == LOWER_X);
  int effective_length = starts_with_0x ? length - 2 : length;
  int exp_diff = starts_with_0x ? 1 : -1;
  int i = starts_with_0x ? 2 : 0;
  long int num = 0;

  printf("Len: %d, Eff. len: %d, i: %d\n", length, effective_length, i);

  for (; i < length; i++) {
    char c = input[i];
    int is_numeric = c >= ZERO && c <= NINE;
    int is_upper = c >= UPPER_A && c <= UPPER_F;
    int is_lower = c >= LOWER_A && c <= LOWER_F;
    int in_range = is_numeric || is_upper || is_lower;

    if (in_range) {
      int exponent = effective_length - i + exp_diff;
      int base = 0;

      if (is_numeric) {
        base = ((int) c) - ZERO;
      } else if (is_upper) {
        base = ((int) c) - UPPER_A + 10;
      } else if (is_lower) {
        base = ((int) c) - LOWER_A + 10;
      }

      printf("Base: %d, Exp: %d\n", base, exponent);

      num += base * (int) pow(16, exponent);
    } else {
      num = -1;
      break;
    }
  }

  return num;
}