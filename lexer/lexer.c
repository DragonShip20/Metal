#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <lexer.h>

static const char *src;
static int pos;
static char current;
Token current_token;

void init_lexer(const char *source) {
    src = source;
    pos = 0;
    current = src[pos];
}

void advance(void) {
    pos++;
    current = src[pos];
}

void skip_whitespace(void) {
    while (current == ' ' || current == '\n' || current == '\t')
        advance();
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_letter(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <='z'));
}

int read_number(void) {
    int num = 0;
    while (is_digit(current)) {
        num *= 10;
        num += current - '0';
        advance();
    }
    return num;
}

char* read_word(char *out) {
    if (!is_letter(current))
        return 0;

    int i=0;

    while (is_letter(current)) {
        out[i++] = current;
        advance();
    }

    out[i] ='\0';
    return out;
}

Token next_token(void) {
    skip_whitespace();

    if (is_digit(current)) {
        current_token.type = TOK_NUMBER;
        current_token.value = read_number();
        printf("NUMBER %d ", current_token.value);
        return current_token;
    }

    if (is_letter(current)) {
        char buffer[128];
        read_word(buffer);

        if (strcmp(buffer, "syscall") == 0)
            current_token.type = TOK_SYSCALL;

        printf("STRING %s ", buffer);

        return current_token;
    }

    switch (current) {
    case '[':
        current_token.type = TOK_LBRACKET;
        printf("LBRACKET ");
        advance();
        return current_token;
    case ']':
        current_token.type = TOK_RBRACKET;
        printf("RBRACKET ");
        advance();
        return current_token;
    case ';':
        current_token.type = TOK_SEMICOLON;
        printf("SEMICOLON ");
        advance();
        return current_token;
    case '\0':
        current_token.type = TOK_EOF;
        printf("EOF ");
        advance();
        return current_token;
    case ',':
        current_token.type = TOK_COMMA;
        printf("COMMA ");
        advance();
        return current_token;
    default:
        printf("UNKNOWN CHAR AT POS %d: %c\n", pos, current);
        exit(1);
    }
}

char* read_file(const char* filename) {
    FILE* f = fopen(filename, "r");

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    char* buffer = malloc(size + 1);
    fread(buffer, 1, size, f);
    buffer[size] = '\0';

    fclose(f);
    return buffer;
}