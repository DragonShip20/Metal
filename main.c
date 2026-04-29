#include <stdio.h>
#include <stdlib.h>
#include <lexer.h>

int main(int args, char **argv) {
    FILE *src;
    src = fopen("sample/sample_code.mt", "r");

    init_lexer((const char*)src);
    skip_whitespace();
    advance();
    printf("File opened.\n");
    printf("%d\n", is_digit('5'));
    printf("%d\n", is_digit('a'));
}