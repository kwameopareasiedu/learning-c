#include <stdio.h>

#define STR_SIZE 64

int strend(char *str, char *t);

int main() {
  printf("Find a string at the end of another using pointers\n");
  printf("==================================================\n");

  char str[STR_SIZE] = "The quick brown fox jumps over the lazy dog", target[STR_SIZE] = "dog";
  int found = strend(str, target);

  if (found) {
    printf("\"%s\" was found at the end of \"%s\"\n", target, str);
  } else {
    printf("\"%s\" was not found at the end of \"%s\"\n", target, str);
  }

  return 0;
}

int strend(char *str, char *t) {
  char *t_copy = t;

  while (*str++) {
    if (*str == *t) t++;
    else t = t_copy;
  }

  return *str == '\0' && *t == '\0';
}