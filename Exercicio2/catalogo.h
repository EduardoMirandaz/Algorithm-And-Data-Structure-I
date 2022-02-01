#ifndef CATALOGO_H
#define CATALOGO_H

typedef struct catalog_st CATALOG;

CATALOG *createCatalog(CATALOG *catalog);
CATALOG *insertGamesOnCatalog(GAME *games, CATALOG *catalog, int gamesIterator);
char checkInput(char *input);
GAME *input(GAME *games, int *gamesIterator);
void inputForSearch(CATALOG *catalog);
void searchForYear(CATALOG *catalog);
void searchForCompany(CATALOG *catalog);

#endif //CATALOGO_H
