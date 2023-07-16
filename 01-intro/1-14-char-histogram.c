#include <stdio.h>

#define MAX_CHARS 26
#define ASCII_UPPERCASE_A 65
#define ASCII_UPPERCASE_Z 90
#define ASCII_LOWERCASE_A 97
#define ASCII_LOWERCASE_Z 122
#define UPPERCASE_LOWERCASE_INTERVAL 32

int main() {
  printf("Print a histogram of characters in the sentence\n");
  printf("===============================================\n");
  printf("Enter some text:\n");

  int histogram[MAX_CHARS];

  for (int i = 0; i < MAX_CHARS; i++) {
    histogram[i] = 0;
  }

  int c;

  while ((c = getchar()) != EOF) {
    // Process only letters
    if ((c >= ASCII_LOWERCASE_A && c <= ASCII_LOWERCASE_Z) || (c >= ASCII_UPPERCASE_A && c <= ASCII_UPPERCASE_Z)) {
      // Convert lowercase to uppercase
      if (c >= ASCII_LOWERCASE_A) {
        c -= UPPERCASE_LOWERCASE_INTERVAL;
      }

      // Update the character count in the histogram
      histogram[c - ASCII_UPPERCASE_A]++;
    }
  }

  // Print the histogram
  for (int i = 0; i < MAX_CHARS; i++) {
    int frequency = histogram[i];

    printf("%c - [%2d]: ", ASCII_LOWERCASE_A + i, frequency);

    for (int j = 0; j < frequency; j++) {
      printf("=");
    }

    printf("\n");
  }

  return 0;
}