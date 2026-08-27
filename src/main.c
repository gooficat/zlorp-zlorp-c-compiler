#include "lexer.h"
#include "pool.h"
#include "tokens.h"

int main(void) {
	lexer_open(fopen("./test/1.c", "r"));

	while (lexer.token.type != TK_EOF) {
		if (lexer.token.type < TK_IDENT) {
			printf("tok `%s`\n", TOKENS[lexer.token.type]);
		} else if (lexer.token.type == TK_IDENT) {
			printf("ident `%s`\n", identifiers.val[lexer.token.val]);
		} else {
			printf("tok `%i`\n", lexer.token.type);
		}
		lexer_next();
	}
	lexer_close();
}
