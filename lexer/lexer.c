#include <string.h>
#include <stdlib.h>
#include <lexer.h>

static const char *src;
static int pos;
static char current;

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

int read_number(char *str) {
    int num = 0;
    while (is_digit(*str)) {
        num *= 10;
        num += *str - '0';
        str++;
    }
    return num;
}

int read_word(const char *str, char *out) {
    int pos = 0;

    if (!is_letter(str[pos]))
        return 0;

    while (is_letter(*(str+pos))) {
        out[pos] = str[pos];
        pos++;
    }

    out[pos] ='\0';
    return pos;
}