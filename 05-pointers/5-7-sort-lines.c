#include <stdio.h>
#include <string.h>
#include "utils/heap.c"

#define MAX_LINES 8
#define BUF_SIZE 1024

int readlines(char *lines[], int max_lines);

int readline(char *line, int limit);

void qsort(char *lines[], int left, int right);

void swap(char *lines[], int from, int to);

void writelines(char *lines[], int size);

int main() {
  printf("Sort lines using the quicksort algorithm\n");
  printf("========================================\n");
  char *lines[MAX_LINES];

  for (int i = 0; i < MAX_LINES; i++) {
    lines[i] = alloc(BUF_SIZE);
  }

  int lines_read;

  printf("Read %d lines\n", lines_read = readlines(lines, MAX_LINES));

  printf("Input lines\n");
  printf("===========\n");
  writelines(lines, lines_read);

  qsort(lines, 0, lines_read - 1);

  printf("Sorted lines\n");
  printf("============\n");
  writelines(lines, lines_read);

  return 0;
}

//int readlines(char *lines[], int max_lines) {
//  int lines_read = 0;
//  char line[BUF_SIZE];
//
//  for (int i = 0; i < max_lines; i++) {
//    printf("Line %d: ", i + 1);
//
//    int len = readline(line, BUF_SIZE);
//
//    if (len) {
//      char *ptr = alloc(len + 1);
//      strcpy(ptr, line);
//      ptr[len] = '\0';
//
//      lines[lines_read++] = ptr;
//    } else {
//      break;
//    }
//  }
//
//  printf("\n");
//  return lines_read;
//}

int readlines(char *lines[], int max_lines) {
  int lines_read = 0;

  for (int i = 0; i < max_lines; i++) {
    printf("Line %d: ", i + 1);

    if (readline(lines[lines_read], BUF_SIZE)) {
      lines_read++;
    } else {
      break;
    }
  }

  printf("\n");
  return lines_read;
}


int readline(char *line, int limit) {
  int len = 0, c;

  while ((c = getchar()) != EOF && len < limit) {
    if (c == '\n') break;
    *line++ = (char) c;
    len++;
  }

  *line = '\0';
  return len;
}

void writelines(char *lines[], int size) {
  for (int i = 0; i < size; i++) {
    printf("\"%s\"\n", lines[i]);
  }
}

/* qsort: sort lines[left]...lines[right] into increasing order */
void qsort(char *lines[], int left, int right) {
  int i, last;

  if (left >= right) {
    /* do nothing if array contains fewer than two elements */
    return;
  }

  swap(lines, left, (left + right) / 2);
  last = left;

  for (i = left + 1; i <= right; i++) {
    if (strcmp(lines[i], lines[left]) < 0) {
      swap(lines, ++last, i);
    }
  }

  swap(lines, left, last);
  qsort(lines, left, last - 1);
  qsort(lines, last + 1, right);
}

void swap(char *lines[], int from, int to) {
  char *temp = lines[from];
  lines[from] = lines[to];
  lines[to] = temp;
}