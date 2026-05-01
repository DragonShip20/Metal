#ifndef PARSER_H
#define PARSER_H

#include <lexer.h>

typedef enum {
    AST_SYSCALL,
    AST_NUMBER,
} AST_type;

typedef struct {
    AST_type type;
    int value;
    struct AST* left;
    struct AST* right;
} AST;

void expect(TokenType type);

#endif