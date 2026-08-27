#include <ctype.h>
#define LEXER_IMPL
#include "lexer.h"
#include <stdio.h>

struct lexer {
  struct token token;
  size_t line_num, col_num;
  FILE *file;
  char line[4096];
};

struct lexer lexer;

static void lexer_next_line(void);

void lexer_open(FILE *in_file) {
  lexer.file = in_file;
  lexer.line_num = 0;
  lexer_next_line();
}

static void lexer_next_line(void) {
  if (!fgets(lexer.line, 4096, lexer.file)) {
    lexer.line[0] = 0;
  } else {
    lexer.col_num = 0;
    ++lexer.line_num;
  }
}

void lexer_next(void) {
repeat:
  if (isspace(lexer.line[lexer.col_num])) {
    ++lexer.col_num;
    goto repeat;
  }
  if (lexer.line[lexer.col_num] == '"') {
    ++lexer.col_num;
    size_t i = 0;
    do {
      ++i;
    } while (lexer.line[lexer.col_num + i] != '"' ||
             lexer.line[lexer.col_num + i - 1] == '\\');
    // todo: clean up, helper funcs, etc etc etc
    lexer.col_num += i;
  }
  if (isdigit(lexer.line[lexer.col_num])) {
  }
}

void lexer_close(void) {}
