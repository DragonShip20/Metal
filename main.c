#include <stdio.h>
#include <string.h>
#include <lexer.h>
#include <parser.h>
#include <codegen.h>

int main(int args, char **argv) {
    if (args != 2) {
        printf("Wrong argument count\nUsage: ./compiler [file]\n");
        return -1;
    }

    char src_filepath[256];
    char out_filepath[256];
    strcpy(src_filepath, argv[1]);
    strcpy(out_filepath, argv[1]);
    char *dot = strrchr(out_filepath, '.');
    (dot) ? strcpy(dot, ".asm") : strcat(out_filepath, ".asm");

    char *code = read_file(src_filepath);

    init_lexer(code);
    printf("File opened.\n");

    next_token();
    
    AST *syscall = parse_syscall();

    FILE *output = init_codegen(out_filepath);
    
    gen_syscall(syscall);

    while (current_token.type == TOK_SYSCALL) {
        syscall = parse_syscall();
        gen_syscall(syscall);
    }
    
    finish_generation(output);
   
    return 0;
}
