#ifndef __LEXER__H__
#define __LEXER__H__

struct token {
    
};

extern struct token token;

void lexer_open(FILE *file);
void lexer_next(void);
void lexer_close(void);

#endif