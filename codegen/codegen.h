#ifndef CODEGEN_H
#define CODEGEN_H

#include <stdio.h>
#include <stdlib.h>

void write_file(FILE *file, char *str, int pos);
FILE* init_codegen(const char *filename);

#endif
