#ifndef PILHA_H
#define PILHA_H
#define TRUE 1
#define FALSE 0

#include "carta.h"

typedef int boolean;
typedef struct stack_st STACK;

int bringValue(CARD *card);
void playGame(STACK *stack, int howMuchCards);
STACK *createStack();
void stackCard(STACK *stack, CARD *card);
void unstackCard(STACK *stack, int *valueOfCard);
boolean deleteStack(STACK **stack);
void stackDeleteAll(STACK *const *stack);

#endif //PILHA_H