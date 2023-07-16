#include <stdio.h>

int main() {
  printf("Count number of blanks, tabs and new lines\n");
  printf("==========================================\n");
  printf("Enter some text\n");

  int blank_count, tab_count, line_count;
  blank_count = tab_count = line_count = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ') blank_count++;
    if (c == '\t') tab_count++;
    if (c == '\n') line_count++;
  }

  printf("Blanks: %d, Tabs: %d, Lines: %d", blank_count, tab_count, line_count);
  return 0;
}