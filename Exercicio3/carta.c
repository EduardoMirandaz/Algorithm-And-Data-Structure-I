#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carta.h"

struct card_st
{
    int symbolValue;
    char cardSuit[7];
};

CARD *alocCard(CARD **card){
    *card = (CARD*)malloc(sizeof(CARD));
    return *card;
}
int takeValueFromSymbol(char *symbol){
    if(symbol[0] == 'V' || symbol[0] == 'D' || symbol[0] == 'R')
     return 10;              // retorna 10 se for DAMA, VALETE ou REI
    else
     return(atoi(symbol));   // se nao for nenhum dos anteriores, dá cast no valor e retorna como INT.
}

CARD *createCard(CARD *card){
    // printf("criando carta :) \n");
    char charValue[7];
    if(!scanf("%s %s", card->cardSuit, charValue)){
        printf("scanf error");
        exit(1);
    }
    getchar();
    card->symbolValue = takeValueFromSymbol(charValue);
    // printf("%s %d", card->cardSuit, card->symbolValue);
    return card;
}

boolean deleteCard(CARD **card){
    if (*card != NULL)
    {
        (*card)->symbolValue = 0; /*apaga o card simbolicamente*/
        free (*card);
        *card = NULL;
        return TRUE;
    }
    return FALSE;
}

boolean setCardSymbolValue(CARD *card, int symbolValue){
    if (card != NULL){
        card->symbolValue = symbolValue;
        return TRUE;
    }
    return FALSE;
}

int bringValue(CARD *card){
    // printf("\n[ %d ]\n ", card->symbolValue);
    return(card->symbolValue);
}

void printstackedCard(CARD *top){
    // printf("=- =- CARTINHA CRIADA !! =- =-\n");
    // printf("%s\n", top->cardSuit);
    // printf("%d\n", top->symbolValue);
}
