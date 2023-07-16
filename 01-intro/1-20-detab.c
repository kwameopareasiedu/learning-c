#include <stdio.h>

#define BUFFER_CHAR_SIZE 1000
#define TAB_STOPS 4

int get_line(char input[], int limit);

void detab(const char input[], char output[], int tab_stops);

int main() {
  printf("Replace tabs in input with spaces till next tab stop\n");
  printf("====================================================\n");
  printf("Enter some text\n");

  char input[BUFFER_CHAR_SIZE], output[BUFFER_CHAR_SIZE];

  while (get_line(input, BUFFER_CHAR_SIZE) > 0) {
    printf("Input:  \"%s\"\n", input);
    detab(input, output, TAB_STOPS);
    printf("Output: \"%s\"\n", output);
  }

  return 0;
}

int get_line(char input[], int limit) {
  int len = 0, c;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      break;
    }

    if (len < limit - 1) {
      input[len] = (char) c;
      len++;
    }
  }

  input[len] = '\0';

  return len;
}

void detab(const char input[], char output[], int tab_stops) {
  int i_idx = 0, o_idx = 0, col = 0;
  char c = 'a';

  while (c != '\0') {
    c = input[i_idx++];

    if (c == '\t') {
      for (int j = 0; j < tab_stops - col; j++) {
        output[o_idx++] = ' ';
      }

      col = 0;
    } else {
      output[o_idx++] = c;
      col = i_idx % tab_stops;
    }
  }

  output[o_idx] = '\0';
}