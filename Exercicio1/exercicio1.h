#ifndef EXERCICIO1_H
#define EXERCICIO1_H
//mensagem para o compilador "se nao está definida uma macro com esse nome, defina-a e execute esses códigos em sequncia"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct dot_ DOT;
typedef struct distance_ DISTANCE;

int inputAmountDots();
DOT *createDotsVector(int amountDots);
DISTANCE *createDistanceVector(int amountDots);
void inputDots(int amountDots, DOT *dotsVector);
void calculateDistance(DOT *dotsVector, DISTANCE *distancesVector, int amountDots);
void printFinalDistance(DISTANCE *distancesVector, int amountDots);
void freeVectors(DOT *dotsVector, DISTANCE *distancesVector);

#endif //EXERCICIO1_H <-terminei esse if