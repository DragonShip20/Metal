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
    int argv[6];
} AST;

void expect(TokenType type);
AST* new_number(int value);

#endif
