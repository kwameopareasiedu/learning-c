#include <stdio.h>

#define PATH_CHAR_SIZE 1024
#define BUFFER_CHAR_SIZE 16384
#define FALSE 0
#define TRUE 1

int get_line(char buffer[], int limit);

int get_stream_contents(FILE *stream, char buffer[], int limit, int break_on_new_line);

void remove_comments(const char input[], char output[]);

int main() {
  printf("Remove comments from C code\n");
  printf("===========================\n");
  printf("Enter path to C file:\n");

  char path[PATH_CHAR_SIZE], buffer[BUFFER_CHAR_SIZE], output[BUFFER_CHAR_SIZE];
  FILE *file;

  // Read path from stdin
  get_stream_contents(stdin, path, PATH_CHAR_SIZE, TRUE);

  // Open the file
  file = fopen(path, "r");

  // Read all contents of file
  get_stream_contents(file, buffer, BUFFER_CHAR_SIZE, FALSE);

  remove_comments(buffer, output);

  printf("Output\n%s\n", output);

  fclose(file);

  return 0;
}

int get_stream_contents(FILE *stream, char buffer[], int limit, int break_on_new_line) {
  int len = 0, c;

  while ((c = fgetc(stream)) != EOF) {
    if (break_on_new_line && c == '\n') {
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

void remove_comments(const char input[], char output[]) {
  int string_encountered = FALSE;
  int star_encountered = FALSE;
  int forward_slash_encountered = FALSE;
  int line_comment_started = FALSE;
  int block_comment_started = FALSE;
  int i_idx = 0, o_idx = 0;
  char c = input[i_idx];

  while (c != '\0') {
    c = input[i_idx++];

    if (c == '\n') {
      string_encountered = FALSE;
      line_comment_started = FALSE;
    } else if (c == '*') {
      if (!block_comment_started &&
          !string_encountered &&
          forward_slash_encountered) {
        block_comment_started = TRUE;
        o_idx--;
      }

      star_encountered = TRUE;
    } else if (c == '"') {
      if (!string_encountered) {
        string_encountered = TRUE;
      } else {
        string_encountered = FALSE;
      }
    } else if (c == '/') {
      if (forward_slash_encountered && !string_encountered) {
        line_comment_started = TRUE;
        o_idx--;
      } else if (star_encountered && block_comment_started) {
        block_comment_started = FALSE;
        o_idx--;
        c = ' ';
      }

      forward_slash_encountered = TRUE;
    } else {
      forward_slash_encountered = FALSE;
      star_encountered = FALSE;
    }

    if (!line_comment_started && !block_comment_started) {
      output[o_idx++] = c;
    }
  }

  output[o_idx] = '\0';
}