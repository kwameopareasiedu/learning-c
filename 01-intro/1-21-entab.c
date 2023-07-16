#include <stdio.h>

#define BUFFER_CHAR_SIZE 1000
#define TAB_STOPS 4

int get_line(char input[], int limit);

void entab(const char input[], char output[], int tab_stops);

int main() {
  printf("Replace a series of spaces with tabs and spaces to match input\n");
  printf("==============================================================\n");
  printf("Enter some text\n");

  char input[BUFFER_CHAR_SIZE], output[BUFFER_CHAR_SIZE];

  while (get_line(input, BUFFER_CHAR_SIZE) > 0) {
    printf("Input:  \"%s\"\n", input);
    entab(input, output, TAB_STOPS);
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

void entab(const char input[], char output[], int tab_stops) {
  // cb = consecutive blanks
  int cb_count = 0;
  int i_idx = 0, o_idx = 0;
  char c = input[i_idx];

  while (c != '\0') {
    c = input[i_idx++];

    if (c == ' ' || c == '\t') {
      cb_count += (c == ' ' ? 1 : tab_stops);

      int tabs_to_insert = cb_count / tab_stops;
      int spaces_to_insert = cb_count % tab_stops;

      if (cb_count >= tab_stops) {
        for (int i = 0; i < tabs_to_insert; i++) {
          output[o_idx++] = '\t';
        }

        for (int i = 0; i < spaces_to_insert; i++) {
          output[o_idx++] = ' ';
        }
      } else {
        output[o_idx++] = c;
      }
    } else {
      cb_count = 0;
      output[o_idx++] = c;
    }
  }

  output[o_idx] = '\0';
}