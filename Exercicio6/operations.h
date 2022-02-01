#ifndef OPERATIONS_H
#define OPERATIONS_H
#include"person.h"
#include"tree.h"

int readIntInput();
char readCharInput();
char *readCpf(char *cpf);
void makeTheOperations (char operation, PERSON *person, TREE *tree);
#endif 