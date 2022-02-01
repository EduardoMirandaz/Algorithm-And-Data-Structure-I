BINARY=executavelEx4
INPUT = in.txt

all:
	gcc -O3 -march=native -Wall -Werror -g main.c bignumber.c linkedList.c -o $(BINARY) -lm

run:
	./$(BINARY)

input:
	./$(BINARY) < $(INPUT) > out.txt

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)
