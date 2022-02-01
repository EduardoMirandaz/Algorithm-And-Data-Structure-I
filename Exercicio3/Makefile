BINARY=executavelEx3

all:
	gcc -O3 -march=native -g main.c carta.c pilha.c -o $(BINARY) -lm

run:
	./$(BINARY)
runin:
	./$(BINARY) < in.in
valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)