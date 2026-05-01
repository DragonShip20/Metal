#include <stdlib.h>
#include <stdio.h>
#include <parser.h>
#include <lexer.h>

Token current_token;

void expect(AST_type type) {
    if (current_token.type != type) {
        printf("Expected token: %d Recieved token: %d", type, current_token.type);
        exit(1);
    }
    current_token = next_token();
}