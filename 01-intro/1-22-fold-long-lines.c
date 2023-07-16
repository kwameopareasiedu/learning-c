#include <stdio.h>

#define BUFFER_CHAR_SIZE 2048
#define LINE_LIMIT 80
#define FALSE 0
#define TRUE 1

int get_line(char input[], int limit);

void fold_line(const char input[], char output[], int line_limit);

int main() {
  printf("Fold long lines into mutiple shorter lines\n");
  printf("==========================================\n");
  printf("Enter some text\n");

  char input[BUFFER_CHAR_SIZE], output[BUFFER_CHAR_SIZE];
  int len;

  while ((len = get_line(input, BUFFER_CHAR_SIZE)) > 0) {
    printf("Input (%d chars)\n%s\n", len, input);
    fold_line(input, output, LINE_LIMIT);
    printf("Output\n%s\n", output);
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

void fold_line(const char input[], char output[], int line_limit) {
  int i_idx = 0, col_idx = 0, word_idx = 0;
  int word_encountered = FALSE;
  char c = input[i_idx];

  while (c != '\0') {
    c = input[i_idx];

    if (c != ' ' && c != '\t') {
      if (word_encountered == FALSE) {
        word_idx = i_idx;
      }

      word_encountered = TRUE;
    } else {
      word_encountered = FALSE;
    }

    if (col_idx == line_limit - 1) {
      printf("Revert from %d (%c) to %d  (%c)\n", i_idx, input[i_idx], word_idx, input[word_idx]);

      if (word_encountered) {
        i_idx = word_idx - 1;
      }

      output[i_idx++] = '\n';
      col_idx = 0;
    }

    output[i_idx] = input[i_idx];
    col_idx++;
    i_idx++;
  }

  output[i_idx] = '\0';
}