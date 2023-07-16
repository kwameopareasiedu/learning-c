#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_LINE_LENGTH 1000

int get_line(char line[], int limit);

void trim_line(char line[], int length);

int main() {
  printf("Trims trailing blanks and tabs from lines and ignores entirely blank lines\n");
  printf("==========================================================================\n");
  printf("Enter some text:\n");

  int len;
  char line[MAX_LINE_LENGTH];

  while ((len = get_line(line, MAX_LINE_LENGTH)) > 0) {
    printf("Input:  \"%s\"\n", line);
    trim_line(line, len);
    printf("Output: \"%s\"\n", line);
  }

  return 0;
}

int get_line(char line[], int limit) {
  int count = 0, pos = 0, c;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      break;
    }

    // Copy if pos < limit - 1, because line[limit - 1]
    // will be the null terminator
    if (pos < limit - 1) {
      line[pos++] = (char) c;
    }

    count++;
  }

  line[pos] = '\0';

  return count;
}

// Trims the blank spaces of the line and returns
// true (1) or false (0) if the final line is valid
// (I.e. whether the line has more than 1 character)
void trim_line(char line[], int length) {
  int counter = 0;
  int blank_encountered = FALSE;
  int blank_start_pos = 0;

  while (counter < length) {
    if (line[counter] == ' ' || line[counter] == '\t') {
      if (blank_encountered == FALSE) {
        blank_start_pos = counter;
      }
      
      blank_encountered = TRUE;
    } else {
      blank_encountered = FALSE;
    }

    counter++;
  }

  // If blank_encountered is still true at this point
  // terminate the line at blank_start_pos
  if (blank_encountered == TRUE) {
    line[blank_start_pos] = '\0';
  }
}