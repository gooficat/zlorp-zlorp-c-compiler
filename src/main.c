#include "lexer.h"
#include "parser.h"
#include "pool.h"
#include "tokens.h"

int main(void) {
	lexer_open(fopen("./test/1.c", "r"));
	parse_tree();
	print_tree();
	lexer_close();
}
