#include <stdio.h>

#define STR_SIZE 64

void strncpy(char *dest, const char *src, int num);

void strncat(char *dest, const char *src, int num);

int strncmp(const char *s1, const char *s2, int num);

int main() {
  printf("Test pointer variants of 'strncpy', 'strncat' and 'strncmp' string functions\n");
  printf("============================================================================\n");
  char str[STR_SIZE] = "The quick brown fox jumps over the lazy dog";
  char str1[] = "abcd", str2[] = "abCd";

  printf("Str is \"%s\"\n", str);

  strncpy(str, "That sly  ", STR_SIZE);
  printf("After copying \"The sly  \", str is now \"%s\"\n", str);

  strncat(str, " because that's what foxes do", STR_SIZE);
  printf("After concatenating \" because that's what foxes do\", str is now \"%s\"\n", str);

  int result = strncmp(str1, str2, 4);
  printf("\"%s\" = \"%s\": %d\n", str1, str2, result);

  return 0;
}

void strncpy(char *dest, const char *src, int num) {
  while (*src && (*dest++ = *src++) && num-- > 1);
}

void strncat(char *dest, const char *src, int num) {
  while (*dest++);
  dest--;
  while ((*dest++ = *src++) && num-- > 1);
}

int strncmp(const char *s1, const char *s2, int num) {
  while (*s1 && *s2 && num-- > 0) {
    if (*s1 < *s2) return -1;
    else if (*s1 > *s2) return 1;
    else {
      s1++;
      s2++;
    }
  }

  return 0;
}