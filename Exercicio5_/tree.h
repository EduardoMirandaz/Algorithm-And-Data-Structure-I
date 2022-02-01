#ifndef TREE_H
#define TREE_H
#include"person.h"
typedef struct tree TREE;

TREE *createTree();
int insertOnBinaryTree(TREE *tree, PERSON *person);
void preOrderBinaryT(TREE *arvoreBinaria);
void inOrderBinaryT(TREE *arvoreBinaria);
void postOrderBinaryT(TREE *arvoreBinaria);

void deleteTree(TREE **tree);
#endif