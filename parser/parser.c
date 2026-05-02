#include <stdlib.h>
#include <stdio.h>
#include <parser.h>

void expect(TokenType type) {
    if (current_token.type != type) {
        printf("Expected token: %d Recieved token: %d", type, current_token.type);
        exit(1);
    }
    current_token = next_token();
}

AST* new_number(int v) {
    AST *new = malloc(sizeof(AST));
    new->type = AST_NUMBER;
    new->value = v;
    new->args = 0;
    return new;
}

AST* new_string(char *str) {
    AST *new = malloc(sizeof(AST));
    new->type = AST_STRING;
    new->str = str;
    new->args = 0;
    return new;
}

AST* new_node(AST_type type) {
    AST *new = malloc(sizeof(AST));
    new->type = type;
    new->args = 0;
    return new;
}
