#include <codegen.h>

static const char *syscall_args[7] = {
    "rax",
    "rdi",
    "rsi",
    "rdx",
    "r10",
    "r9",
    "r8"
};

char data_section[4096] = "";
char text_section[8192] = "";
char output[16384] = "";

void write_file(FILE *file, char *str, int pos) {
    fseek(file, pos, SEEK_SET);
    fprintf(file, str);
}

void finish_generation(FILE *file) {
    strcat(output, data_section);
    strcat(output, "\n");
    strcat(output, text_section);
    write_file(file, output, 0);
    fclose(file);
}

FILE* init_codegen(const char *filename) {
    FILE *f = fopen(filename, "w+");
    if (!f)
        return NULL;
    char *text_init = "global _start\nsection .text\n_start:\n";
    char *data_init = "section .data\n";
    emit_data(data_init);
    emit_text(text_init);
    return f;
}

void emit_data(char *str) {
    strcat(data_section, str);
}

void emit_text(char *str) {
    strcat(text_section, str);
}

void gen_reg(const char* reg, AST *number) {
    char buffer[128];
    sprintf(buffer, "\tmov %s, %d\n", reg, number->value);
    emit_text(buffer);
}

void gen_syscall(AST *syscall) {
    for (int i=0; i<syscall->args; i++) {
        gen_reg(syscall_args[i], syscall->argv[i]);
    }
    emit_text("\tsyscall\n");
}

void dump_ast(AST *node) {
    printf("\n\nNode: %p", node);
    printf("\nType: %d", node->type);
    printf("\nValue: %d", node->value);
    printf("\nArg count: %d", node->args);
    for (int i=0; i<node->args; i++) {
        printf("\nArg %d Type: %d", i, node->argv[i]->type);
        printf("\nArg %d Value: %d", i, node->argv[i]->value);
    }
}
