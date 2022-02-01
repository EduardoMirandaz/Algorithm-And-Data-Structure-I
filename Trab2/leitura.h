#ifndef READ_ARCHIVE
#define READ_ARCHIVE
#define arquivo "CSV.csv"

#include"tree.h"
#include"jogo.h"


FILE *readArchive(FILE *textArchive);
void readInput(FILE *textArchive, GAME *game, TREE *tree);
void gameInsertion(char *stringWithAttributes, FILE *textArchive, GAME *game, TREE *tree);
#endif //READ_ARCHIVE