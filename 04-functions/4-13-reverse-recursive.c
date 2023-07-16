#include <stdio.h>

#define BUF_SIZE 32

void str_reverse(char in[]);

void str_reverse_r(char in[], int i, int j);

int main() {
  printf("Reverse a string in place using recursion\n");
  printf("=========================================\n");
  char in[BUF_SIZE] = "7 3 5 2 1 0 3 8";

  printf("\"%s\" reversed is: ", in);
  str_reverse(in);
  printf("\"%s\"\n", in);

  return 0;
}

void str_reverse(char in[]) {
  int len = 0;

  while (in[len] != '\0') {
    len++;
  }

  str_reverse_r(in, 0, len - 1);
}

void str_reverse_r(char in[], int i, int j) {
  if (i > j)
    return;

  char temp = in[i];
  in[i] = in[j];
  in[j] = temp;

  str_reverse_r(in, i + 1, j - 1);
}