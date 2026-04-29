#include <stdio.h>
#include <stdlib.h>
#include <lexer.h>

int main(int args, char **argv) {
    FILE *src;
    src = fopen("sample/sample_code.mt", "r");
    printf("File opened.\n");
}