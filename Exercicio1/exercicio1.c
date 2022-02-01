#include"exercicio1.h"

struct dot_{
    float coordinateX;
    float coordinateY;
};

struct distance_{
    float distance;
};

int inputAmountDots(){
    int amountDots = 0;
    if(scanf("%d", &amountDots) != 1) return 0;
    return amountDots;
}

DOT *createDotsVector(int amountDots){
    DOT *dotsVector;
    dotsVector = (DOT*)malloc(amountDots*sizeof(DOT));
    return &dotsVector[0];
}

DISTANCE *createDistanceVector(int amountDots){
    DISTANCE *distancesVector;
    distancesVector = (DISTANCE*)malloc((amountDots-1)*sizeof(DISTANCE));
    return &distancesVector[0];
}

void inputDots(int amountDots, DOT *dotsVector){
    int iteratorForCoordinates = 0;
    while(amountDots > 0){
        if(scanf("%f", &dotsVector[iteratorForCoordinates].coordinateX) != 1) exit(1);
        if(scanf("%f", &dotsVector[iteratorForCoordinates].coordinateY) != 1) exit(1);
        amountDots--;
        iteratorForCoordinates++;
    }
}

void calculateDistance(DOT *dotsVector, DISTANCE *distancesVector, int amountDots){
    int distanceIterator = 0;
    int sumIterator = 0;

    while(amountDots > 1){
        distancesVector[distanceIterator].distance = sqrt(((dotsVector[sumIterator].coordinateX -
                                                   dotsVector[sumIterator+1].coordinateX)*(dotsVector[sumIterator].coordinateX -
                                                   dotsVector[sumIterator+1].coordinateX)) +
                                                   ((dotsVector[sumIterator].coordinateY - 
                                                   dotsVector[sumIterator+1].coordinateY)*(dotsVector[sumIterator].coordinateY - 
                                                   dotsVector[sumIterator+1].coordinateY)));
        amountDots--;
        distanceIterator++;
        sumIterator++;
    }
}

void printFinalDistance(DISTANCE *distancesVector, int amountDots){
    float finalDistance = 0, sumAuxiliar = 0;
    for(int i = 0; i < amountDots-1; i++){
        finalDistance = distancesVector[i].distance + sumAuxiliar;
        sumAuxiliar = finalDistance;
    }
    finalDistance = roundf(finalDistance * 100) / 100;
    printf("%.2f", finalDistance);
}
void freeVectors(DOT *dotsVector, DISTANCE *distancesVector){
    free(dotsVector);
    free(distancesVector);
}
