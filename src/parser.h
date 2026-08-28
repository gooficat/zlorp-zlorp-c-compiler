#ifndef __PARSER__H__
#define __PARSER__H__

#include "main.h"
#include "pool.h"
#include <stddef.h>

enum ast_expr_type {
	AST_EXPR_VREF,
	AST_EXPR_UNARY,
	AST_EXPR_BINARY,
	AST_EXPR_CALL,
	AST_EXPR_CONSTANT,
};

enum c_op {
	OP_ADDR,
	OP_DEREF,
};

struct ast_expr_list {
	struct ast_expr *val;
	size_t len;
};

struct ast_op {
	enum c_op op;
	struct ast_expr *expr;
};

struct ast_expr {
	enum ast_expr_type type;
};

enum ast_stmt_type {
	AST_STMT_EMPTY,
	AST_STMT_EXPR,
	AST_STMT_ORDER,
	AST_STMT_DECL,
};

struct ast_decl {
	struct c_var *var;
	struct ast_node *val;
};

struct ast_stmt_list {
	struct ast_stmt *val;
	size_t len;
};

struct ast_scope {
	struct ast_stmt_list body;
	struct str_list labels;
	struct c_var_list vars;
};

enum ast_order_type {
	AST_ORDER_RETURN,
	AST_ORDER_GOTO,
};

union ast_order_value {
	struct ast_expr *ret;
	char *lab;
};

struct ast_order {
	enum ast_order_type type;
	union ast_order_value val;
};
union ast_stmt_val {
	struct ast_expr expr;
	struct ast_scope scope;
};

struct ast_stmt {
	enum ast_stmt_type type;
	union ast_stmt_val value;
};

struct ast_decl_list {
	struct ast_decl *val;
	size_t len;
};

struct ast {
	struct ast_decl_list decls;
};

void parse_tree(void);
void print_tree(void);

#endif
