#include <stdio.h>
#include <lexer.h>
#include <parser.h>

int main(int args, char **argv) {
    char *code = read_file("sample/sample_code.mlt");

    init_lexer(code);
    printf("File opened.\n");

    next_token();

    parse_syscall();

    return 0;
}
