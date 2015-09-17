#include <stdio.h>
#include <stdlib.h>
#include "branch.h"

#define N 0
#define Z 1
#define C 2
#define V 3
#define LR 14
#define PC 15

char BEQ(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if(R_Banderas[Z]==1){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}

char BNE(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if(R_Banderas[Z]==0){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}

char BCS(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if(R_Banderas[C]==1){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}

char BCC(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if(R_Banderas[C]==0){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}

char BMI(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if(R_Banderas[N]==1){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}

char BPL(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if(R_Banderas[N]==0){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}

char BVS(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if(R_Banderas[V]==1){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}

char BVC(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if(R_Banderas[V]==0){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}
char BHI(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if((R_Banderas[C]==1)&&(R_Banderas[Z]==0)){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}

char BLS(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if((R_Banderas[C]==0)||(R_Banderas[Z]==1)){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}

char BGE(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if(R_Banderas[N]==R_Banderas[V]){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}

char BLT(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if(R_Banderas[N]!=R_Banderas[V]){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}

char BGT(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if((R_Banderas[Z]==0)&&(R_Banderas[N]==R_Banderas[V])){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}

char BLE(char *R_Banderas,uint32_t *Registro,uint32_t Posicion){
	if((R_Banderas[Z]==0)||(R_Banderas[N]!=R_Banderas[V])){
		Registro[PC]=Posicion;
		return 1;
	}else{
		return 0;
	}
}

char BAL(uint32_t *Registro,uint32_t Posicion){
	Registro[PC]=Posicion;
	return 1;
}

void BL(uint32_t *Registro,uint32_t Posicion){
	Registro[LR]=Posicion;      
}

void BX(uint32_t *Registro){
	Registro[PC]=Registro[LR];
}