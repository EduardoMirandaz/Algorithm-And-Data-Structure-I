#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"operations.h"
 
int main(){
    TREE *tree = createTree();
    PERSON *person = NULL;
    int howMuchPeople = readIntInput();
    for(int i = 0; i < howMuchPeople; i++)
    {
        person = createPerson();
        person = inputAndBuildPerson(person);
        insertOnBinaryTree(tree, person);
        getchar();
    }
    char operation = ' ';
    operation = readCharInput();
    makeTheOperations(operation, person, tree);
    deleteTree(&tree);
    free(tree); // o nó restante!
    tree = NULL;
}

void preOrderPrint(TREE *t){
    printf("Preorder\n");
    preOrderBinaryT(t);
}
