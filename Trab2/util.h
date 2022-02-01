#ifndef UTIL_H
#define UTIL_H


#define tam 200
#define MAX 400


#define NAME_COLUMN_CSV 1
#define YEAR_COLUMN_CSV 2
#define PRODUCER_COLUMN_CSV 3

#define FALSE 0
#define TRUE 1

#define RUNCODES 1

typedef int boolean;

char *copyString(const char *fonte);
char* throwComma(char* linha, int num);
int string_compare(char *firstStr, char *secondStr);
char *readLine(FILE **textArchive);

#endif //UTIL_H