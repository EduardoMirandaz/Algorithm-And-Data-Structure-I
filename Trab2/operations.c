#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"operations.h"

#include"tree.h"
#include"jogo.h"


int bigger(int firstValue, int secondValue){
    int res = firstValue;
    if(secondValue > firstValue) res = secondValue;
    return res;
}

int readIntInput(){
    int integer = 0;
    if(!scanf("%d", &integer)){
        return -1;
    }
    return integer;
}
char readCharInput(){
    char character = ' ';
    if(!scanf("%c", &character)){
        return -1;
    }
    return character;
}

void removeGame(TREE *tree, char *year){

    // printf("PROCUREI, O RESULTADO == %d Achei = ", searchOnBinaryTree(tree, year));
    // printf("\n VOU REMOVER JOGOS DO ANO %s\n", year);
    while(searchOnBinaryTree(tree, year) ){
        binaryTreeRemove(tree, year);
    }
    // printf("\n ======================== \n");
}

void makeTheOperations (TREE *tree){
    
    int flagForPrint = 0; char operation[200];
    if(!scanf("%d", &flagForPrint)) exit(0);
    if(!scanf("%s", operation)) exit(0);

    while(operation[0] != 'F')
    {
        // se estamos em um ano de 4 digitos
        if(strlen(operation) == 4){
            if(searchOnBinaryTree(tree, operation)){
                removeGame(tree, operation);
            }
        }
        if(!scanf("%s", operation)) exit(0);
    }

    if(flagForPrint == PRE_ORDER) preOrderBinaryT(tree);
    else if(flagForPrint == IN_ORDER) inOrderBinaryT(tree);
    else if(flagForPrint == POST_ORDER) postOrderBinaryT(tree);
    
}