#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "desplazamiento.h"
#include "ALU.h"
#define PC 15
#define C 2


void LSL(uint32_t *Registro,uint32_t *Rd, uint32_t Rn, uint32_t Rm,char *R_Banderas){
	uint32_t d;
	*Rd=Rn<<Rm;
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	d=(Rn<<(Rm-1))&(1<<31);
	if(d){
		R_Banderas[C]=1;
	}else{
		R_Banderas[C]=0;
	}
	Registro[PC]++;
}

void LSR(uint32_t *Registro,uint32_t *Rd, uint32_t Rn, uint32_t Rm,char *R_Banderas){
	uint32_t d;
	*Rd=Rn>>Rm;
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	d=(Rn>>(Rm-1))&(1);
	if(d){
		R_Banderas[C]=1;
	}else{
		R_Banderas[C]=0;
	}
	Registro[PC]++;
}

void ROR(uint32_t *Registro,uint32_t *Rd, uint32_t Rn, uint32_t Rm,char *R_Banderas){
	uint32_t d;
	d=Rn>>Rm;
	*Rd=Rn<<(31-Rm);
	*Rd=*Rd|d;
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	R_Banderas[C]=0;
	Registro[PC]++;
}

void ASR(uint32_t *Registro,uint32_t *Rd, uint32_t Rn, uint32_t Rm,char *R_Banderas){
	uint32_t d; 
	d=~0<<(31-Rm);
	*Rd=Rn>>Rm;
	*Rd=*Rd|d;
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	d=(Rn>>(Rm-1))&(1);
	if(d){
		R_Banderas[C]=1;
	}else{
		R_Banderas[C]=0;
	}
	Registro[PC]++;
}

void BIC(uint32_t *Registro,uint32_t *Rd, uint32_t Rn,char *R_Banderas){
	*Rd&=~Rn;
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	R_Banderas[C]=0;
	Registro[PC]++;
}

void MVN(uint32_t *Registro,uint32_t *Rd, uint32_t Rn,char *R_Banderas){
	*Rd=~Rn;	
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	R_Banderas[C]=0;
	Registro[PC]++;
}

void RSB(uint32_t *Registro,uint32_t *Rd, uint32_t Rn, int inmediato,char *R_Banderas){
	inmediato=0;
	*Rd=inmediato-Rn;	
	Bandera_N(*Rd,R_Banderas);
	Bandera_Z(*Rd,R_Banderas);
	Registro[PC]++;
}

void NOP(uint32_t *Registro){
	Registro[PC]++;
}
 
 void REV(uint32_t *Registro,uint32_t *Rd){
	uint32_t aux[4];
	int i,j=0;		
	for(i=32;i<<8;i-=8){
		aux[j]=((*Rd<<(32-i))>>24);			
		j++;
	}
	for (i=8;i>=33;i+=8){
		aux[j]=aux[j]<<(32-i);
		j--;
	}
	*Rd=aux[0]+aux[1]+aux[2]+aux[3];
	Registro[PC]++;
 }
 
void REVIG(uint32_t *Registro,uint32_t *Rd){
	uint32_t aux[4];
	int i,j=0;
	for(i=32;i<<16;i-=16){
		aux[j]=((*Rd<<(32-i))>>16);
		j++;
	}
	for (i=16;i>=33;i+=8){
		aux[j]=aux[j]<<(32-i);
		j--;
	}
	*Rd=aux[0]+aux[1];
	Registro[PC]++;
}

void REVSH(uint32_t *Registro,uint32_t *Rd){
	uint32_t aux,d=~0;
	uint8_t aux2;
	aux=*Rd<<16;
	aux2=*Rd;
	aux2=aux2>>7;
	if(aux2==0){
		aux=*Rd>>24;
	}else{
		aux=*Rd>>24;
		d=d<<8;
		aux+=d;
	}
	*Rd=aux;
	Registro[PC]++;
}