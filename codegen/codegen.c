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

void write_file(FILE *file, char *str, int pos) {
    fseek(file, pos, SEEK_SET);
    fprintf(file, str);
}

FILE* init_codegen(const char *filename) {
    FILE *f = fopen(filename, "w+");
    if (!f)
        return NULL;
    char *init = "global _start\nsection .text\n\t_start:";
    write_file(f, init, 0);
    return f;
}
