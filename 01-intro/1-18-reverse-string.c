#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_LINE_LENGTH 1000

int get_line(char line[], int limit);

int trim_line(char line[], int length);

void reverse_line(char line[], int length);

int main() {
  printf("Reverses lines as they are being types\n");
  printf("======================================\n");
  printf("Enter some text:\n");

  int len;
  char line[MAX_LINE_LENGTH];

  while ((len = get_line(line, MAX_LINE_LENGTH)) > 0) {
    printf("Input:    \"%s\"\n", line);
    len = trim_line(line, len);
    printf("Trimmed:  \"%s\"\n", line);
    reverse_line(line, len);
    printf("Reversed: \"%s\"\n", line);
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
// the length of the trimmed line
int trim_line(char line[], int length) {
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
    return blank_start_pos;
  } else {
    return length;
  }
}

void reverse_line(char line[], int length) {
  char holder;
  int half_length = (int) (length / 2);

  for (int i = 0; i < half_length; i++) {
    holder = line[i];
    line[i] = line[length - i - 1];
    line[length - i - 1] = holder;
  }
}