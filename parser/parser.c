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

AST* new_syscall(int args) {
    AST *new = malloc(sizeof(AST));
    new->type = AST_SYSCALL;
    new->args = args;
    return new;
}

AST* parse_number(void) {
    AST *n = new_number(current_token.value);
    expect(TOK_NUMBER);
    return n;    
}

AST* parse_syscall(void) {
    expect(TOK_SYSCALL);
    expect(TOK_LBRACKET);

    AST *node = new_syscall(0);
    int arg_counter = 0;
    while (current_token.type != TOK_RBRACKET) {
        node->argv[arg_counter] = parse_number();
        if (current_token.type == TOK_RBRACKET) {
            arg_counter++;
            break;
        }
        expect(TOK_COMMA);
    }
    node->args = arg_counter + 1;
    expect(TOK_RBRACKET);
    expect(TOK_SEMICOLON);
    return node;
}
