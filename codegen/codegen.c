#include <codegen.h>
#include <string.h>

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

void write_file(FILE *file, char *str, int pos) {
    fseek(file, pos, SEEK_SET);
    fprintf(file, str);
}

FILE* init_codegen(const char *filename) {
    FILE *f = fopen(filename, "w+");
    if (!f)
        return NULL;
    char *text_init = "global _start\nsection .text\n\t_start:\n";
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
