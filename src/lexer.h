#ifndef __LEXER__H__
#define __LEXER__H__

#include <stdio.h>

enum token_type {
#define TK(id, str) TK_##id,
#include "token.h"
  TK_IDENT,
  TK_CONST,
  TK_EOF,
#undef TK
};

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
