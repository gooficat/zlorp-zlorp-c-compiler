#include "pool.h"
#include "tokens.h"
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define LEXER_IMPL
#include "lexer.h"
#include <stdio.h>

_Bool is_word_char(int c) {
	return c == '_' || isalnum(c);
}
struct lexer {
	struct token token;
	int_fast16_t line_num, col_num;
	FILE *file;
	char line[4096];
};

struct lexer lexer;

static void lexer_next_line(void);

void lexer_open(FILE *in_file) {
	lexer.file = in_file;
	lexer.line_num = 0;
	lexer_next_line();
	lexer_next();
}

static void lexer_next_line(void) {
	if (!fgets(lexer.line, 4096, lexer.file)) {
		lexer.line[0] = '\0';
	} else {
		lexer.col_num = 0;
		++lexer.line_num;
	}
}

void lexer_next(void) {
repeat:
	if (lexer.line[0] == '\0') {
		lexer.token.type = TK_EOF;
		return;
	}
	if (lexer.line[lexer.col_num] == '\n') {
		lexer_next_line();
		goto repeat;
	}
	if (isspace(lexer.line[lexer.col_num])) {
		++lexer.col_num;
		goto repeat;
	}
	if (lexer.line[lexer.col_num] == '"') {
		struct c_const constant;
		lexer.token.type = TK_CONST;
		constant.type = C_CONST_STR;
		++lexer.col_num;
		size_t i = 0;
		do {
			++i;
		} while (lexer.line[lexer.col_num + i] != '"' || lexer.line[lexer.col_num + i - 1] == '\\');

		constant.val.s = malloc(i);
		memcpy(constant.val.s, lexer.line + lexer.col_num, i - 1);
		constant.val.s[i - 1] = '\0';
		lexer.col_num += i;
	} else if (isdigit(lexer.line[lexer.col_num])) {
		struct c_const constant;
		int_fast16_t seek = lexer.col_num;
		lexer.token.type = TK_CONST;

		while (isalnum(++seek))
			;
		if (lexer.line[seek] == '.') {
			constant.type = C_CONST_FLT;
			constant.val.f = strtold(lexer.line + lexer.col_num, NULL);
			while (isalnum(++seek))
				;
		} else {
			constant.type = C_CONST_INT;
			constant.val.i = strtoll(lexer.line + lexer.col_num, NULL, 0);
		}
		lexer.col_num = seek;
		lexer.token.val = pool_absorb_constant(&constant);
	} else {
		for (lexer.token.type = 0; TOKENS[lexer.token.type]; ++lexer.token.type) {
			size_t len = strlen(TOKENS[lexer.token.type]);
			if (!memcmp(lexer.line + lexer.col_num, TOKENS[lexer.token.type], len) &&
				(!is_word_char(TOKENS[lexer.token.type][0]) || !is_word_char(lexer.line[len]))) {
				lexer.col_num += len;
				return;
			}
		}
		// lexer.token.type = TK_IDENT; not needed because of the above for loop
		// ending at there anyway
		{
			char *identifier;
			size_t len = 0;

			while (is_word_char(lexer.line[++len + lexer.col_num]))
				;
			identifier = malloc(len + 1);
			memcpy(identifier, lexer.line + lexer.col_num, len);
			identifier[len] = '\0';
			lexer.token.val = pool_absorb_identifier(identifier);
			lexer.col_num += len;
		}
	}
}

void lexer_close(void) {
	fclose(lexer.file);
}
