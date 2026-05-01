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

AST* new_number(int value) {
    AST *new = malloc(sizeof(AST));
    new->type = AST_NUMBER;
    new->value = value;
    return new;
}
