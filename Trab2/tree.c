#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "tree.h"
#include "jogo.h"
#include "operations.h"
#include "util.h"


typedef struct node NODE;

struct tree{
    NODE *root;
    int depth;
};

struct node{
    int height;
    GAME *game;
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

NODE *createNode(GAME *game) {
    NODE *node = (NODE *) malloc(sizeof (NODE));
    if (node != NULL) {
        node->height = 0;
        node->right = NULL;
        node->left = NULL;
        node->game = game;
    }
    return node;
}

static void recursivePreOrder(NODE *root) {
    if (root != NULL) {
        printGameName(root->game);
        recursivePreOrder(root->left);
        recursivePreOrder(root->right);
    }
}

static void recursiveInOrder(NODE *root) {
    if (root != NULL) {
        recursiveInOrder(root->left);
        printGameName(root->game);
        recursiveInOrder(root->right);
    }
}

static void recursivePostOrder(NODE *root) {
    if (root != NULL) {
        recursivePostOrder(root->left);
        recursivePostOrder(root->right);
        printGameName(root->game);
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

NODE *recursiveInsertNode(NODE *root, GAME *game){
    if (root == NULL)
        root = createNode(game);
    else if(string_compare(getYearNameKey(root->game), getYearNameKey(game)) == -1)
        root->right = recursiveInsertNode(root->right,game);
    else if(string_compare(getYearNameKey(root->game), getYearNameKey(game)) == 1)
        root->left = recursiveInsertNode(root->left,game);
    return root;
}

int recursiveSearch(NODE *root, char *gameYear)
{
    if(root == NULL)
        return 0;
    if(strstr(getYearNameKey(root->game),gameYear) != NULL){
        return 1;
    }
    if(string_compare(gameYear, getGameYear(root->game)) == 1)
        return (recursiveSearch(root->right, gameYear));
    else
        return (recursiveSearch(root->left, gameYear));
}

int searchOnBinaryTree(TREE *tree, char *gameYear)
{
    return(recursiveSearch(tree->root, gameYear));
}

int height(NODE *node){
    if(node == NULL)
        return -1;
    else
        return node->height;
}

int balance(NODE *node){
    return labs(height(node->left) - height(node->right));
}


static NODE *insertAndRotate(NODE *root,  GAME *item);
static boolean isUmbalanceNegative(NODE *root);
static boolean isUmbalancePositive(NODE *root);
static boolean isGameKeyBigger( NODE *root,  GAME *item);
static boolean isGameKeyLower( NODE *root,  GAME *item);
static NODE *selectAndExecuteRotation(NODE *root,  GAME *item);
static NODE *insertNode(NODE *root, GAME *item);


int max(int a, int b)
{
    return (a > b)? a : b;
}

NODE *Rrotate(NODE *a) {
    NODE *auxNode = a->left;
    a->left = auxNode->right;
    auxNode->right = a;

    a->height = max(height(a->left),
                    height(a->right)) + 1;
    auxNode->height = max(height(auxNode->left),
                    a->height) + 1;
    return auxNode;
}

NODE *Lrotate(NODE *receivedNode) {
    NODE *auxNode = receivedNode->right;
    receivedNode->right = auxNode->left;
    auxNode->left = receivedNode;

    receivedNode->height = max(height(receivedNode->left),
                    height(receivedNode->right)) + 1;
    auxNode->height = max(height(auxNode->right),
                    receivedNode->height) + 1;
    return auxNode;
}

NODE *LRrotate(NODE *receivedNode)   {
    receivedNode->left = Lrotate(receivedNode->left);
    return Rrotate(receivedNode);
}

NODE *RLrotate(NODE *receivedNode)   {
    receivedNode->right = Rrotate(receivedNode->right);
    return Lrotate(receivedNode);
}
static void maxLeftChange(NODE *aux, NODE *root, NODE *previous)
{
    if(aux->right != NULL)
    {
        maxLeftChange(aux->right, root, aux);
        return;
    }
    if(root == previous) {
        previous->left = aux->left;
    }
    else {
        previous->right = aux->left;
    }
    root->game = aux->game;
    free(aux);
    aux = NULL;
}


NODE *recursiveRemoveNode(NODE **root, char *year) {
    NODE *aux;
    if (*root == NULL) {
        return NULL;
    }
    else
    {
        if(strstr(getYearNameKey((*root)->game),year) != NULL)
        {
            // se tem 1 ou nenhum filho
            if((*root)->left == NULL || (*root)->right == NULL)
            {
                aux = *root;
                if(((*root)->left == NULL)){
                    *root = ((*root)->right);
                }
                else{
                    *root = ((*root)->left);
                }
                free(aux);
                aux = NULL;
            } 
            // se tem 2 filhos, troca pelo maior da sub-arvore da esquerda
            else
            {
                maxLeftChange((*root)->left, (*root), (*root));
            }
        }

        else if (string_compare(year,getGameYear((*root)->game)) == -1)
        {
            // tento remover na esquerda se a chave do ano for menor que a raiz em questao 
            (*root)->left = recursiveRemoveNode(&(*root)->left, year);
            //atualizo a height
            (*root)->height = max(height((*root)->left), height((*root)->right)) + 1;
        }

        else if (string_compare(year,getGameYear((*root)->game)) == 1) {
            // tento remover na direita se a chave do ano for maior que a raiz em questao
            (*root)->right = recursiveRemoveNode(&(*root)->right, year);
            //atualizo a height
            (*root)->height = max(height((*root)->left), height((*root)->right)) + 1;
        }

        if (*root == NULL){
            return NULL;
        }

        if (height((*root)->left) - height((*root)->right) == -2) {
            if (height((*root)->right->left) - height((*root)->right->right) <= 0) {
                *root = Lrotate(*root);
            } else {
                *root = RLrotate(*root);
            }
        }
        if (height((*root)->left) - height((*root)->right) == 2) {
            if (height((*root)->left->left) - height((*root)->left->right) >= 0) {
                *root = Rrotate(*root);
            } else {
                *root = LRrotate(*root);
            }
        }
    }

    return *root;
}

// Remove um nó a partir de sua chave ano_nome
int binaryTreeRemove(TREE *tree, char *gameNameKey)
{
    return (tree->root = recursiveRemoveNode( &(tree)->root, gameNameKey)) != NULL;
}

void recursiveDeleteTree(NODE **root) {
    if (*root != NULL) {
        recursiveDeleteTree(&(*root)->left);
        recursiveDeleteTree(&(*root)->right);
        deleteGame(&(*root)->game);
        free(*root);
        *root = NULL;
    }
}

void deleteTree(TREE **tree) {
    recursiveDeleteTree(&(*tree)->root);
    free(*tree);
    *tree = NULL;
}

static NODE *insertAndRotate(NODE *root,  GAME *item) {
    root = insertNode(root, item);

    root->height = max(height(root->left),
                       height(root->right)) + 1;

    root = selectAndExecuteRotation(root, item);

    return root;
}

static NODE *insertNode(NODE *root,  GAME *game) {
    if (root == NULL) {
        root = createNode(game);
    }
    else if (string_compare(getYearNameKey(root->game), getYearNameKey(game)) == -1) {
        root->right = insertAndRotate(root->right, game);
    }
    else if (string_compare(getYearNameKey(root->game), getYearNameKey(game)) == 1) {
        root->left = insertAndRotate(root->left, game);
    }
    return root;
}

static NODE *selectAndExecuteRotation(NODE *root, GAME *item) {
    if (isUmbalanceNegative(root)) {
        if (isGameKeyBigger(root->right, item)) {
            root = Lrotate(root);
        }
        else {
            root = RLrotate(root);
        }
    }

    if (isUmbalancePositive(root)) {
        if (isGameKeyLower(root->left, item))
            root = Rrotate(root);
        else
            root = LRrotate(root);
    }
    return root;
}

static boolean isGameKeyLower( NODE *root,  GAME *item) {

    return string_compare(getYearNameKey(item), getYearNameKey(root->game)) == -1;
}

static boolean isGameKeyBigger( NODE *root, GAME *item) {
    return string_compare(getYearNameKey(item), getYearNameKey(root->game)) == 1;
}

static boolean isUmbalancePositive(NODE *root) {
    return height(root->left)
           - height(root->right) == 2;
}

static boolean isUmbalanceNegative(NODE *root) {
    return height(root->left)
           - height(root->right) == -2;
}

boolean insertOnBinaryTree(TREE *arvore,  GAME *item) {
    arvore->root = insertAndRotate(arvore->root, item);
    return arvore->root != NULL;
}
