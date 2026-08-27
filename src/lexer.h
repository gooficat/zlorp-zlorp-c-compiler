#ifndef __LEXER__H__
#define __LEXER__H__

#include "tokens.h"
#include <stdio.h>

struct token {
  enum token_type type;
  size_t val;
};

#ifndef LEXER_IMPL
struct lexer {
  struct token token;
  size_t line, col;
};
#endif
extern struct lexer lexer;

void lexer_open(FILE *);
void lexer_next(void);
void lexer_close(void);

#endif
