#include <stdio.h>
#include <stdlib.h>
#include "branch.h"

#define N 0
#define Z 1
#define C 2
#define V 3
#define LR 14
#define PC 15

void BEQ(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if(R_Banderas[Z]==1){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}

void BNE(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if(R_Banderas[Z]==0){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}

void BCS(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if(R_Banderas[C]==1){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}

void BCC(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if(R_Banderas[C]==0){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}

void BMI(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if(R_Banderas[N]==1){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}

void BPL(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if(R_Banderas[N]==0){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}

void BVS(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if(R_Banderas[V]==1){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}

void BVC(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if(R_Banderas[V]==0){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}
void BHI(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if((R_Banderas[C]==1)&&(R_Banderas[Z]==0)){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}

void BLS(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if((R_Banderas[C]==0)||(R_Banderas[Z]==1)){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}

void BGE(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if(R_Banderas[N]==R_Banderas[V]){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}

void BLT(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if(R_Banderas[N]!=R_Banderas[V]){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}

void BGT(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if((R_Banderas[Z]==0)&&(R_Banderas[N]==R_Banderas[V])){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}

void BLE(char *R_Banderas,uint32_t *Registro,uint32_t Label){
	if((R_Banderas[Z]==0)||(R_Banderas[N]!=R_Banderas[V])){
		Registro[PC]+=Label;
	}else{
		Registro[PC]++;
	}
}

void BAL(uint32_t *Registro,uint32_t Label){
	Registro[PC]+=Label;
}

void BL(uint32_t *Registro,uint32_t Label){
	Registro[LR]=Registro[PC]+2; 
	Registro[PC]+=Label;
}

void BX(uint32_t *Registro){
	Registro[PC]=Registro[LR];
}

void B(uint32_t *Registro,uint32_t Label){
	Registro[PC]+=Label;
}