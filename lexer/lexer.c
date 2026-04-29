#include <string.h>
#include "lexer.h"

static const char *src;
static int pos;
static char current;

void init_lexer(const char *source) {
    src = source;
    pos = 0;
    current = src[pos];
}
