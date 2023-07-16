#ifndef _STDIO_H

#include <stdio.h>

#endif

#include "stack.c"
#include <ctype.h>
#include <string.h>
#include <math.h>

#define TOKEN_SIZE 64

#define OPERATOR 32
#define INT_OPERAND 33
#define FLOAT_OPERAND 34

#define FALSE 0
#define TRUE 1

/** Gets the Polish notation input from the user */
int get_stdin_operation(char buffer[], int limit) {
  int c, len = 0;

  while ((c = getchar()) != EOF && c != '\n' && len < limit - 1) {
    buffer[len++] = (char) c;
  }

  buffer[len] = '\0';

  return len;
}

/** Returns the next token from the operation together with its type (integer, decimal or operator) */
static void get_next_token(const char operation[], int *start, char token[], int *type) {
  int i = *start, token_len = 0, i_copy = *start;
  char c;

  while ((c = operation[i++]) != '\0') {
    i_copy++;

    if (c == ' ' || c == '\n') {
      continue;
    } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == 's' || c == 'c' || c == 'p') {
      token[token_len++] = c;
      token[token_len] = '\0';
      *type = OPERATOR;
      break;
    } else if (isdigit(c) || c == '.') {
      char c_num = c;
      int is_decimal = FALSE;

      while (isdigit(c_num) || c_num == '.') {
        if (!is_decimal && c_num == '.') {
          is_decimal = TRUE;
        }

        token[token_len++] = c_num;
        c_num = operation[i++];
        i_copy++;
      }

      token[token_len] = '\0';
      *type = is_decimal ? FLOAT_OPERAND : INT_OPERAND;
      break;
    }
  }

  // Record the start for next run
  *start = (i <= i_copy) ? i : -1;
}

/** Checks if two strings are equal */
static int str_equal(const char s1[], const char s2[]) {
  return strcmp(s1, s2) == 0;
}

static double str_to_double(const char str[]) {
  int i = 0, int_res = 0, is_decimal = FALSE;
  double frac_result = 0, frac_mul = 10;
  char c;

  while ((c = str[i++]) != '\0') {
    if (c == '.') {
      if (!is_decimal) {
        is_decimal = TRUE;
      }
    } else {
      int num = c - '0';

      if (!is_decimal) {
        int_res = int_res * 10 + num;
      } else {
        frac_result += ((double) num / frac_mul);
        frac_mul *= 10;
      }
    }
  }

  return int_res + frac_result;
}

double calculate(const char operation[]) {
  char token[TOKEN_SIZE];
  int start = 0, type = 0;

  clear_stack();

  while (start != -1) {
    get_next_token(operation, &start, token, &type);

    if (start == -1) {
      break;
    }

    if (type == INT_OPERAND || type == FLOAT_OPERAND) {
      push_stack(str_to_double(token));
    } else if (type == OPERATOR) {
      if (str_equal(token, "+")) {
        push_stack(pop_stack() + pop_stack());
      } else if (str_equal(token, "-")) {
        double second = pop_stack();
        push_stack(pop_stack() - second);
      } else if (str_equal(token, "*")) {
        push_stack(pop_stack() * pop_stack());
      } else if (str_equal(token, "/")) {
        double second = pop_stack();

        if (second == 0.0) {
          printf("Cannot divide by 0\n");
          break;
        }

        push_stack(pop_stack() / second);
      } else if (str_equal(token, "%")) {
        int second = (int) pop_stack();
        int first = (int) pop_stack();

        if (second == 0) {
          printf("Cannot mod by 0\n");
          break;
        }

        push_stack(first % second);
      } else if (str_equal(token, "s")) {
        push_stack(sin(pop_stack()));
      } else if (str_equal(token, "c")) {
        push_stack(cos(pop_stack()));
      } else if (str_equal(token, "p")) {
        push_stack(pow(pop_stack(), pop_stack()));
      }
    }
  }

  return pop_stack();
}