#include <stdio.h>

int main() {
  printf("Copy input, replacing multiple consecutive blanks with a single blank\n");
  printf("=====================================================================\n");
  printf("Enter some text:\n");

  int c;
  int is_blank = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      if (is_blank == 0) {
        printf("%c", c);
        is_blank = 1;
      }
    } else {
      printf("%c", c);
      is_blank = 0;
    }
  }

  return 0;
}