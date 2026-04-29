CC = gcc
CFLAGS = -Wall -Ilexer -Iparser -Icodegen

SRC = main.c \
      $(wildcard lexer/*.c) \
      $(wildcard parser/*.c) \
      $(wildcard codegen/*.c)	  

OUT = compiler

all = $(OUT)

$(OUT): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	@echo Compiled with success.

run: $(OUT)
	@echo Starting...
	@./$(OUT)

clean:
	@rm -f $(OUT)
	@echo Removed all output files.
