#include <stdio.h>
#include <stdlib.h>
#include "ALU.h"

void ADD(uint32_t *Rd,uint32_t Rn,uint32_t Rm){
    *Rd=Rn+Rm;  //suma de registros 
}
void AND(uint32_t *Rd,uint32_t Rn,uint32_t Rm){
    *Rd=Rn&Rm;  // multiplicacion de registros
}
void EOR(uint32_t *Rd,uint32_t Rn,uint32_t Rm){
    *Rd=Rn^Rm;  // EOR a nivel de bits
}
void MOV(uint32_t *Rd,uint32_t Rn){
    *Rd=Rn;  // despalazamiento de un resgistro a otro
}
void ORR(uint32_t *Rd,uint32_t Rn,uint32_t Rm){
    *Rd=Rn|Rm;  // orr a nivel de bits
}
void SUB(unsigned long int *R0,unsigned long int R1,unsigned long int R2){
    *Rd=Rn-Rm;   // resta a nivel de bits
}


