#include <stdio.h>

#define FALSE 0
#define TRUE 1

int main() {
  printf("Copy input to output, one word per line\n");
  printf("=======================================\n");
  printf("Enter some text:\n");

  int c;
  int is_blank = FALSE;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      if (is_blank == FALSE) {
        printf("\n");
        is_blank = TRUE;
      }
    } else {
      printf("%c", c);
      is_blank = 0;
    }
  }

  return 0;
}