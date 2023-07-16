#include <stdio.h>

#define BUF_SIZE 4096

int get_line(char buffer[], int limit);

void escape(const char input[], char output[], int limit);

int main() {
  printf("Print escape sequences in strings\n");
  printf("=================================\n");
  printf("Enter some text:\n");
  char input[BUF_SIZE], output[BUF_SIZE];

  while (get_line(input, BUF_SIZE) > 0) {
    escape(input, output, BUF_SIZE);
    printf("Out: %s\n", output);
  }

  return 0;
}

int get_line(char buffer[], int limit) {
  int len = 0, c;

  while ((c = getchar()) != EOF && len < limit - 1) {
    if (c == '\n') break;
    buffer[len++] = (char) c;
  }

  buffer[len] = '\0';

  return len;
}

void escape(const char input[], char output[], int limit) {
  int i_idx = 0, o_idx = 0;
  char c;

  while((c = input[i_idx++]) != '\0' && o_idx < limit - 1) {
    switch (c) {
      case '\n':
        output[o_idx++] = '\\';
        output[o_idx++] = 'n';
        break;
      case '\t':
        output[o_idx++] = '\\';
        output[o_idx++] = 't';
        break;
      default:
        output[o_idx++] = c;
    }
  }

  output[o_idx] = '\0';
}