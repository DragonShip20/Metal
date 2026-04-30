#include <stdlib.h>
#include <stdio.h>
#include <parser.h>

AST current_node;

int expect(AST_type type) {
    return (current_node.type == type);
}