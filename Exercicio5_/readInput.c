#include<stdio.h>
#include"readInput.h"

int readIntInput(){
    int integer = 0;
    if(!scanf("%d", &integer)){
        return -1;
    }
    return integer;
}