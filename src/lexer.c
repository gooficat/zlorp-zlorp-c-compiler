#define LEXER_IMPL
#include "lexer.h"
#include <stdio.h>

struct lexer {
  struct token token;
  size_t line, col;
  FILE *file;
};

struct lexer lexer;

void lexer_open(FILE *in_file) { lexer.file = in_file; }

void lexer_next(void) {}

void lexer_close(void) {}
