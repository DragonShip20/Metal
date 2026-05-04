#ifndef PARSER_H
#define PARSER_H

#include <lexer.h>

#define MAX_ARGS 8

typedef enum {
    AST_SYSCALL,
    AST_NUMBER,
    AST_STRING
} AST_type;

typedef struct AST {
    AST_type type;
    int value;
    char *str;
    struct AST* argv[MAX_ARGS];
    int args;
} AST;

void expect(TokenType type);
AST* new_number(int v);
AST* new_string(char *str);
AST* new_node(AST_type type);
AST* new_syscall(int args);
AST* parse_number(void);
AST* parse_syscall(void);

#endif
