#include <stdio.h>

#define BUF_SIZE 512

int get_line(char buffer[], int limit);

int strindex(const char str[], char t);

int main() {
  printf("Find last index of a letter in a string\n");
  printf("=======================================\n");
  printf("Enter some text: ");
  char input[BUF_SIZE], target = 'z';

  while ((get_line(input, BUF_SIZE)) > 0) {
    printf("Input: %s\n", input);
    printf("Last index of '%c' is %d\n", target, strindex(input, target));
  }

  return 0;
}

int get_line(char buffer[], int limit) {
  int len = 0, c;

  while ((c = getchar()) != EOF && len < limit - 1) {
    if (c == '\n') {
      break;
    }

    buffer[len] = (char) c;
    len++;
  }

  buffer[len] = '\0';

  return len;
}

int strindex(const char str[], char t) {
  int i = 0, index = -1;
  char c;

  while ((c = str[i++]) != '\0') {
    if (c == t) index = i - 1;
  }

  return index;
}