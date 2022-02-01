#include<stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct node_st NODE;

struct node_st{
    CARD *card;     
    NODE *previous;
};

struct stack_st{
    NODE *top;
    int size;
};

STACK *createStack(){
    STACK *stack = (STACK*) malloc(sizeof(STACK));
    
    if(stack != NULL)
    {
        stack->top = NULL;
        stack->size = 0;
    }
    return stack;
}

void stackCard(STACK *stack, CARD *card){
    if (stack!=NULL)
    {
        NODE *newNode = (NODE *) malloc(sizeof(NODE));
        if(newNode != NULL)
        {
            newNode->card = card;
            newNode->previous = stack->top;
            stack->top = newNode;
            stack->size++;
            printstackedCard(stack->top->card);
            return;
        }
    }
    printf("There's no more space, =(");
    exit(1);
}

void unstackCard(STACK *stack, int *valueOfCard){
    if (stack != NULL) {
        NODE *unstacked = stack->top;
        CARD *card = stack->top->card;
        *valueOfCard = bringValue(card);
        stack->top = stack->top->previous;
        unstacked->previous = NULL;
        free(unstacked);
        unstacked = NULL;
        stack->size--;
    }
    else{
        printf("The stack is empty, there's no way to play :(");
        exit(1);
    }
}

boolean deleteStack(STACK **stack)
{
    if (*stack != NULL)
    {
        stackDeleteAll(stack);
        free(*stack);
        *stack = NULL;
        return TRUE;
    }
    return FALSE;
}

void stackDeleteAll(STACK *const *stack){
    NODE *temporaryNode;
    temporaryNode = (*stack)->top;
    (*stack)->top = (*stack)->top->previous;
    deleteCard(&temporaryNode->card);
    temporaryNode->previous = NULL;
    free(temporaryNode);
    temporaryNode = NULL;
}


void playGame(STACK *stack, int howMuchCards){
    int valueOfCard = 0;
    int sumTo21 = 0;
    while(stack != 0){
        if(sumTo21 < 21){
            unstackCard(stack, &valueOfCard);
            sumTo21 = sumTo21 + valueOfCard;
        }
        else break; // se a soma nao for menor que 21 sai do loop
    }
    sumTo21 == 21 ? printf("Ganhou ;)") : printf("Perdeu :(\nSoma :: %d", sumTo21);
    // a soma deu 21 ? se sim, mostre ganhou, senão, mostre Perdeu e a soma!;
}   

