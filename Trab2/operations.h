#ifndef OPERATIONS_H
#define OPERATIONS_H

#define PRE_ORDER 1

#define IN_ORDER 2

#define POST_ORDER 3

#include"jogo.h"
#include"tree.h"

int bigger(int firstValue, int secondValue);
int readIntInput();
char readCharInput();
void makeTheOperations (TREE *tree);
#endif 