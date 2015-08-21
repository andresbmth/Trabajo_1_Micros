#include <stdio.h>
#include <stdlib.h>
#include "ALU.h"

void ADD(unsigned long int *R0,unsigned long int R1,unsigned long int R2){
    *R0=R1+R2;
}
void AND(unsigned long int *R0,unsigned long int R1,unsigned long int R2){
    *R0=R1&R2;
}
void EOR(unsigned long int *R0,unsigned long int R1,unsigned long int R2){
    *R0=R1^R2;
}
void MOV(unsigned long int *R0,unsigned long int R1){
    *R0=R1;
}
void ORR(unsigned long int *R0,unsigned long int R1,unsigned long int R2){
    *R0=R1|R2;
}
void SUB(unsigned long int *R0,unsigned long int R1,unsigned long int R2){
    *R0=R1-R2;
}


