#include <stdio.h>

# define MAX_LINE_LENGTH 1000
# define CHARACTER_THRESHOLD 80

int get_line(char line[], int limit);

int main() {
  printf("Print all input lines longer than 80 characters\n");
  printf("===============================================\n");
  printf("Enter some text:\n");

  int len = 0;
  char line[MAX_LINE_LENGTH];

  while ((len = get_line(line, MAX_LINE_LENGTH)) > 0) {
    if (len >= CHARACTER_THRESHOLD) {
      printf("More than 80 chars: \"%s\"\n", line);
    }
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
