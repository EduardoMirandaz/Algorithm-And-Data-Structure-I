#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

char *copyString(const char *fonte) {
    char *destino = malloc(strlen (fonte) + 1);
    if (destino != NULL){
        strcpy(destino, fonte);
        return destino;
    }
    return NULL;
}

char* throwComma(char* linha, int num)
{
    char* tok;
    for (tok = strtok(linha, ";");
         tok && *tok;
         tok = strtok(NULL, ";"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int string_compare(char *firstStr, char *secondStr){
    int sizeOfFirstStr = sizeof(firstStr);
    int sizeOfSecondStr = sizeof(secondStr);
    int strSize = (sizeOfFirstStr / (sizeof(char)) ) + (sizeOfSecondStr / (sizeof(char))) ;
    for(int i = 0; i < strSize; i++){
        if(firstStr[i] > secondStr[i]){
            return 1;
        }
        else if(firstStr[i] < secondStr[i]){
            return -1;
        }
    }
    return 0;
}

char *readLine(FILE **textArchive) {
    char *string = NULL;
    char currentInput;
    int index = 0;
    do {
        currentInput = getc((*textArchive));
        if(currentInput == '\0') return NULL;
        string = (char *) realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;
        if(currentInput == '\r')
        {
            currentInput = (char)getc((*textArchive));
        }
    } while((currentInput != '\n') && (currentInput != EOF));
    string[index - 1] = '\0';
    return string;
}