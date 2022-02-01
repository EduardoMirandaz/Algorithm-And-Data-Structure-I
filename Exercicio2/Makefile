BINARY=executavelEx2
all:
	gcc -O3 -march=native -Wall -Werror -g jogo.c catalogo.c main.c -o $(BINARY) -lm
run:
	./$(BINARY)
valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)
gustavo:
	clear && gcc -O3 -march=native -Wall -Werror -g jogo.c catalogo.c main.c -o $(BINARY) -lm && ./$(BINARY) < in.in
