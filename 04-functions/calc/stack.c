#ifndef _STDIO_H

#include <stdio.h>

#endif

#define STACK_SIZE 64

static double stack[STACK_SIZE];
static int top = 0;

void push_stack(double entry) {
  if (top < STACK_SIZE) {
    stack[top++] = entry;
  } else {
    printf("Cannot push '%.2f' onto a full stack\n", entry);
  }
}

double pop_stack() {
  if (top > 0) {
    return stack[--top];
  } else {
    printf("Cannot pop an empty stack\n");
    return 0;
  }
}

void print_stack() {
  for (int i = 0; i < top; i++) {
    printf("%.0f,", stack[i]);
  }

  printf("\n");
}

void clear_stack() { top = 0; }