MAIN=exercicio1.c
BINARY=executavelEx1

all:
	gcc -O3 -march=native -Wall -Werror -g main.c exercicio1.c -o $(BINARY) -lm

run:
	./$(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)
