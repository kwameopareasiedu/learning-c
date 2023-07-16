#include <stdio.h>

# define MAX_LINE_LENGTH 10

int get_line(char line[], int limit);

void copy_line(char dest[], const char src[]);

int main() {
  printf("Print the longest line in a series of lines\n");
  printf("===========================================\n");
  printf("Enter some text:\n");

  int current_length, max_length = 0;
  char current_line[MAX_LINE_LENGTH], longest_line[MAX_LINE_LENGTH];

  while ((current_length = get_line(current_line, MAX_LINE_LENGTH)) > 0) {
    if (current_length > max_length) {
      copy_line(longest_line, current_line);
      max_length = current_length;
    }
  }

  if (max_length > 0) {
    printf("Longest line: %s\nLine length: %d", longest_line, max_length);
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

void copy_line(char dest[], const char src[]) {
  int i = 0;

  // Copy till a null terminator is reached
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
}