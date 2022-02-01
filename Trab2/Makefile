BINARY=exe
INPUT = "./testes/8.in"

all:
	gcc -O3 -march=native -Wall -Werror -g main.c tree.c jogo.c leitura.c operations.c util.c -o $(BINARY) -lm

run:
	./$(BINARY)

input:
	./$(BINARY) < $(INPUT) > out.txt && ./$(BINARY) < $(INPUT)

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)