#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"tree.h"
#include"person.h"


typedef struct node NODE;

struct tree{
    NODE *root;
    int depth;
};

struct node{
    PERSON *person;
    NODE *right;
    NODE *left;
};

TREE *createTree(){
    TREE *emptyTree = (TREE*) calloc (1, sizeof(TREE));
    if(emptyTree != NULL){
        emptyTree->root = NULL;
        emptyTree->depth = -1;
        return emptyTree;
    }
    else{
        return NULL;
    }
}

static NODE* createNode(PERSON *person)
{
    NODE *newNode = (NODE *) malloc(sizeof(NODE));
    if (newNode != NULL) {
        newNode->person = person;
        newNode->right = NULL;
        newNode->left = NULL;
    }
    return newNode;
}

static void recursivePreOrder(NODE *root) {
    if (root != NULL) {
        printCpf(root->person);
        recursivePreOrder(root->left);
        recursivePreOrder(root->right);
    }
}

static void recursiveInOrder(NODE *root) {
    if (root != NULL) {
        recursiveInOrder(root->left);
        printCpf(root->person);
        recursiveInOrder(root->right);
    }
}

static void recursivePostOrder(NODE *root) {
    if (root != NULL) {
        recursivePostOrder(root->left);
        recursivePostOrder(root->right);
        printCpf(root->person);
    }
}

void preOrderBinaryT(TREE *arvoreBinaria)
{
    recursivePreOrder(arvoreBinaria->root);
}

void inOrderBinaryT(TREE *arvoreBinaria)
{
    recursiveInOrder(arvoreBinaria->root);
}

void postOrderBinaryT(TREE *arvoreBinaria)
{
    recursivePostOrder(arvoreBinaria->root);
}

int string_compare(char *firstStr, char *secondStr){
    int strSize = 11;
    for(int i = 0; i < strSize; i++){
        if(firstStr[i] > secondStr[i]){
            // printf("\nstring :%s\né maior que\nstring :%s\n", firstStr, secondStr);
            return 1;
        }
        else if(firstStr[i] < secondStr[i]){
            // printf("\nstring :%s\né menor que\nstring :%s\n", firstStr, secondStr);
            return -1;
        }
    }
    //printf("\nstring :%s\né igual a\nstring :%s\n", firstStr, secondStr);
    return 0;
}


NODE *recursiveInsertNode(NODE *root, PERSON *person){
    if (root == NULL)
        root = createNode(person);
    else if(string_compare(getCpf(root->person), getCpf(person)) == -1)
        root->right = recursiveInsertNode(root->right,person);
    else if(string_compare(getCpf(root->person), getCpf(person)) == 1)
        root->left = recursiveInsertNode(root->left,person);
    return root;
}

int recursiveSearch(NODE *root, char *cpf)
{
    if(root == NULL)
        return 0;
    if(string_compare(cpf,getCpf(root->person)) == 0){
        // if(string_compare(cpf,getCpf(root->person)) != 1){
            printPerson(root->person);
        // }
        return 1;
    }
    if(string_compare(cpf, getCpf(root->person)) == 1)
        return (recursiveSearch(root->right, cpf));
    else
        return (recursiveSearch(root->left, cpf));
}

int searchOnBinaryTree(TREE *tree, char *cpf)
{
    return(recursiveSearch(tree->root, cpf));
}

static void minRightChange(NODE *rightNode, NODE *willBeDeleted)
{
    // chegar até o mínimo à direita
    NODE *aux = rightNode;
    NODE *previous = willBeDeleted;

    while(aux->left != NULL){
        previous = aux;
        aux = aux->left;
    }
    if(previous != willBeDeleted){
        previous->left = aux->right;
    }
    else{
        previous->right = aux->right;
    }
    willBeDeleted->person = aux->person;
    free(aux);
    aux = NULL;
}


static int abb_remover_aux(NODE **root, char *cpf){
    if(*root == NULL)
    {
        return 0;
    }
    if( string_compare(cpf, getCpf((*root)->person)) == 0)
    {
        printPerson((*root)->person); // encontrei !
        if ((*root)->left == NULL || (*root)->right == NULL) 
        {/*Tem 1 filho só ou nenhum*/
            if( (*root)->left == NULL ){
                *root = (*root)->right;
            }
            else{
                *root = (*root)->left;
            }
        }
        else /* Caso tenha os 2 filhos*/
        {
            minRightChange( (*root)->right, (*root) );
        }
        return 1;
    }
    else
    {
        if(string_compare(cpf,getCpf((*root)->person)) == -1)
            return abb_remover_aux (&(*root)->left, cpf);
        else
            return abb_remover_aux (&(*root)->right, cpf);
    }
}


int binaryTreeRemove(TREE *tree, char *cpf){
    if(tree != NULL)
        return abb_remover_aux(&tree->root, cpf);
    return 0;
}

int insertOnBinaryTree(TREE *tree, PERSON *person){
    if (tree->root == NULL){
        tree->root = createNode(person);
        return(tree->root != NULL);
    }
    else{
        tree->root = recursiveInsertNode(tree->root, person);
        return( tree->root != NULL);
    }
}

void recursiveDeleteTree(NODE **root) {
    if (*root != NULL) {
        recursiveDeleteTree(&(*root)->left);
        recursiveDeleteTree(&(*root)->right);
        deletePerson(&(*root)->person);
        free(*root);
        *root = NULL;
    }
}
void deleteTree(TREE **tree) {
    recursiveDeleteTree(&(*tree)->root);
    free(*tree);
    *tree = NULL;
}