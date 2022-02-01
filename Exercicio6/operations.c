#include<stdio.h>
#include<string.h>
#include"operations.h"

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

char *readCpf(char *cpf){
    if(!scanf("%s", cpf)){
        return "-1";
    }
    char aux[12];
    int j = 0;
    for(int i = 0; i < 15; i++){
        if(cpf[i] != '.' && cpf[i] != '-'){
            aux[j] = cpf[i];
            j++;
        }
    }
    strcpy(cpf, " ");
    strcpy(cpf, aux);
    return cpf;
}

void makeTheOperations (char operation, PERSON *person, TREE *tree){
    if(operation == 'I')
    {
        person = createPerson();
        person = inputAndBuildPerson(person);
        insertOnBinaryTree(tree, person);
        preOrderPrint(tree);
    }
    else if(operation == 'R')
    {
        char cpf[15];
        strcpy(cpf, readCpf(cpf));
        if(!binaryTreeRemove(tree, cpf))
            printf("Pessoa nao encontrada.\n");
        preOrderPrint(tree);
    }
    else if (operation == 'B')
    {
        char cpf[15];
        strcpy(cpf, readCpf(cpf));
        if(!searchOnBinaryTree(tree, cpf))
            printf("Pessoa nao encontrada.\n");
    }
    printf("\n");
}