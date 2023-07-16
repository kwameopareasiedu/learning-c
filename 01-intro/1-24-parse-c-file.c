#include <stdio.h>
#include "utils/stack.c"

#define FALSE 0
#define TRUE 1
#define PATH_BUF_SIZE 512
#define CODE_BUF_SIZE 32768

int get_stream_lines(FILE *stream, char buffer[], int limit, int break_on_newline);

struct StackEntry *parse_code(const char input[], int limit);

int main() {
  printf("Parse C file for syntax errors\n");
  printf("==============================\n");
  printf("Enter path_buffer to C file:\n");

  char path_buffer[PATH_BUF_SIZE];
  get_stream_lines(stdin, path_buffer, PATH_BUF_SIZE, TRUE);

  char code_buffer[CODE_BUF_SIZE];
  FILE *stream = fopen(path_buffer, "r");

  if (stream != NULL) {
    get_stream_lines(stream, code_buffer, CODE_BUF_SIZE, FALSE);
    fclose(stream);

    struct StackEntry *unmatched_token = parse_code(code_buffer, CODE_BUF_SIZE);

    if (unmatched_token != NULL) {
      printf(
          "Unmatched token '%c' on line %d:%d\n",
          unmatched_token->$char,
          unmatched_token->line,
          unmatched_token->pos
      );
    } else {
      printf("No syntax issues found!");
    }
  } else {
    printf("Error: File could not be opened\n");
    return -1;
  }

  return 0;
}

int get_stream_lines(FILE *stream, char buffer[], int limit, int break_on_newline) {
  int len = 0, c;

  while ((c = fgetc(stream)) != EOF) {
    if (c == '\n' && break_on_newline) {
      break;
    }

    if (len < limit - 1) {
      buffer[len] = (char) c;
      len++;
    }
  }

  buffer[len] = '\0';
  return len;
}

struct StackEntry *parse_code(const char input[], int limit) {
  struct Stack s;

  int in_line_comment = FALSE, in_block_comment = FALSE, in_string = FALSE, in_char = FALSE;
  int char_escape_sequences = 0;
  int idx = 0, lines = 1, line_chars = 1;
  char c, prev_c;

  while ((c = input[idx]) != '\0' && idx < limit) {
    // Count lines and line chars
    if (c == '\n') {
      lines++;
      line_chars = 1;
      in_line_comment = FALSE;
    } else {
      line_chars++;
    }

    // Determine line comment
    if (!in_block_comment && !in_line_comment && !in_string && c == '/' && prev_c == '/') {
      in_line_comment = TRUE;
    }

    // Determine start of block comment
    if (!in_block_comment && !in_line_comment && !in_string && c == '*' && prev_c == '/') {
      in_block_comment = TRUE;
    }

    // Determine end of block comment
    if (in_block_comment && c == '/' && prev_c == '*') {
      in_block_comment = FALSE;
    }

    // Determine start and end of string
    if (!in_block_comment && !in_line_comment) {
      if (!in_string && c == '"' && prev_c != '\'') {
        in_string = TRUE;
      } else if (in_string && c == '"' && prev_c != '/') {
        in_string = FALSE;
      }
    }

    // Determine start and end of char
    if (!in_block_comment && !in_line_comment && !in_string) {
      if (!in_char && c == '\'') {
        in_char = TRUE;
      } else if (in_char) {
        if (c == '\\') char_escape_sequences++;

        if (c == '\'' && (char_escape_sequences % 2 == 0 || prev_c != '\\')) {
          char_escape_sequences = 0;
          in_char = FALSE;
        }
      }
    }

//    if (lines > 125 && lines < 130) {
//      printf("'%c'<-'%c' BC:%b, LC:%b, S:%b, C:%b\n", c, prev_c, in_block_comment, in_line_comment, in_string, in_char);
//    }

    // Push and pop tokens accordingly
    if (!in_line_comment && !in_block_comment && !in_string && !in_char) {
      struct StackEntry e = {lines, line_chars, c};

      if (c == '(' || c == '[' || c == '{') {
        stack_push(&s, &e);
      } else if (c == ')' || c == ']' || c == '}') {
        struct StackEntry *popped = stack_pop(&s);

        if (
            popped == NULL ||
            (c == ')' && popped->$char != '(') ||
            (c == ']' && popped->$char != '[') ||
            (c == '}' && popped->$char != '{')
            ) {
          // Error: stack is either empty or
          // popped element does not close
          // current char
          stack_push(&s, &e);
          break;
        }
      }
    }

    prev_c = c;
    idx++;
  }

  return stack_pop(&s);
}