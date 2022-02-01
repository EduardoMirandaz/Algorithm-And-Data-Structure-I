#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"jogo.h"
#include"catalogo.h"

struct catalog_st{
    GAME *games;
    int size;
};

CATALOG *createCatalog(CATALOG *catalog){
    catalog = (CATALOG*) calloc (1,sizeof(CATALOG));
    return catalog;
}
CATALOG *insertGamesOnCatalog(GAME *games, CATALOG *catalog, int gamesIterator){
    catalog->games = games;
    catalog->size = gamesIterator;
    return catalog;
}

// Funções de busca:
void searchForYear(CATALOG *catalog){
    int yearToSearchFor = 0;
    if(!scanf("%d", &yearToSearchFor)){
       exit(1);
    }
    int foundGames = 0;
    int wardForFound = 0;
   for(int i = 0; i < catalog->size; i++){
        foundGames = searchForGameByYear(catalog->games, i, yearToSearchFor);
        if(foundGames) wardForFound = 1;
}
   if(!wardForFound) printf("Nada encontrado\n"); //Se nenhum jogo foi encontrado, mostra "nada encontrado" na tela.
}

void searchForCompany(CATALOG *catalog){
    int foundGames = 0;
    int wardForFound = 0;
    char companyToSearchFor[30];
    if(!scanf(" %[^(\r|\n)]*c", companyToSearchFor)){
        exit(1);
    }

   for(int i = 0; i < catalog->size; i++){
        foundGames = searchForGameByCompany(catalog->games, i, companyToSearchFor);
        if(foundGames) wardForFound = 1;
   }
   if(!wardForFound) printf("Nada encontrado\n"); //Se nenhum jogo foi encontrado, mostra "nada encontrado" na tela.
}


GAME *input(GAME *games, int *gamesIterator){
    char inputed[30];
    do {
        if(!scanf(" %[^(\r|\n)]*c", inputed)){
            exit(1);
        }
        if(strcmp("F", inputed) == 0){
            break;
        }
        (*gamesIterator)++;
        games = addGame(games, gamesIterator, inputed);
        }while(strcmp("F", inputed) != 0); // Adiciona jogos enquanto o primeiro input do while é diferente de 'F';
    return games;
}


char checkInput(char *input){ //verifica o input, se é 'F', 'A' ou 'E'.
    if(strcmp("A", input) == 0){
        return 'A';
    }
    else if(strcmp("E",  input) == 0){
        return 'E';
    }
    else{
        return 'F';
    }
}
void inputForSearch(CATALOG *catalog){
    char inputed[30];
    char verify = 'O'; // uma letra 'O' de flag neutra.
    do {
        setbuf(stdin, 0);
        if(!scanf(" %[^(\r|\n)]*c", inputed)){
            exit(1);
        }
        char verify = checkInput(inputed);
        if(verify == 'A'){
            searchForYear(catalog);
        }
        else if(verify == 'E'){
            searchForCompany(catalog);
        }
        else{
            break;
        }
    }
    while(verify != 'F'); // Adiciona jogos enquanto o primeiro input do while é diferente de 'F';
}
