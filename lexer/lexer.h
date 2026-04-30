typedef enum {
    TOK_SYSCALL,
    TOK_LBRACKET,
    TOK_RBRACKET,
    TOK_NUMBER,
    TOK_SEMICOLON,
    TOK_COMMA
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
int read_number(char *str);
int read_word(const char *str, char *out);