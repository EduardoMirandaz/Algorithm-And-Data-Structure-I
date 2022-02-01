#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "carta.h"
#include "pilha.h"
int howMuchCards = 52;

// amo minha vida!
STACK* createAllCards( STACK* stack, CARD *card, int howMuchCards);

int main(){
    STACK *stack = createStack();
    CARD *card = NULL;
    if(stack == NULL) {
        printf("Couldn't create the stack!");
        exit(1);
    } 
    createAllCards(stack, card, howMuchCards);
    playGame(stack, howMuchCards);
    deleteStack(&stack);
    free(card);
}

STACK* createAllCards( STACK* stack, CARD *card, int howMuchCards){
    for(int i = 0; i < howMuchCards; i++){
        card = alocCard(&card);
        card = createCard(card);
        stackCard(stack, card);
    }
    return stack;
}
