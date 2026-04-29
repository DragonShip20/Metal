typedef enum {
    TOK_PRINT,
    TOK_NUMBER,
    TOK_SEMICOLON
} TokenType;

typedef struct {
    TokenType type;
    int value;
} Token;