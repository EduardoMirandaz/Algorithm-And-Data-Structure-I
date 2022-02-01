#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"jogo.h"
#include"catalogo.h"

int main(){
    GAME *games = NULL;
    CATALOG *catalog = NULL;
    int gamesIterator = 0;
    catalog = createCatalog(catalog);
    games = input(games, &gamesIterator);
    catalog = insertGamesOnCatalog(games, catalog, gamesIterator);
    inputForSearch(catalog);
    return 0;
}
