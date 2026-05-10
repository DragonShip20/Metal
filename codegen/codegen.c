#include <codegen.h>
#include <stdlib.h>
#include <stdio.h>

void write_file(FILE *file, char *str, int pos) {
    fseek(file, pos, SEEK_SET);
    fprintf(file, str);
}

FILE* init_codegen(const char *filename) {
    FILE *f = fopen(filename, "w+");
    if (!f)
        return NULL;
    return f;
}
