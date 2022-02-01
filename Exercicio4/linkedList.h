#ifndef LISTA_H
#define LISTA_H
#include"bignumber.h"


typedef struct linkedList_st LINKEDLIST;
typedef struct bigNumbers_st BIGNUMBERS;

LINKEDLIST *createLinkedList();
BIGNUMBERS* takeTheBigGuys(LINKEDLIST *firstBigNumberLL,  LINKEDLIST  *secondBigNumberLL, BIGNUMBERS *bignumbers);
LINKEDLIST *partionateTheBigNumber(char *strongerNumber, LINKEDLIST *firstBigNumberLL);
LINKEDLIST *receiveTheBigBuddy(LINKEDLIST *firstBigNumberLL);
int emptyList(const LINKEDLIST *list);
int castForInt(char *auxReducedNum);
void makeTheOperations(BIGNUMBERS *bigNumbers, char *operation);
char* getTheBigNumber(LINKEDLIST *linkedList, int key);
/*********************************************************************************/
void makeTheOperations(BIGNUMBERS *bigNumbers, char *operation);
void manipulateTheBigNumbers (LINKEDLIST *firstBigNumberLL, LINKEDLIST *secondBigNumberLL, char *operation);
/**************************** OPERACOES *****************************/
/*** Operações com os números ***/
char* getTheBigNumber(LINKEDLIST *linkedList, int key);
void makeTheOperations(BIGNUMBERS *bigNumbers, char *operation);
void sumTheBigNumbers(LINKEDLIST *firstBigNumberLL, LINKEDLIST *secondBigNumberLL);
void getTheCompleteNum(char *completeNumber, int start, LINKEDLIST *bigNumberLL);
/*** Comparações ***/
void comparationLogicForGreater1(char *completeNumber1, int sizeOfA);
void comparationLogicForGreater2(char *completeNumber1, int sizeOfA);
void compareIfEqualSizeForGreater(char *completeNumber1, char *completeNumber2, int size);
void compareIfEqualSizeForMinor(char *completeNumber1, char *completeNumber2, int size);
void seeIfTheNumberIsGreater(LINKEDLIST *firstBigNumberLL, LINKEDLIST *secondBigNumberLL);
void seeIfTheNumberIsMinor(LINKEDLIST *firstBigNumberLL, LINKEDLIST *secondBigNumberLL);
void seeIfTheNumbersAreEqual(LINKEDLIST *firstBigNumberLL, LINKEDLIST *secondBigNumberLL);

#endif //LISTA_H
