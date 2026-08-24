#ifndef __PARSER__H__
#define __PARSER__H__

#include <stddef.h>
#include "main.h"


enum ast_expr_type {
    AST_EXPR_VREF,
    AST_EXPR_UNARY,
    AST_EXPR_BINARY,
    AST_EXPR_CALL,
    AST_EXPR_CONSTANT,
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

union ast_stmt_val {
    struct ast_expr expr;
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

#endif