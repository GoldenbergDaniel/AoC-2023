NAME = aoc
CC = cc

CFLAGS_R = -std=gnu17 \
					 -O0 \
					 -Iext/ \
					 -Wall \
					 -Wpedantic \
					 -Wno-missing-braces \
					 -Wno-unused-function \
					 -Wno-language-extension-token \

.PHONY: all compile compile_t run

all: compile run

compile:
	@echo "Compiling project..."
	@./ParseShaders
	@$(CC) $(CFLAGS_R) src/_target.c -o $(NAME)
	@echo "Compilation complete!"

compile_t:
	@echo "Timing compilation..."
	@time $(CC) $(CFLAGS_R) src/_target.c -o $(NAME)

run:
	./$(NAME)
