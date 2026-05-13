CC = gcc
CFLAGS = -Wall -Ilexer -Iparser -Icodegen

DEBUGFLAGS = -Wall -Ilexer -Iparser -Icodegen -g -O0

SRC = main.c \
      $(wildcard lexer/*.c) \
      $(wildcard parser/*.c) \
      $(wildcard codegen/*.c)

FILE ?= sample/sample_code.mlt
OUT = compiler
ASM = $(wildcard sample/*.asm)

all = $(OUT)

$(OUT): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	@echo Compiled with success.

debug: $(SRC)
	@$(CC) $(DEBUGFLAGS) $(SRC) -o $(OUT)
	@echo Compiled for debugging with success.

run: $(OUT)
	@echo Starting...
	@./$(OUT) $(FILE)

clean:
	@rm -f $(OUT)
	@rm -f $(ASM)
	@echo Removed all output files.
