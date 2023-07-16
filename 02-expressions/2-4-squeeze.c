#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 64
#define ASCII_BUF_SIZE 128

void squeeze(char output[], const char s1[], const char s2[]);

int main() {
  printf("Delete matching characters from another string\n");
  printf("==============================================\n");
  char s1[BUFFER_SIZE] = "aeiou", s2[BUFFER_SIZE] = "The quick fox jumps over the lazy dog";
  char res[BUFFER_SIZE];

  printf("S1: \"%s\"\n", s1);
  printf("S2: \"%s\"\n", s2);
  squeeze(res, s2, s1);
  printf("SR: \"%s\"\n", res);

  return 0;
}

void squeeze(char output[], const char s1[], const char s2[]) {
  char asciiBuf[ASCII_BUF_SIZE];
  int s1_i = 0, s2_i = 0, out_i = 0;
  char c;

  for (int i = 0; i < ASCII_BUF_SIZE; i++) {
    asciiBuf[i] = 0;
  }

  while ((c = s2[s1_i++]) != '\0') {
    // Set buffer indices for matching characters
    asciiBuf[(int) c] = 1;
  }

  while ((c = s1[s2_i++]) != '\0') {
    if (!asciiBuf[(int) c]) {
      output[out_i++] = c;
    }
  }

  output[out_i] = '\0';
}