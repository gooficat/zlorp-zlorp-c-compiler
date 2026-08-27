#ifndef __MAIN__H__
#define __MAIN__H__

#include <stddef.h>
#include <stdint.h>

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

struct c_type {
  enum c_type_type type;
  struct c_type *next;
  unsigned long size;
};

enum c_storage {
  C_STORAGE_NONE,
  C_STORAGE_STATIC,
  C_STORAGE_AUTO,
  C_STORAGE_REGISTER,
  C_STORAGE_TYPEDEF,
  C_STORAGE_EXTERN,
};

struct c_var {
  struct c_type type;
  enum c_storage storage;
};

struct c_var_list {
  struct c_var *val;
  size_t len;
};

#endif
