#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOK_SYSCALL,
    TOK_LBRACKET,
    TOK_RBRACKET,
    TOK_NUMBER,
    TOK_SEMICOLON,
    TOK_COMMA,
    TOK_EOF
} TokenType;

typedef struct {
    TokenType type;
    int value;
} Token;

int main();
void init_lexer(const char *source);
void advance(void);
void skip_whitespace(void);
int is_digit(char c);
int is_letter(char c);
int read_number(void);
char* read_word(char *out);
Token next_token(void);
char* read_file(const char* filename);

#endif