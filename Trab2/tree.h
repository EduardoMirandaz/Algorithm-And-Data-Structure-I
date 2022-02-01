#ifndef TREE_H
#define TREE_H

#include"jogo.h"
#include "util.h"

typedef struct tree TREE;

TREE *createTree();
int insertOnBinaryTree(TREE *tree, GAME *game);
int binaryTreeRemove(TREE *tree, char *chave);
int searchOnBinaryTree(TREE *tree, char *gameYear);
void preOrderPrint(TREE *t);
void preOrderBinaryT(TREE *arvoreBinaria);
void inOrderBinaryT(TREE *arvoreBinaria);
void postOrderBinaryT(TREE *arvoreBinaria);
void deleteTree(TREE **tree);
void libera_TREE(TREE* root);
int insertInsert(TREE *tree, GAME *game);
#endif