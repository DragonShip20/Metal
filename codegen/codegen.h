#ifndef CODEGEN_H
#define CODEGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <parser.h>
#include <string.h>
extern char data_section[4096];
extern char text_section[8192];

void write_file(FILE *file, char *str, int pos);
FILE* init_codegen(const char *filename);
void emit_data(char *str);
void emit_text(char *str);
void gen_reg(const char *reg, AST *number);
void gen_syscall(AST *syscall);
void dump_ast(AST *node);
void finish_generation(FILE *file);

#endif
