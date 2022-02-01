#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"jogo.h"

// para ler string -> scanf(" %[^(\r|\n)]*c", string);

struct game_st{
    char name[100];
    char producer[100];
    int year;
};

int searchForGameByYear(GAME *games, int i, int yearToSearchFor){
    if(games[i].year == yearToSearchFor){
        printf("%s\n", games[i].name);
        return 1;
    }
    return 0;
}

int searchForGameByCompany(GAME *games, int i, char *companyToSearchFor){

    if(strcmp(games[i].producer, companyToSearchFor) == 0){
        printf("%s\n", games[i].name);
        return 1;
    }
    return 0;
}


// Funções para popular os jogos:
void insertGameName(GAME *games, int *gamesIterator, char *inputed){
    //colocando o nome do jogo:
    strcpy(games[(*gamesIterator)-1].name, inputed);
}
void insertProducerName(GAME *games, int *gamesIterator){
    //colocando o nome da empresa:
    if(!scanf(" %[^(\r|\n)]*c", games[(*gamesIterator)-1].producer)){
        exit(1);
    }
}
void insertGameYear(GAME *games, int *gamesIterator){
    //colocando o ano do jogo:
    if(!scanf("%d", &games[(*gamesIterator)-1].year)){
        exit(1);
    }
}

GAME *buildGame(GAME *games, int *gamesIterator, char *inputed){
    insertGameName(games, gamesIterator, inputed);
    insertProducerName(games, gamesIterator);
    insertGameYear(games, gamesIterator);
    return games;
}

GAME *addGame(GAME *games, int *gamesIterator, char *inputed){ //retorno 1 para parar o laço e ir pra pesquisa!
    if(*gamesIterator == 0){ // se for o primeiro jogo, da um malloc de tamanho 1*sizeof(GAME);
        games = (GAME*) malloc (1*sizeof(GAME));
        (*gamesIterator)++;
    }
    else{
        games = (GAME*)realloc(games, ((*gamesIterator))*sizeof(GAME)); 
    }
    games = buildGame(games, gamesIterator, inputed);
    return games;
}
