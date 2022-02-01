#ifndef BIGNUMBER_H
#define BIGNUMBER_H
#include"linkedList.h"


typedef struct bigNumber BIGNUMBER;

char *takeOperation(char *operation);
BIGNUMBER *createABigNumber();
BIGNUMBER *putTheFracionedInABigNumberStruct(char *auxReducedNum, BIGNUMBER *bigNumber);
void insertTheKey(BIGNUMBER *bigNumber, int *key);
int getTheKey(BIGNUMBER *bignumber);
char *getThePartionedNumber(BIGNUMBER *bigNumber);
void printAAA(BIGNUMBER *big);

#endif // BIGNUMBER_H