#include "chibi.h"

// Type CHAR_TYPE = {TY_CHAR, 1, 1, NULL, -1};
// Type SHORT_TYPE = {TY_SHORT, 2, 2, NULL, -1};
// Type INT_TYPE = {TY_INT, 4, 4, NULL, -1};
Type CHAR_TYPE = {TY_CHAR, 8, 8, NULL, -1};
Type SHORT_TYPE = {TY_SHORT, 8, 8, NULL, -1};
Type INT_TYPE = {TY_INT, 8, 8, NULL, -1};
Type LONG_TYPE = {TY_LONG, 8, 8, NULL, -1};

int align_to(int n, int align) {
  return (n + align - 1) & ~(align - 1);
}

bool is_integer(Type *ty) {
  TypeKind k = ty->kind;
  return k == TY_CHAR || k == TY_SHORT || k == TY_INT  || k == TY_LONG;
}

bool is_ptr(Type* ty) {
    return ty->base;
}

Type* new_type(TypeKind kind, int size, int align) {
  Type *ty = new Type();
  ty->kind = kind;
  ty->size = size;
  ty->align = align;
  return ty;
}

Type* pointer_to(Type *base) {
    Type *ty = new_type(TY_PTR, 8, 8);
    ty->base = base;
    return ty;
}

Type* array_of(Type *base, int len) {
    Type *ty = new_type(TY_ARRAY, base->size * len, base->align);
    ty->base = base;
    ty->array_len = len;
    return ty;
}