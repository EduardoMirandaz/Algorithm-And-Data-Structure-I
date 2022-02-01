#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"bignumber.h"
#include"linkedList.h"


struct bigNumber{
    char partionedNumber[5];
    int key;
};


char *takeOperation(char *operation){
    if(!scanf(" %[^( )]*c", operation)) exit(1);
    return (operation);
}

BIGNUMBER *putTheFracionedInABigNumberStruct(char *auxReducedNum, BIGNUMBER *bigNumber){
    strcpy(bigNumber->partionedNumber, auxReducedNum);
    return bigNumber;
}

BIGNUMBER *createABigNumber(){
    BIGNUMBER *bigNumber = (BIGNUMBER*) malloc(sizeof(BIGNUMBER));
    return bigNumber;
}

void insertTheKey(BIGNUMBER *bigNumber, int *key){
    bigNumber->key = *key;
}
void printAAA(BIGNUMBER *big)
{
    //printf("\n [%s] key = %d", big->partionedNumber, big->key);

}
char *getThePartionedNumber(BIGNUMBER *bigNumber){
    return bigNumber->partionedNumber;
}

int getTheKey(BIGNUMBER *bignumber){
    return (bignumber->key);
}

