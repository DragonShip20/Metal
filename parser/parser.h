typedef enum {
    AST_SYSCALL;
    AST_NUMBER;
} AST_type;

typedef struct {
    AST_type type;
    int value;
    AST* left;
    AST* right;
} AST;