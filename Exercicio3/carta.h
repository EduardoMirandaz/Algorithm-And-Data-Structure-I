#ifndef ITEM_H
#define ITEM_H
#define TRUE 1
#define FALSE 0

typedef int boolean;
typedef struct card_st CARD;

void printstackedCard(CARD *top);
int bringValue(CARD *card);
CARD *alocCard(CARD **card);
int takeValueFromSymbol(char *symbol);
CARD *createCard(CARD *card);
boolean deleteCard(CARD **card);
boolean setCardSymbolValue(CARD *card, int symbolValue);

#endif //ITEM_H
