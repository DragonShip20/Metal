#include <stdio.h>
#include <lexer.h>
#include <parser.h>
#include <codegen.h>

int main(int args, char **argv) {
    char *code = read_file("sample/sample_code.mlt");

    init_lexer(code);
    printf("File opened.\n");

    next_token();
    parse_syscall();

    init_codegen("sample/sample_code.asm");
    printf("%s", text_section);
    printf("%s", data_section);    
    
    return 0;
}
