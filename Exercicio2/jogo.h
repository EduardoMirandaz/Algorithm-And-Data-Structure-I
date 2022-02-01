#ifndef JOGO_H
#define JOGO_H

typedef struct game_st GAME;

void insertGameName(GAME *games, int *gamesIterator, char *inputed);
void insertProducerName(GAME *games, int *gamesIterator);
void insertGameYear(GAME *games, int *gamesIterator);
GAME *addGame(GAME *games, int *gamesIterator, char *inputed); //retorno 1 para parar o laço e ir pra pesquisa!
int searchForGameByYear(GAME *games, int i, int yearToSearchFor);
int searchForGameByCompany(GAME *games, int i, char *companyToSearchFor);

#endif 