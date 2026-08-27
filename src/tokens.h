#ifndef __TOKENS__H__
#define __TOKENS__H__

enum token_type {
#define TK(id, str) TK_##id,
#include "token.h"
  TK_IDENT,
  TK_CONST,
  TK_EOF,
#undef TK
};

extern char const *const TOKENS[];

#endif //!__TOKENS__H__
