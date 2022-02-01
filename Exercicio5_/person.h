#ifndef PERSON_H
#define PERSON_H

typedef struct person PERSON;

PERSON *createPerson();

char *getCpf(PERSON *person);
void printCpf(PERSON *person);
int deletePerson(PERSON **person);

PERSON *inputAndBuildPerson(PERSON *person);

#endif