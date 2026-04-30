#include <stdio.h>
#include <stdlib.h>
#include <lexer.h>

int main(int args, char **argv) {
    char *code = read_file("sample/sample_code.mlt");

    init_lexer(code);
    printf("File opened.\n");

    Token tok = next_token();

    while (tok.type != TOK_EOF) {
        tok = next_token();
    }

    return 0;
}