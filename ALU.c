#include <stdio.h>
#include <stdlib.h>
#include "ALU.h"

void ADD(long int *R0,long int R1,long int R2){
    *R0=R1+R2;
}
void AND(long int *R0,long int R1,long int R2){
    *R0=R1&R2;
}
void EOR(long int *R0,long int R1,long int R2){
    *R0=R1^R2;
}
void MOV(long int *R0,long int R1){
    *R0=R1;
}
void ORR(long int *R0,long int R1,long int R2){
    *R0=R1|R2;
}
void SUB(long int *R0,long int R1,long int R2){
    *R0=R1-R2;
}


