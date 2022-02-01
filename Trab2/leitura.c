#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"leitura.h"
#include"tree.h"
#include"jogo.h"


FILE *readArchive(FILE *textArchive)
{
  if( (textArchive = fopen(arquivo, "r+") )== NULL)
  {
      printf("\nError Opening File for Writing");
      return 0;
  }
  return textArchive;
}

//Enquanto o arquivo nao terminar, leio linha a linha e monto os jogos, colocando-os no catálogo
void readInput(FILE *textArchive, GAME *game, TREE *tree){
    // coloco um '\0' no fim do arquivo no lugar do '\n'
    fseek(textArchive,0, SEEK_END);
    getc(textArchive);
    putc('\0', textArchive);

    // Temos que setar o ponteiro para o 3 caractere pois há uma indicação de unicode
    fseek(textArchive, 3, SEEK_SET);

    char *stringWithAttributes = NULL; // Linha auxiliar para leitura do arquivo
    while (!feof(textArchive))
    {
        stringWithAttributes = readLine(&textArchive);
        if (stringWithAttributes != NULL){
            gameInsertion(stringWithAttributes, textArchive, game, tree);
            strcpy(stringWithAttributes, " ");
        }
        else{
            fclose(textArchive);
            return;    
        }
    }
    fclose(textArchive);
}

void gameInsertion(char *stringWithAttributes, FILE *textArchive, GAME *game, TREE *tree){
    game = createEmptyGame();
    game = addGame(game, stringWithAttributes);
    // se nao consigo inserir, mostro erro e saio;
    if(!insertOnBinaryTree(tree, game)){
        printf("Erro ao inserir jogo na árvore!");
    };
}
