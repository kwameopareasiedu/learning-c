#include <stdio.h>

#define BUF_SIZE 65536

int get_line(char buffer[], int limit);

void expand(const char input[], char output[]);

int main() {
  printf("Expand shorthand (a-z, 1-9) into complete lists\n");
  printf("===============================================\n");
  printf("Enter some text:\n");
  char input[BUF_SIZE], output[BUF_SIZE];

  while (get_line(input, BUF_SIZE) > 0) {
    expand(input, output);
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

void expand(const char input[], char output[]) {
  int i_idx = 0, o_idx = 0;
  char cn, cn_1, cn_2;

  while ((cn = input[i_idx++]) != '\0') {
    int start = 0, end = 0, dir = 1;

    if (cn_1 == '-' && (
        cn_2 >= 'A' && cn <= 'Z' || cn_2 >= 'a' && cn <= 'z' || cn_2 >= '0' && cn <= '9' ||
        cn >= 'A' && cn_2 <= 'Z' || cn >= 'a' && cn_2 <= 'z' || cn >= '0' && cn_2 <= '9'
    )) {
      start = (int) cn_2;
      end = (int) cn;

      if (end < start) dir = -1;
    }

    if (start != end) {
      // Backtrack 2 characters
      o_idx -= 2;

      printf("From %c to %c. Dir: %d\n", (char) start, (char) end, dir);

      for (int oc = start;; oc += dir) {
        output[o_idx++] = (char) oc;
        if (oc == end) break;
      }
    } else {
      output[o_idx++] = (char) cn;
    }

    cn_2 = cn_1;
    cn_1 = cn;
  }

  output[o_idx] = '\0';
}