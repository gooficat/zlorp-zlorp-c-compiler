#ifndef __POOL__H__
#define __POOL__H__

#include <stddef.h>
#include <stdint.h>

enum c_const_type {
  C_CONST_INT,
  C_CONST_FLT,
  C_CONST_STR,
};

union c_const_val {
  intmax_t i;
  long double f;
  char *s;
};

struct c_const {
  enum c_const_type type;
  union c_const_val val;
};

struct c_const_list {
  struct c_const *val;
  size_t len;
};

struct str_list {
  char **val;
  size_t len;
};

extern struct c_const_list constants;
extern struct str_list identifiers;

size_t pool_absorb_constant(struct c_const *constant);
size_t pool_absorb_identifier(char *identifier);

#endif //!__POOL__H__
