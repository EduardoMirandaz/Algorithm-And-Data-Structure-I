#include<stdio.h>
#include<stdlib.h>
#include"bignumber.h"
#include"linkedList.h"



int main(){
    int howManyOperations = 0;
    if(!scanf("%d", &howManyOperations)){
        exit(1);
    }
    for(int i = 0; i < howManyOperations; i++){
        LINKEDLIST *firstNumber = createLinkedList();
        LINKEDLIST *secondNumber = createLinkedList();
        char operation[10];
        takeOperation(operation);
        BIGNUMBERS *bignumbers = (BIGNUMBERS*) malloc (1*sizeof(firstNumber) + sizeof(secondNumber));
        bignumbers = takeTheBigGuys(firstNumber, secondNumber , bignumbers);
        makeTheOperations(bignumbers, operation);
        free(bignumbers);
    }
}

