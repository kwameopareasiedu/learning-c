#include <stdio.h>

#define MAX_WORD_CHAR_COUNT 100

int main() {
  printf("Print a histogram of word length in the sentence\n");
  printf("================================================\n");
  printf("Enter some text:\n");

  int histogram[MAX_WORD_CHAR_COUNT];
  int char_count = 0;
  int c;

  // Initialize histogram array
  for (int i = 0; i < MAX_WORD_CHAR_COUNT; i++) {
    histogram[i] = 0;
  }

  // Get text and compute word lengths for histogram
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      histogram[char_count]++;
      char_count = 0;
    } else {
      char_count++;
    }
  }

  // Print histogram
  for (int i = 0; i < MAX_WORD_CHAR_COUNT; i++) {
    int frequency = histogram[i];

    if (frequency > 0) {
      printf("%2d letter words - [%2d]: ", i, frequency);

      for (int j = 0; j < frequency; j++) {
        printf("=");
      }

      printf("\n");
    }
  }

  return 0;
}