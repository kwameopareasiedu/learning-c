#include <stdio.h>

int main() {
  printf("Substitute input with tab, backspace and back slash with \\t, \\b and \\ respectively\n");
  printf("=====================================================================================\n");
  printf("Enter some text:\n");

  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\t') printf("\\t");
    else if (c == '\b') printf("\\b");
    else if (c == '\\') printf("\\\\");
    else printf("%c", c);
  }

  return 0;
}