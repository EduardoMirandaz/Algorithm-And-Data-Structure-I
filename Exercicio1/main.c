#include"exercicio1.h"

int main(){

    int amountDots = inputAmountDots();
    if(amountDots == 0) return 0;
    
    DOT *dotsVector;
    dotsVector = createDotsVector(amountDots);
    DISTANCE *distancesVector;
    distancesVector = createDistanceVector(amountDots);
    
    inputDots(amountDots, dotsVector);
    calculateDistance(dotsVector, distancesVector, amountDots);
    printFinalDistance(distancesVector, amountDots);
    freeVectors(dotsVector, distancesVector);
    return 0;
}