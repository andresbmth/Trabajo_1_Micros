#include <stdio.h>
#include <stdlib.h>
#include "ALU.h"

#define N 0
#define Z 1
#define C 2
#define V 3

void Banderas(uint32_t Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas){
	 uint32_t d,n,m;     //variables auxiliares para revisar el bit 31 del registro
	 d=(1<<31)&Rd;
	 n=(1<<31)&Rn;
	 m=(1<<31)&Rm;
	 if(d){
		 R_Banderas[N]=1;    // R_Banderas[0] Hace referencia a la bandera N (resultado negativo)
	 }else{
		 R_Banderas[N]=0;
	 }
	 if(!Rd){
		 R_Banderas[Z]=1;  // R_Banderas[1] hace referencia a la bandera Z (resultado nulo)
	 }else{
		 R_Banderas[Z]=0;
	 } 
	 if((n==m)&&(n==(1<<31))){
		 R_Banderas[C]=1;  // R_Banderas[2] hace referencia a la bandera C (acarreo en el resultado)
	 }
	 if(n!=m){
		 if(!d){
			 R_Banderas[C]=1;
		 }else{
			 R_Banderas[C]=0;
		 }
	 }
	 if((n==m)&&(n!=d)){
		 R_Banderas[V]=1; //R_Banderas[3] hace referencia a la bandera V (sofreflujo)
	 }else{
		 R_Banderas[V]=0;
	 }
}

void ADD(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas){
    *Rd=Rn+Rm;  //suma de registros
	Banderas(*Rd,Rn,Rm,R_Banderas);
}
void AND(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas){
    *Rd=Rn&Rm;  // multiplicacion de registros
	Banderas(*Rd,Rn,Rm,R_Banderas);
}
void EOR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas){
    *Rd=Rn^Rm;  // EOR a nivel de bits
	Banderas(*Rd,Rn,Rm,R_Banderas);
}
void MOV(uint32_t *Rd,uint32_t Rn){
    *Rd=Rn;  // despalazamiento de un resgistro a otro
}
void ORR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas){
    *Rd=Rn|Rm;  // orr a nivel de bits
	Banderas(*Rd,Rn,Rm,R_Banderas);
}
void SUB(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas){
    *Rd=Rn-Rm;   // resta a nivel de bits
	Banderas(*Rd,Rn,Rm,R_Banderas);
}

void CMN(uint32_t Rn, uint32_t Rm,char *R_Banderas){
	Banderas(Rn+Rm,Rn,Rm,R_Banderas);     //ADN sin almacenar, solo modifica banderas
}

void CMP(uint32_t Rn, uint32_t Rm,char *R_Banderas){
	Banderas(Rn-Rm,Rn,Rm,R_Banderas);  //comparar (SUB sin almacenar), solo modifica banderas
}

void MUL(uint32_t *Rd,uint32_t Rn, uint32_t Rm,char *R_Banderas){
	*Rd=Rn*Rm;            //Multiplicacion de registros, solo se alacenan 32 bits menos significativos
	Banderas(*Rd,Rn,Rm,R_Banderas);
}

void TST(uint32_t Rn, uint32_t Rm,char *R_Banderas){
	Banderas(Rn&Rm,Rn,Rm,R_Banderas);  //AND sin almacenacmiento, solo modifica banderas
}


