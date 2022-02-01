#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"jogo.h"
#include"util.h"
#include"tree.h"

// para ler string -> scanf(" %[^(\r|\n)]*c", string);

struct game_st{
    char *name;
    char *year;
    char *producer;
    char *key;
};

GAME* createEmptyGame(){
  GAME* game = (GAME*) calloc(1, sizeof(GAME));
  return game;
}

// Funções de acesso, quando preciso de algum atributo do jogo.
char *getYearNameKey(GAME *game){
  return game->key;
}
char *getGameYear(GAME *game){
  return game->year;
}
char *getGameName(GAME *game){
  return game->name;
}
char *getGameProd(GAME *game){
  return game->producer;
}
void printGameName(GAME *game){
  printf("%s\n", game->name);
}


// Nessa função, "construo o jogo", colocando na estrutura "GAME" todos os atributos que foram lapidados
void buildGame(GAME *game, const char *gameName, char *gameYear, const char *gameProducer, const char *gameKey){
  game->name = calloc (strlen(gameName), sizeof(char));
  game->year = calloc (strlen(gameYear), sizeof(char));
  game->producer = calloc (strlen(gameProducer), sizeof(char));
  game->key = calloc (strlen(gameKey), sizeof(char));
  strcpy(game->name, gameName);
  strcpy(game->year,gameYear);
  strcpy(game->producer, gameProducer);
  strcpy(game->key, gameKey);
}

//boolean isLeftParameterDateSmaller

// Nessa função, concateno o ANO e o NOME, com o intuito de auxiliar na ID de inserção na árvore
char *buildGameKey(const char *gameYear, const char *gameName, char *gameKey){
    gameKey = calloc(strlen(gameYear) + strlen(gameName) + 1,sizeof (char));
    if(gameKey != NULL){
      strcpy(gameKey, " ");
      strcpy(gameKey, gameYear);
      strcat(gameKey, gameName);
      return gameKey;
    } 
  return NULL;
}
// crio os atributos do jogo, seleciono eles e mando para a "construção"(que seria a função "buildGame")
GAME *addGame(GAME *game, const char *stringWithAttributes){
  char *gameName,*gameYear, *gameProd, *gameKey;
  gameName = copyString(stringWithAttributes); gameName = throwComma(gameName, NAME_COLUMN_CSV);
  gameYear = copyString(stringWithAttributes); gameYear = throwComma(gameYear, YEAR_COLUMN_CSV); 
  gameProd = copyString(stringWithAttributes); gameProd = throwComma(gameProd, PRODUCER_COLUMN_CSV); 
  gameKey = copyString(stringWithAttributes);  gameKey = buildGameKey(gameYear, gameName, gameKey);
  buildGame(game,gameName,gameYear, gameProd, gameKey);
  return game;
}

void deleteGame(GAME **game){
  if (*game != NULL)
  {
    (*game)->name = NULL;
    (*game)->year = NULL;
    (*game)->producer = NULL;
    (*game)->key = NULL;
    free((*game)->name);
    free((*game)->year);
    free((*game)->producer);
    free((*game)->key);
  /*apaga o game simbolicamente*/
    free (*game);
    *game = NULL;
  }
}

void printGame(GAME *game){
  printf("%s\n", game->name);
  printf("%s\n", game->year);
  printf("%s\n", game->producer);
  printf("%s\n", game->key);
  printf("====================\n");
}