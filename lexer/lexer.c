#include <string.h>
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