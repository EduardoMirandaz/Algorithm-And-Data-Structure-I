#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"util.h"
#include"person.h"

struct person{
    char cpf[15];
    char name[tam];
    int age;
    float balance;
};

PERSON *createPerson(){
    PERSON *emptyPerson = (PERSON*) calloc(1,sizeof(PERSON));
    if(emptyPerson != NULL){
        return emptyPerson;
    }
    else{
        return NULL;
    }
}

char *getCpf(PERSON *person){
    return person->cpf;
}

void printCpf(PERSON *person){
    int aux = 0;
    if(person->cpf[aux] == '0'){
        while(person->cpf[aux] == '0'){
            aux++;
        }
        for(int i = aux; i <= 11-aux; i++){
            printf("%c", person->cpf[i]);
        }
    }
    else{
        printf("%s", person->cpf);
    }
    printf("\n");

}

char *buildCpf(char *grossCpf, int *i, char* auxStringCpf){
    auxStringCpf = (char*)calloc(12, sizeof(char));
    int j = 0;
    while(grossCpf[(*i)] != ';'){
        if(grossCpf[(*i)] != '.' && grossCpf[(*i)] != '-'){
               auxStringCpf[j] = grossCpf[(*i)];
               j++;
           }
        (*i)++;        
    }
    (*i)+=1; // para sair do ';'
    return auxStringCpf;
}
char *buildName(char *grossName, char *cleanName, int *i){
    cleanName = NULL;
    setbuf(stdin, 0);
    setbuf(stdout, 0);
    int counter = 0;
    while(grossName[(*i)] != ';'){
        (*i)++;
        counter++;
    }
    cleanName = (char*) calloc(counter,sizeof(char));
    counter = 0;
    (*i) = 15;
    while(grossName[(*i)] != ';'){
        cleanName[counter] = grossName[(*i)];
        (*i)++;
        counter++;
    }
    (*i)+=1; // para sair do ';'
    setbuf(stdin, 0);
    setbuf(stdout, 0);
    return cleanName;
}

int buildAge(char *grossAge, int *i){
    setbuf(stdin, 0);
    setbuf(stdout, 0);
    char *year = (char*) calloc(2,sizeof(char));
    year[0] = grossAge[(*i)];
    year[1] = grossAge[(*i)+1];
    (*i)+=3; // pulo os 2 digitos do ano e o ';'
    return(atoi(year));
}

// jeff bezos tem 12 digitos de fortuna
float buildBalance(char *grossBalance, int *i){
    setbuf(stdin, 0);
    setbuf(stdout, 0);
    float signal = 1.0;

    if(grossBalance[(*i)] == '-'){
        signal*= -1;
        (*i)++;
    }
    int counter = 0;
    int start_i = (*i);
    while(grossBalance[(*i)] != '\0'){
        counter++;
        (*i)++;
    }
    char *auxBalance = (char*) calloc(counter, sizeof(char));
    counter = 0;
    (*i) = start_i;
    while(grossBalance[(*i)] != '\0'){
        if(grossBalance[(*i)] != '.'){
            auxBalance[counter] = grossBalance[(*i)];
            counter++;            
        }
        (*i)++;
    }
    float balance = (atof(auxBalance) / 100) * signal;
    return balance;
}


PERSON *inputAndBuildPerson(PERSON *person){
    int stringCounter = 0;
    char *stringWithAttributes = (char*) calloc(tam, sizeof(char));
    if(!scanf(" %[^(\r|\n)]*c", stringWithAttributes)) exit(1);
    char cpf[15], name[80];
    strcpy(person->cpf, buildCpf(stringWithAttributes, &stringCounter, cpf));
    strcpy(person->name, buildName(stringWithAttributes, name, &stringCounter));
    person->age = buildAge(stringWithAttributes, &stringCounter);
    person->balance = buildBalance(stringWithAttributes, &stringCounter);
    
    return person;
}

int deletePerson(PERSON **person)
{
    if (*person != NULL)
    {
        strcpy((*person)->cpf, "");
        free (*person);
        *person = NULL;
        return 1;
    }
    return 0;
}