#include "pool.h"
#include <stdlib.h>
#include <string.h>

struct c_const_list constants;
struct str_list identifiers;

size_t pool_absorb_constant(struct c_const *constant) {
  size_t i;
  for (i = 0; i < constants.len; ++i) {
    if (constant->type == constants.val[i].type) {
      switch (constant->type) {
      case C_CONST_INT:
        if (constants.val[i].val.i == constant->val.i) {
          return i;
        }
        break;
      case C_CONST_FLT:
        if (constants.val[i].val.f == constant->val.f) {
          return i;
        }
        break;
      case C_CONST_STR:
        if (!strcmp(constants.val[i].val.s, constant->val.s)) {
          return i;
        }
        break;
      }
    }
  }
  constants.val =
      realloc(constants.val, ++constants.len * sizeof *constants.val);
  constants.val[i] = *constant;
  return i;
}

size_t pool_absorb_identifier(char *identifier) {
  size_t i;
  for (i = 0; i < identifiers.len; ++i) {
    if (!strcmp(identifiers.val[i], identifier)) {
      free(identifier);
      return i;
    }
  }
  identifiers.val =
      realloc(identifiers.val, ++identifiers.len * sizeof *identifiers.val);
  identifiers.val[i] = identifier;
  return i;
}
