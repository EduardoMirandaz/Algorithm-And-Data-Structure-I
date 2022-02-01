#ifndef TREE_H
#define TREE_H
#include"person.h"
typedef struct tree TREE;

TREE *createTree();
int insertOnBinaryTree(TREE *tree, PERSON *person);
int binaryTreeRemove(TREE *tree, char *chave);
int searchOnBinaryTree(TREE *tree, char *cpf);
void preOrderPrint(TREE *t);
void preOrderBinaryT(TREE *arvoreBinaria);
void deleteTree(TREE **tree);
#endif