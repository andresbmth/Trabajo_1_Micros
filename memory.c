#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "memory.h"

#define SP 13
#define LR 14
#define PC 15
#define TAM_MEMORY 60

int Bitcount(int *R_activos){
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

void PUSH(uint32_t *Registro,uint8_t *Memory,int *R_activos){
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
}

void POP(uint32_t *Registro,uint8_t *Memory,int *R_activos){
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
}