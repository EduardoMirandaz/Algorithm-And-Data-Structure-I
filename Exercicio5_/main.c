#include<stdio.h>
#include<stdlib.h>
#include"readInput.h"
#include"tree.h"
#include"person.h"

void finalPrints(TREE *t, PERSON *p){
    printf("Inorder\n");
    inOrderBinaryT(t);
    printf("\nPreorder\n");
    preOrderBinaryT(t);
    printf("\nPostorder\n");
    postOrderBinaryT(t);
    printf("\n");
}

int main(){
    TREE *tree = createTree();    
    PERSON *person = NULL;
    int howMuchPeople = readIntInput();
    
    for(int i = 0; i < howMuchPeople; i++){
        person = createPerson();
        person = inputAndBuildPerson(person);
        insertOnBinaryTree(tree, person);
    }
    finalPrints(tree, person);
    deleteTree(&tree);
    free(tree); // o nó restante!
    tree = NULL;
}
