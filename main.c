#include <stdio.h>
#include <lexer.h>
#include <parser.h>
#include <codegen.h>

int main(int args, char **argv) {
    char *code = read_file("sample/sample_code.mlt");

    init_lexer(code);
    printf("File opened.\n");

    next_token();
    
    AST *syscall = parse_syscall();

    FILE *output = init_codegen("sample/sample_code.asm");
    
    gen_syscall(syscall);

    while (current_token.type == TOK_SYSCALL) {
        syscall = parse_syscall();
        gen_syscall(syscall);
    }
    
    finish_generation(output);
   
    return 0;
}
