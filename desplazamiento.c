#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "desplazamiento.h"


void LSL(uint32_t *Rd, uint32_t Rn, uint32_t Rm){
	*Rd=Rn<<Rm;
}

void LSR(uint32_t *Rd, uint32_t Rn, uint32_t Rm){
	*Rd=Rn>>Rm;
}

void ROR(uint32_t *Rd, uint32_t Rn, uint32_t Rm){
	uint32_t d;
	d=Rn>>Rm;
	*Rd=Rn<<(31-Rm);
	*Rd=*Rd|d;
}

void ASR(uint32_t *Rd, uint32_t Rn, uint32_t Rm){
	uint32_t d; 
	d=~0<<(31-Rm);
	*Rd=Rn>>Rm;
	*Rd=*Rd|d;
}
void BIC(uint32_t *Rd, uint32_t Rm){
	*Rd&=~Rm;
}

void MUN(uint32_t *Rd, uint32_t Rm){
	*Rd=~Rm;	
}

void RSB(uint32_t *Rd, uint32_t Rn, int t){
	t=0;
	*Rd=t-Rn;	
}

 void NOP(uint32_t *Rd, uint32_t Rn, int t){
 }
 
 void REV(uint32_t *Rd, uint32_t Rn){
	*Rd=Rn<<24;
	*Rd=*Rd|(Rn>>24); 
 }
 
void REVIG(uint32_t *Rd, uint32_t Rn) {
	uint32_t d=255;
	*Rd=Rn<<24;
	*Rd=*Rd|((Rn&(d<<8))<<8);
}

void REVSH(uint32_t *Rd, uint32_t Rn) {
	uint32_t d=255;
	*Rd=Rn<<24;
	*Rd=*Rd|((Rn&(d<<16))<<8);
}


 
