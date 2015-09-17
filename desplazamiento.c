#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "desplazamiento.h"
#include "ALU.h"
#define PC 15


void LSL(uint32_t *Rd, uint32_t Rn, uint32_t Rm,char *R_Banderas){
	*Rd=Rn<<Rm;
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	Bandera_C(*Rd,Rn,Rm,R_Banderas);
	Rd[PC]+=2;
}

void LSR(uint32_t *Rd, uint32_t Rn, uint32_t Rm,char *R_Banderas){
	*Rd=Rn>>Rm;
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	Bandera_C(*Rd,Rn,Rm,R_Banderas);
	Rd[PC]+=2;
}

void ROR(uint32_t *Rd, uint32_t Rn, uint32_t Rm,char *R_Banderas){
	uint32_t d;
	d=Rn>>Rm;
	*Rd=Rn<<(31-Rm);
	*Rd=*Rd|d;
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	Bandera_C(*Rd,Rn,Rm,R_Banderas);
	Rd[PC]+=2;
}

void ASR(uint32_t *Rd, uint32_t Rn, uint32_t Rm,char *R_Banderas){
	uint32_t d; 
	d=~0<<(31-Rm);
	*Rd=Rn>>Rm;
	*Rd=*Rd|d;
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	Bandera_C(*Rd,Rn,Rm,R_Banderas);
	Rd[PC]+=2;
}

void BIC(uint32_t *Rd, uint32_t Rn,char *R_Banderas){
	*Rd&=~Rn;
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	Bandera_C(*Rd,*Rd,Rn,R_Banderas);
	Rd[PC]+=2;
}

void MVN(uint32_t *Rd, uint32_t Rn,char *R_Banderas){
	*Rd=~Rn;	
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	Bandera_C(*Rd,*Rd,Rn,R_Banderas);
	Rd[PC]+=2;
}

void RSB(uint32_t *Rd, uint32_t Rn, int inmediato,char *R_Banderas){
	inmediato=0;
	*Rd=inmediato-Rn;	
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	Rd[PC]+=2;
}

void NOP(uint32_t *Registro){
	Registro[PC]+=2;
}
 
 void REV(uint32_t *Rd, uint32_t Rn){
	*Rd=Rn<<24;
	*Rd=*Rd|(Rn>>24); 
	Rd[PC]+=2;
 }
 
void REVIG(uint32_t *Rd, uint32_t Rn){
	uint32_t d=255;
	*Rd=Rn<<24;
	*Rd=*Rd|((Rn&(d<<8))<<8);
	Rd[PC]+=2;
}

void REVSH(uint32_t *Rd, uint32_t Rn){
	uint32_t d=255;
	*Rd=Rn<<24;
	*Rd=*Rd|((Rn&(d<<16))<<8);
	Rd[PC]+=2;
}