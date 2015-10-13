#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "memory.h"

#define N 0
#define Z 1
#define C 2
#define V 3

#define SP 13
#define LR 14
#define PC 15
#define TAM_MEMORY 320

int Bitcount(uint8_t *R_activos){
	int i;
	int count=0;
	for(i=0;i<8;i++){
		if(R_activos[i]==1){
			count++;
		}
	}
	if(R_activos[LR]==1){
		count++;
	}
	return count;  // retorna los registros activos 
}

void PUSH(uint32_t *Registro,uint8_t *Memory,uint8_t *R_activos){
	int i;
	uint32_t address;
	address=Registro[SP]-4*Bitcount(R_activos);
	for(i=0;i<8;i++){
		if(R_activos[i]==1){
			Memory[address]=(uint8_t)Registro[i];
			Memory[address+1]=(uint8_t)(Registro[i]>>8);
			Memory[address+2]=(uint8_t)(Registro[i]>>16);
			Memory[address+3]=(uint8_t)(Registro[i]>>24);
			address+=4;
		}
	}
	if(R_activos[LR]==1){
		Memory[address]=(uint8_t)Registro[LR];
		Memory[address+1]=(uint8_t)(Registro[LR]>>8);
		Memory[address+2]=(uint8_t)(Registro[LR]>>16);
		Memory[address+3]=(uint8_t)(Registro[LR]>>24);
		address+=4;
	}
	Registro[SP]=Registro[SP]-4*Bitcount(R_activos);
	Registro[PC]++;
}

void POP(uint32_t *Registro,uint8_t *Memory,uint8_t *R_activos){
	int i;
	uint32_t address;
	address=Registro[SP];
	for(i=0;i<8;i++){
		if(R_activos[i]==1){
			Registro[i]=0;
			Registro[i]=Registro[i]|(((uint32_t)Memory[address]));
			Registro[i]=Registro[i]|(((uint32_t)Memory[address+1])<<8);
			Registro[i]=Registro[i]|(((uint32_t)Memory[address+2])<<16);
			Registro[i]=Registro[i]|(((uint32_t)Memory[address+3])<<24);
			address+=4;
		}
	}
	if(R_activos[PC]==1){
			Registro[PC]=0;
			Registro[PC]=Registro[PC]|(((uint32_t)Memory[address]));
			Registro[PC]=Registro[PC]|(((uint32_t)Memory[address+1])<<8);
			Registro[PC]=Registro[PC]|(((uint32_t)Memory[address+2])<<16);
			Registro[PC]=Registro[PC]|(((uint32_t)Memory[address+3])<<24);
	}
	Registro[SP]=Registro[SP]+4*Bitcount(R_activos);
	Registro[PC]++;
}

void LDR(uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm){
	*Rt=Rn+Rm;
	Registro[PC]++;
}

void LDRB(uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm){
	*Rt=(Rn+Rm);
	Registro[PC]++;
}

void LDRH(uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm){
	*Rt=(Rn+Rm);
	Registro[PC]++;
}

void LDRSB(uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm){
	*Rt=(uint32_t)(Rn+Rm);
	Registro[PC]++;
}

void LDRSH(uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm){
	*Rt=(uint32_t)(Rn+Rm);
	Registro[PC]++;
}

void STR(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm){
	Memory[Rn+Rm]=(uint8_t)(*Rt);
	Memory[Rn+Rm+1]=(uint8_t)(*Rt>>8);
	Memory[Rn+Rm+2]=(uint8_t)(*Rt>>16);
	Memory[Rn+Rm+3]=(uint8_t)(*Rt>>24);
	Registro[PC]++;
}

void STRB(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm){
	Memory[Rn+Rm]=(uint8_t)(*Rt);
	Registro[PC]++;
}

void STRH(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm){
	Memory[Rn+Rm]=(uint8_t)(*Rt);
    Memory[Rn+Rm+1]=(uint8_t)(*Rt>>8);
	Registro[PC]++;
}

void PUSH_INTER(uint8_t *Memory,uint32_t *Registro,char *R_Banderas){
	int i;
	uint32_t address;
	address=Registro[SP]-4*16;
	for(i=0;i<16;i++){
		if(i!=SP){
			Memory[address]=(uint8_t)Registro[i];
			Memory[address+1]=(uint8_t)(Registro[i]>>8);
			Memory[address+2]=(uint8_t)(Registro[i]>>16);
			Memory[address+3]=(uint8_t)(Registro[i]>>24);
			address+=4;
		}
	}
	
	Memory[address]=(uint8_t)R_Banderas[N];
	Memory[address+1]=(uint8_t)R_Banderas[Z];
	Memory[address+2]=(uint8_t)R_Banderas[C];
	Memory[address+3]=(uint8_t)R_Banderas[V];
	
	Registro[SP]=Registro[SP]-4*16;
}

void POP_INTER(uint8_t *Memory,uint32_t *Registro,char *R_Banderas){
	int i;
	uint32_t address;
	address=Registro[SP];
	for(i=0;i<16;i++){
		if(i!=SP){
			Registro[i]=0;
			Registro[i]=Registro[i]|(((uint32_t)Memory[address]));
			Registro[i]=Registro[i]|(((uint32_t)Memory[address+1])<<8);
			Registro[i]=Registro[i]|(((uint32_t)Memory[address+2])<<16);
			Registro[i]=Registro[i]|(((uint32_t)Memory[address+3])<<24);
			address+=4;
		}
	}
	
	R_Banderas[N]=(char)Memory[address];
	R_Banderas[Z]=(char)Memory[address+1];
	R_Banderas[C]=(char)Memory[address+2];
	R_Banderas[V]=(char)Memory[address+3];
	
	Registro[SP]=Registro[SP]+4*16;
}

void NVIC(int *I,uint8_t *Memory,uint32_t *Registro,char *R_Banderas){
	int i;
	PUSH_INTER(Memory,Registro,R_Banderas);
	for(i=0;i<5;i++){
		if((I[i]=1)&&(i==0)){
			// Se ejecuta la instruccion correspondiente
		}
		if((I[i]=1)&&(i==1)){
			// Se ejecuta la instruccion correspondiente
		}
		if((I[i]=1)&&(i==2)){
			// Se ejecuta la instruccion correspondiente
		}
		if((I[i]=1)&&(i==3)){
			// Se ejecuta la instruccion correspondiente
		}
		if((I[i]=1)&&(i==4)){
			// Se ejecuta la instruccion correspondiente
		}
	}
	POP_INTER(Memory,Registro,R_Banderas);
}