#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 64
#define ASCII_BUF_SIZE 128

int any(const char src[], const char target[]);

int main() {
  printf("Find first index of any characters of one string in another\n");
  printf("===========================================================\n");

  char s1[BUFFER_SIZE] = "The quick brown fox jumps over the lazy dog", s2[BUFFER_SIZE] = "eiou";

  printf("S1: \"%s\"\n", s1);
  printf("S2: \"%s\"\n", s2);
  int idx = any(s1, s2);

  if (idx > -1) {
    printf("Characters of \"%s\" are first found in \"%s\" at index %d\n", s2, s1, idx);
  } else {
    printf("Characters of \"%s\" not found in \"%s\"\n", s2, s1);
  }

  return 0;
}

int any(const char src[], const char target[]) {
  char ascii_buf[ASCII_BUF_SIZE];
  int ascii_pos_buf[ASCII_BUF_SIZE];
  int src_idx = 0, target_idx = 0;
  char c;

  for (int i = 0; i < ASCII_BUF_SIZE; i++) {
    ascii_buf[i] = 0;
    ascii_pos_buf[i] = -1;
  }

  while ((c = src[src_idx++]) != '\0') {
    int ascii_idx = (int) c;

    ascii_buf[ascii_idx] = 1;

    if (ascii_pos_buf[ascii_idx] == -1) {
      ascii_pos_buf[ascii_idx] = src_idx - 1;
    }
  }

  while ((c = target[target_idx++]) != '\0') {
    int ascii_idx = (int) c;

    if (ascii_buf[ascii_idx]) {
      return ascii_pos_buf[ascii_idx];
    }
  }

  return -1;
}