#ifndef __PARSER__H__
#define __PARSER__H__

enum c_type_type {
    C_TYPE_NONE,
    C_TYPE_ERR,
    C_TYPE_VOID,
    C_TYPE_INT,
    C_TYPE_CHAR,
    C_TYPE_FLT,
    C_TYPE_PTR,
    C_TYPE_ARRAY,
    C_TYPE_STRUC_OR_UNION,

};

struct c_type {};

enum c_storage {
    C_STORAGE_NONE,
    C_STORAGE_STATIC,
    C_STORAGE_AUTO,
    C_STORAGE_REGISTER,
    C_STORAGE_TYPEDEF,
    C_STORAGE_EXTERN,
};

struct c_var {};

struct ast_expr {};

enum ast_stmt_type {
    AST_STMT_EMPTY,
    AST_STMT_EXPR,
    AST_STMT_ORDER,
    AST_STMT_DECL,
};

struct ast_stmt {

};


void parse_tree(void);

#endif