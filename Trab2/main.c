#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"operations.h"
#include"leitura.h"
#include"jogo.h"
#include"tree.h"

int main(){
    FILE *textArchive = NULL;
    TREE *tree = createTree();
    GAME *game = NULL;
    textArchive = readArchive(textArchive);
    readInput(textArchive, game, tree);
    makeTheOperations(tree);
    deleteTree(&tree);
}

