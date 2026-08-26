#ifndef TK
#define TK_UNDEFD
#define TK(id, str)
#endif

TK(AUTO, "auto")
TK(RETURN, "return")
TK(GOTO, "goto")
TK(PAREN_L, "(")
TK(PAREN_R, ")")

TK(BRACE_L, "{")
TK(BRACE_R, "}")

TK(BRACK_L, "[")
TK(BRACK_R, "]")

TK(SEMI, ";")
TK(COLON, ":")

TK(ASTER, "*")
TK(AMPER, "&")

#ifdef TK_UNDEFD
#undef TK_UNDEFD
#undef TK
#endif
