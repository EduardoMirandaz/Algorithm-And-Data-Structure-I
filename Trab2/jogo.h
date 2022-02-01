#ifndef JOGO_H
#define JOGO_H

typedef struct game_st GAME;

// "get" functions
char *getGameName(GAME *game);
char *getYearNameKey(GAME *game);
char *getGameYear(GAME *game);
char *getGameProducer(GAME *game);
void printGame(GAME *game);
GAME *createEmptyGame();
GAME *addGame(GAME *game, const char *stringWithAttributes);
void printGameName(GAME *game);
void deleteGame(GAME **game);
#endif 