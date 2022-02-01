#include<stdio.h>
#include <stdlib.h>
#include<string.h>

#include "linkedList.h"
#include "bignumber.h"


typedef struct node_st NODE;

struct node_st
{
    BIGNUMBER *bignumber;
    NODE* nextNode;
};

struct linkedList_st{
    NODE* start;
    NODE* end;
    int size;
};

//just to return the 2 number for main() =p
struct bigNumbers_st {
    LINKEDLIST *firstBigNumberLL;
    LINKEDLIST *secondBigNumberLL;
};

LINKEDLIST *createLinkedList()
{
    LINKEDLIST *number = (LINKEDLIST*) malloc(sizeof(LINKEDLIST));
    if(number != NULL)
    {
        number->start = NULL;
        number->end = NULL;
        number->size = 0;
        return number;
    }
    printf("cannot create a number :(");
    exit(1);
    return number;
}


int castForInt(char *auxReducedNum){
    return atoi(auxReducedNum);
}

LINKEDLIST* insertLinkedList(LINKEDLIST *linkedList, BIGNUMBER *bignumber){
    if(linkedList != NULL)
    {
        NODE *novoNode = (NODE *) malloc(sizeof(NODE));
        if (novoNode != NULL) {
            novoNode->bignumber = bignumber;
            novoNode->nextNode = NULL;
            if(emptyList(linkedList))
            {
                linkedList->start = novoNode;
            }
            else
            {
                linkedList->end->nextNode = novoNode;
            }
            linkedList->end = novoNode;
            linkedList->size++;
            return linkedList;
        }
    }
    printf("Error =(");
    exit(1);
    return 0;
}

LINKEDLIST *partionateTheBigNumber(char *strongerNumber, LINKEDLIST *bigNumberLL){
    int howManyNumbers = strlen(strongerNumber); // count how many caracters
    int reverseIterator = 0;
    int key = 0;
    /************ dividindo os números de 4 em 4 **********/
    for(int i = howManyNumbers-1; i >=0; i = i-4){
        char auxReducedNum[5];
        strcpy(auxReducedNum, "0000");
        reverseIterator=0;
        for(int j = 3; j >= 0; j--){
            if(i-reverseIterator >= 0){
                auxReducedNum[j] = strongerNumber[i-reverseIterator];
                reverseIterator++;
            }
        }
        BIGNUMBER *bigNumber = createABigNumber();
        bigNumber = putTheFracionedInABigNumberStruct(auxReducedNum, bigNumber);
        bigNumberLL = insertLinkedList(bigNumberLL, bigNumber);
        insertTheKey(bigNumber, &key);
        key++;
        howManyNumbers = i;
    }
    return bigNumberLL;
}

LINKEDLIST *receiveTheBigBuddy(LINKEDLIST *firstBigNumberLL){
    char strongerNumber[100];
    if(!scanf("%s", strongerNumber)) exit(1);
    return (partionateTheBigNumber(strongerNumber, firstBigNumberLL));//particiona o número grande em partes menores e poe numa ListLigada
}

BIGNUMBERS* takeTheBigGuys(LINKEDLIST *firstBigNumberLL,  LINKEDLIST  *secondBigNumberLL, BIGNUMBERS *bignumbers){
    firstBigNumberLL = receiveTheBigBuddy(firstBigNumberLL);  //recebe o número grande e já retorna uma lista ligada
    secondBigNumberLL = receiveTheBigBuddy(secondBigNumberLL); 
    
    bignumbers->firstBigNumberLL = firstBigNumberLL; 
    bignumbers->secondBigNumberLL = secondBigNumberLL; 
    
    return bignumbers;
}

int emptyList(const LINKEDLIST *list)
{
    if(list != NULL)
    {
        return list->start == NULL;
    }
    return 0;
}

char* getTheBigNumber(LINKEDLIST *linkedList, int key) {
    if (linkedList != NULL) {
        NODE *noAtual;
        noAtual = linkedList->start;
        while(noAtual != NULL)
        {
            if(getTheKey(noAtual->bignumber) == key)
            {
                return getThePartionedNumber(noAtual->bignumber);
            }
            noAtual = noAtual->nextNode;
        }
    }
    return NULL;
}
void makeTheOperations(BIGNUMBERS *bigNumbers, char *operation){
    manipulateTheBigNumbers(bigNumbers->firstBigNumberLL,bigNumbers->secondBigNumberLL, operation);
}
void manipulateTheBigNumbers (LINKEDLIST *firstBigNumberLL, LINKEDLIST *secondBigNumberLL, char *operation){
    if(strcmp(operation, "soma") == 0){
        sumTheBigNumbers(firstBigNumberLL, secondBigNumberLL);
    }
    else if(strcmp(operation, "maior") == 0){
        seeIfTheNumberIsGreater(firstBigNumberLL, secondBigNumberLL);        
    }
    else if(strcmp(operation, "menor") == 0){
        seeIfTheNumberIsMinor(firstBigNumberLL, secondBigNumberLL);
    }
    else if(strcmp(operation, "igual") == 0){
        seeIfTheNumbersAreEqual(firstBigNumberLL, secondBigNumberLL);
    }
    else{
        printf("Operação inválida :(");
        exit(1);
    }
}
void getTheCompleteNum(char *completeNumber, int start, LINKEDLIST *bigNumberLL){
    char partionatedBigNumber[5];
    for(int i = start; i >= 0 ; i--){
        strcpy(partionatedBigNumber,getTheBigNumber(bigNumberLL, i));
        strcat(completeNumber, partionatedBigNumber);
    }
    strcpy(partionatedBigNumber, "");
}


int getTheBiggestNumberSize(int a, int b){
    if(a > b) return ((a+1)*4);
    return ((b+1)*4);
}
/********************* Soma *************************/
void sumTheBigNumbers(LINKEDLIST *firstBigNumberLL, LINKEDLIST *secondBigNumberLL){

    /*************Pegando o tamanho do maior número pela chave ***********/

    int sizeOfTheBiggest = (getTheBiggestNumberSize(getTheKey(firstBigNumberLL->end->bignumber), getTheKey(secondBigNumberLL->end->bignumber)));
    
    /************ Pegando os números e concatenando **********************/

    char partionatedBigNumber1[5];
    char partionatedBigNumber2[5];
    char *completeNumber1 = (char*) malloc(sizeOfTheBiggest*sizeof(char));    
    char *completeNumber2 = (char*) malloc(sizeOfTheBiggest*sizeof(char));
    for(int i = getTheKey(firstBigNumberLL->end->bignumber); i >= 0 ; i--){
        strcpy(partionatedBigNumber1,getTheBigNumber(firstBigNumberLL, i));
        strcat(completeNumber1, partionatedBigNumber1);
    }
    for(int i = getTheKey(secondBigNumberLL->end->bignumber); i >= 0 ; i--){
        strcpy(partionatedBigNumber2,getTheBigNumber(secondBigNumberLL, i));
        strcat(completeNumber2, partionatedBigNumber2);
    }

    /******************* Atribuindo as variáveis auxiliáres *****************/
    int sizeOfA = strlen(completeNumber1);
    int sizeOfB = strlen(completeNumber2);
    char *auxCompleteBigNumber = (char*) malloc(sizeOfTheBiggest*sizeof(char));
    char *auxCompleteLesserNumber = (char*) malloc(sizeOfTheBiggest*sizeof(char));    
    char *sumResult = (char*) malloc((sizeOfTheBiggest+10)*sizeof(char));
    /*********  if(sizeOfA > sizeOfB) ************/
    auxCompleteBigNumber = completeNumber1;
    auxCompleteLesserNumber = completeNumber2;
    int sizeOfMinor = strlen(auxCompleteLesserNumber);
    int sizeOfBigger = strlen(auxCompleteBigNumber);
    /******************* else *********************/
    if(sizeOfB > sizeOfA){
        auxCompleteLesserNumber = completeNumber1;
        auxCompleteBigNumber = completeNumber2;
        sizeOfMinor = strlen(auxCompleteLesserNumber);
        sizeOfBigger = strlen(auxCompleteBigNumber);
    }
    /******************* Somando os algarismos **********************/
    int carry = 0, sum = 0;
    int iteratorForSum = (sizeOfMinor+sizeOfTheBiggest)-1, j = sizeOfMinor-1;

    for(int i = sizeOfBigger-1; i >= 0; i--){
        // Se o iterador do MENOR NÚMERO ainda é maior ou igual a 0, somo o respectivo algarismo dos dois numeros;
        if(j >= 0){
            int firstNum = auxCompleteBigNumber[i] - '0';
            int secondNum = auxCompleteLesserNumber[j] - '0';
            sum = firstNum + secondNum + carry;
            if(sum >= 10){
                carry = 1;
                sumResult[iteratorForSum] = (sum-10) + '0';
            }
            else{
                carry = 0;
                sumResult[iteratorForSum] = sum + '0';
            }
            j--;
        }
        /*** Se o iterador do menor número já é inferior a zero, apenas "desço" os valores do maior para o "char resultado" */
        else{
            if(carry){
                sum = (auxCompleteBigNumber[i] - '0') + carry;
                sumResult[iteratorForSum] = sum + '0';
                carry = 0;
            }
            else{
                sumResult[iteratorForSum] = auxCompleteBigNumber[i];
            }
        }
        iteratorForSum--;
    }
    
    /*************** Imprimindo a soma ************************/
    printf("Resultado :: ");
    if(carry)   printf("1");
    int i = iteratorForSum+1;
    while(sumResult[i] == '0') i++;
    for(; i <= (sizeOfMinor+sizeOfTheBiggest)-1; i++){
        printf("%c", sumResult[i]);
    }
    printf("\n");
    free(completeNumber1);
    free(completeNumber2);
    free(sumResult);
}
/****************** Comparações *********************/
void comparationLogicForGreater1(char *completeNumber1, int sizeOfA){
    int i = 0;
    int startBiggerNumber = 0;
    while(completeNumber1[i] == '0'){
        i++;
        startBiggerNumber = i;
    }
    if(completeNumber1[startBiggerNumber] == '-'){
        printf("Resultado :: False\n");
        return;
    }
    else{
        printf("Resultado :: True\n");
        return;
    }
}
void comparationLogicForGreater2(char *completeNumber1, int sizeOfA){
    int i = 0;
    int startBiggerNumber = 0;
    while(completeNumber1[i] == '0'){
        i++;
        startBiggerNumber = i;
    }
    if(completeNumber1[startBiggerNumber] == '-'){
        printf("Resultado :: True\n");
        return;
    }
    else{
        printf("Resultado :: False\n");
        return;
    }
}
void compareIfEqualSizeForGreater(char *completeNumber1, char *completeNumber2, int size){
    int startCounter1 = 0;
    int startCounter2 = 0;
    int signal = 1; //Posi
    int i = 0;
    /********* Seto os contadores para aonde começam os números, ignorando os zeros ********/
    while(completeNumber1[i] == '0'){
        startCounter1++;
        i++;
    }
    i = 0;
    while(completeNumber2[i] == '0'){
        startCounter2++;
        i++;
    }

    /************ Se o primeiro é negativo e o segundo não, logo 1o < 2o ************/
    if((completeNumber1[startCounter1] == '-') && (completeNumber2[startCounter2] != '-')){
        printf("Resultado :: False\n");
        return;
    }
    /************ Se o segundo é negativo e o primeiro não, logo 2o < 1o ************/
    else if((completeNumber1[startCounter1] != '-') && (completeNumber2[startCounter2] == '-')){
        printf("Resultado :: True\n");
        return;
    }
    /************ Se os dois forem negativos, ligo a flag signal e vou pro próximo número ************/
    else if((completeNumber1[startCounter1] == '-') && (completeNumber2[startCounter2] == '-')){
        completeNumber1[startCounter1] = '0';
        completeNumber2[startCounter2] = '0';
        signal = -1;
        startCounter1++;
        startCounter2++;
    }
    char partionedNumber1[5];
    char partionedNumber2[5];
    int j = 0;
    int k = 0; 
    while(size){
        strcpy(partionedNumber1, "");
        strcpy(partionedNumber2, "");
        for(int i = 0; i < 4; i++){
            partionedNumber1[i] = completeNumber1[j];
            partionedNumber2[i] = completeNumber2[k];
            j++;
            k++;
        }

        int parseInt1 = atoi(partionedNumber1)*signal;
        int parseInt2 = atoi(partionedNumber2)*signal;
        if(parseInt1 == parseInt2){
            size--;
            continue;
        }
        else if(parseInt1 < parseInt2){
            printf("Resultado :: False\n");
            return;
        }
        if(parseInt1 > parseInt2){
            printf("Resultado :: True\n");
            return;
        }
    }
}
void seeIfTheNumberIsGreater(LINKEDLIST *firstBigNumberLL, LINKEDLIST *secondBigNumberLL){
    /*************Pegando o tamanho do maior número pela chave ***********/
    int sizeOfTheBiggest = (getTheBiggestNumberSize(getTheKey(firstBigNumberLL->end->bignumber), getTheKey(secondBigNumberLL->end->bignumber)));
    /************ Pegando os números e concatenando **********************/
    char *completeNumber1 = (char*) malloc(sizeOfTheBiggest*sizeof(char));    
    char *completeNumber2 = (char*) malloc(sizeOfTheBiggest*sizeof(char));
    getTheCompleteNum(completeNumber1, getTheKey(firstBigNumberLL->end->bignumber), firstBigNumberLL);
    getTheCompleteNum(completeNumber2, getTheKey(secondBigNumberLL->end->bignumber), secondBigNumberLL);
    /************ Atribuindo os tamanhos dos números **********************/
    int sizeOfA = strlen(completeNumber1);
    int sizeOfB = strlen(completeNumber2);
    /************ Comparando! **********************/

    if(sizeOfA == sizeOfB){
        compareIfEqualSizeForGreater(completeNumber1, completeNumber2, sizeOfA);
    }
    else if(sizeOfA > sizeOfB){
        comparationLogicForGreater1(completeNumber1, sizeOfA);
    }
    else{
        comparationLogicForGreater2(completeNumber2, sizeOfB);
    }
    free(completeNumber1);
    free(completeNumber2);

}
void compareIfEqualSizeForMinor(char *completeNumber1, char *completeNumber2, int size){
    int startCounter1 = 0;
    int startCounter2 = 0;
    int signal = 1; //Posi
    int i = 0;
    /********* Seto os contadores para aonde começam os números, ignorando os zeros ********/
    while(completeNumber1[i] == '0'){
        startCounter1++;
        i++;
    }
    i = 0;
    while(completeNumber2[i] == '0'){
        startCounter2++;
        i++;
    }
    /************ Se o primeiro é negativo e o segundo não, logo 1o < 2o ************/
    if((completeNumber1[startCounter1] == '-') && (completeNumber2[startCounter2] != '-')){
        printf("Resultado :: True\n");
        return;
    }
    /************ Se o segundo é negativo e o primeiro não, logo 2o < 1o ************/
    else if((completeNumber1[startCounter1] != '-') && (completeNumber2[startCounter2] == '-')){
        printf("Resultado :: False\n");
        return;
    }
    /************ Se os dois forem negativos, ligo a flag signal e vou pro próximo número ************/
    else if((completeNumber1[startCounter1] == '-') && (completeNumber2[startCounter2] == '-')){
        completeNumber1[startCounter1] = '0';
        completeNumber2[startCounter2] = '0';
        signal = -1;
        startCounter1++;
        startCounter2++;
    }
    char partionedNumber1[5];
    char partionedNumber2[5];
    int j = 0;
    int k = 0; 
    while(size){
        strcpy(partionedNumber1, "");
        strcpy(partionedNumber2, "");
        for(int i = 0; i < 4; i++){
            partionedNumber1[i] = completeNumber1[j];
            partionedNumber2[i] = completeNumber2[k];
            j++;
            k++;
        }

        int parseInt1 = atoi(partionedNumber1)*signal;
        int parseInt2 = atoi(partionedNumber2)*signal;
        if(parseInt1 == parseInt2){
            size--;
            continue;
        }
        else if(parseInt1 < parseInt2){
            printf("Resultado :: True\n");
            return;
        }
        if(parseInt1 > parseInt2){
            printf("Resultado :: False\n");
            return;
        }
    }
}
void seeIfTheNumberIsMinor(LINKEDLIST *firstBigNumberLL, LINKEDLIST *secondBigNumberLL){
    /*************Pegando o tamanho do maior número pela chave ***********/
    int sizeOfTheBiggest = (getTheBiggestNumberSize(getTheKey(firstBigNumberLL->end->bignumber), getTheKey(secondBigNumberLL->end->bignumber)));
    /************ Pegando os números e concatenando **********************/
    char *completeNumber1 = (char*) malloc(sizeOfTheBiggest*sizeof(char));    
    char *completeNumber2 = (char*) malloc(sizeOfTheBiggest*sizeof(char));
    getTheCompleteNum(completeNumber1, getTheKey(firstBigNumberLL->end->bignumber), firstBigNumberLL);
    getTheCompleteNum(completeNumber2, getTheKey(secondBigNumberLL->end->bignumber), secondBigNumberLL);
    /************ Atribuindo os tamanhos dos números **********************/
    int sizeOfA = strlen(completeNumber1);
    int sizeOfB = strlen(completeNumber2);
    /************ Comparando! **********************/
    if(sizeOfA == sizeOfB){
        compareIfEqualSizeForMinor(completeNumber1, completeNumber2, sizeOfA);
    }
    else if(sizeOfA > sizeOfB){
        comparationLogicForGreater2(completeNumber1, sizeOfA);
    }
    else{
        comparationLogicForGreater1(completeNumber2, sizeOfB);
    }

    free(completeNumber1);
    free(completeNumber2);

}
void seeIfTheNumbersAreEqual(LINKEDLIST *firstBigNumberLL, LINKEDLIST *secondBigNumberLL){
    /*************Pegando o tamanho do maior número pela chave ***********/
    int sizeOfTheBiggest = (getTheBiggestNumberSize(getTheKey(firstBigNumberLL->end->bignumber), getTheKey(secondBigNumberLL->end->bignumber)));
    /************ Pegando os números e concatenando **********************/
    char *completeNumber1 = (char*) malloc(sizeOfTheBiggest*sizeof(char));    
    char *completeNumber2 = (char*) malloc(sizeOfTheBiggest*sizeof(char));
    getTheCompleteNum(completeNumber1, getTheKey(firstBigNumberLL->end->bignumber), firstBigNumberLL);
    getTheCompleteNum(completeNumber2, getTheKey(secondBigNumberLL->end->bignumber), secondBigNumberLL);
    /************ Comparando! **********************/
    if(strcmp(completeNumber1, completeNumber2) == 0){
        printf("Resultado :: True\n");
    }
    else{
        printf("Resultado :: False\n");
    }
}
