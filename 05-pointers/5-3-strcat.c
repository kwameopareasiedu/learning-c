#include <stdio.h>

#define STR_SIZE 16

void strcat(char *dest, char *source);

int main() {
  printf("Concatenate two strings using pointers\n");
  printf("======================================\n");
  char dest[STR_SIZE] = "Hello", src[STR_SIZE] = " World!";

  printf("Source was \"%s\"\n", dest);
  strcat(dest, src);
  printf("Source is now \"%s\"\n", dest);

  return 0;
}

void strcat(char *dest, char *source) {
  while (*dest++);
  dest--;
  while ((*dest++ = *source++));
  *dest = '\0';
}