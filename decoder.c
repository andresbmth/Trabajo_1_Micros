#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mostrar.h"
#include "ALU.h"
#include "curses.h"
#include "desplazamiento.h"
#include "branch.h"
#include "decoder.h"
#include "memory.h"

#define SP 13
#define LR 14
#define PC 15
#define TAM_MEMORY 320

void decodeInstruction(instruction_t instruction,uint32_t *Registro,char *R_Banderas,uint8_t *Memory)
{
	if(strcmp(instruction.mnemonic,"ADC")==0||strcmp(instruction.mnemonic,"ADCS")==0){
			ADC(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value],R_Banderas);
	}
	if(strcmp(instruction.mnemonic,"ADD")==0||strcmp(instruction.mnemonic,"ADDS")==0){
		if(instruction.op3_type=='#'){
			ADD(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],instruction.op3_value,R_Banderas);
		}else{
			ADD(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value],R_Banderas);
		}			
	}
	if(strcmp(instruction.mnemonic,"AND")==0||strcmp(instruction.mnemonic,"ANDS")==0){
		if(instruction.op3_type=='#'){
			AND(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],instruction.op3_value,R_Banderas);
		}else{
			AND(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value],R_Banderas);
		}			
	}
	if(strcmp(instruction.mnemonic,"EOR")==0||strcmp(instruction.mnemonic,"EORS")==0){
		if(instruction.op3_type=='#'){
			EOR(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],instruction.op3_value,R_Banderas);
		}else{
			EOR(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value],R_Banderas);
		}			
	}
	if(strcmp(instruction.mnemonic,"MOV")==0||strcmp(instruction.mnemonic,"MOVS")==0){
		if(instruction.op2_type=='#'){
			MOV(Registro,&Registro[instruction.op1_value],instruction.op2_value,R_Banderas);
		}else{
			MOV(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],R_Banderas);
		}
	}
	if(strcmp(instruction.mnemonic,"ORR")==0||strcmp(instruction.mnemonic,"ORRS")==0){
		if(instruction.op3_type=='#'){
			ORR(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],instruction.op3_value,R_Banderas);
		}else{
			ORR(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value],R_Banderas);
		}			
	}
	if(strcmp(instruction.mnemonic,"SUB")==0||strcmp(instruction.mnemonic,"SUBS")==0){
		if(instruction.op3_type=='#'){
			SUB(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],instruction.op3_value,R_Banderas);
		}else{
			SUB(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value],R_Banderas);
		}			
	}
	if(strcmp(instruction.mnemonic,"SBC")==0||strcmp(instruction.mnemonic,"SBCS")==0){
		SBC(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value],R_Banderas);		
	}
	if(strcmp(instruction.mnemonic,"CMN")==0||strcmp(instruction.mnemonic,"CMNS")==0){
		CMN(Registro,Registro[instruction.op1_value],Registro[instruction.op2_value],R_Banderas);
	}
	if(strcmp(instruction.mnemonic,"CMP")==0||strcmp(instruction.mnemonic,"CMPS")==0){
		CMP(Registro,Registro[instruction.op1_value],Registro[instruction.op2_value],R_Banderas);
	}
	if(strcmp(instruction.mnemonic,"MUL")==0||strcmp(instruction.mnemonic,"MULS")==0){
		if(instruction.op3_type=='#'){
			MUL(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],instruction.op3_value,R_Banderas);
		}else{
			MUL(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value],R_Banderas);
		}			
	}
	if(strcmp(instruction.mnemonic,"TST")==0||strcmp(instruction.mnemonic,"TSTS")==0){
			TST(Registro,Registro[instruction.op1_value],Registro[instruction.op2_value],R_Banderas);
	}
	if(strcmp(instruction.mnemonic,"LSLS")==0){
		if(instruction.op3_type=='#'){
			LSL(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],instruction.op3_value,R_Banderas);
		}else{
			LSL(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value],R_Banderas);
		}			
	}
	if(strcmp(instruction.mnemonic,"LSR")==0||strcmp(instruction.mnemonic,"LSRS")==0){
		if(instruction.op3_type=='#'){
			LSR(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],instruction.op3_value,R_Banderas);
		}else{
			LSR(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value],R_Banderas);
		}			
	}
	if(strcmp(instruction.mnemonic,"ROR")==0||strcmp(instruction.mnemonic,"RORS")==0){
		if(instruction.op3_type=='#'){
			ROR(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],instruction.op3_value,R_Banderas);
		}else{
			ROR(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value],R_Banderas);
		}			
	}
	if(strcmp(instruction.mnemonic,"ASR")==0||strcmp(instruction.mnemonic,"ASRS")==0){
		if(instruction.op3_type=='#'){
			ASR(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],instruction.op3_value,R_Banderas);
		}else{
			ASR(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value],R_Banderas);
		}			
	}
	if(strcmp(instruction.mnemonic,"BIC")==0||strcmp(instruction.mnemonic,"BICS")==0){
		BIC(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],R_Banderas);
	}
	if(strcmp(instruction.mnemonic,"MVN")==0||strcmp(instruction.mnemonic,"MVNS")==0){
		MVN(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],R_Banderas);
	}
	if(strcmp(instruction.mnemonic,"RSB")==0||strcmp(instruction.mnemonic,"RSBS")==0){
		RSB(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],0,R_Banderas);		
	}
	if(strcmp(instruction.mnemonic,"NOP")==0||strcmp(instruction.mnemonic,"NOPS")==0){
		NOP(Registro);
	}
	if(strcmp(instruction.mnemonic,"REV")==0||strcmp(instruction.mnemonic,"REVS")==0){
		REV(Registro,&Registro[instruction.op1_value]);
	}
	if(strcmp(instruction.mnemonic,"REVIG")==0||strcmp(instruction.mnemonic,"REVIGS")==0){
		REVIG(Registro,&Registro[instruction.op1_value]);
	}
	if(strcmp(instruction.mnemonic,"REVSH")==0||strcmp(instruction.mnemonic,"REVSHS")==0){
		REVSH(Registro,&Registro[instruction.op1_value]);	
	}
	if(strcmp(instruction.mnemonic,"PUSH")==0){
		PUSH(Registro,Memory,instruction.registers_list);
	}
	if(strcmp(instruction.mnemonic,"POP")==0){
		POP(Registro,Memory,instruction.registers_list);
	}
	if(strcmp(instruction.mnemonic,"BEQ")==0){
		BEQ(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BNE")==0){
		BNE(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BCS")==0){
		BCS(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BCC")==0){
		BCC(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BMI")==0){
		BMI(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BPL")==0){
		BPL(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BVS")==0){
		BVS(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BVC")==0){
		BVC(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BHI")==0){
		BHI(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BLS")==0){
		BLS(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BGE")==0){
		BGE(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BLT")==0){
		BLT(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BGT")==0){
		BGT(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BLE")==0){
		BLE(R_Banderas,Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BAL")==0){
		BAL(Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"BL")==0){
		BL(Registro,instruction.op1_value); 
	}
	if(strcmp(instruction.mnemonic,"BX")==0){
		BX(Registro);
	}
	if(strcmp(instruction.mnemonic,"B")==0){
		B(Registro,instruction.op1_value);
	}
	if(strcmp(instruction.mnemonic,"LDR")==0){
		if(instruction.op3_type=='#'){
		LDR(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],(instruction.op3_value)<<2); 
		}else{
		LDR(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value]);
		}
	}
	if(strcmp(instruction.mnemonic,"LDRB")==0){
		if(instruction.op3_type=='#'){
		LDRB(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],instruction.op3_value); 
		}else{
		LDRB(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value]);
		}
	}
	if(strcmp(instruction.mnemonic,"LDRH")==0){
		if(instruction.op3_type=='#'){
		LDRH(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],(instruction.op3_value)<<1); 
		}else{
		LDRH(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value]);
		}
	}
	if(strcmp(instruction.mnemonic,"LDRSB")==0){
		LDRSB(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value]);
	}
	if(strcmp(instruction.mnemonic,"LDRSH")==0){
		LDRSH(Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value]);
	}
	
	if(strcmp(instruction.mnemonic,"STR")==0){
		if(instruction.op3_type=='#'){
		STR(Memory,Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],(instruction.op3_value)<<2); 
		}else{
		STR(Memory,Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value]);
		}
	}
	
	if(strcmp(instruction.mnemonic,"STRB")==0){
		if(instruction.op3_type=='#'){
		STRB(Memory,Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],(instruction.op3_value)); 
		}else{
		STRB(Memory,Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value]);
		}
	}
	
	if(strcmp(instruction.mnemonic,"STRH")==0){
		if(instruction.op3_type=='#'){
		STRH(Memory,Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],(instruction.op3_value)<<1); 
		}else{
		STRH(Memory,Registro,&Registro[instruction.op1_value],Registro[instruction.op2_value],Registro[instruction.op3_value]);
		}
	}
	
	refresh();
	attroff(COLOR_PAIR(2));
	mostrar_valores(Registro,R_Banderas);	
}


instruction_t getInstruction(char* instStr)
{
	instruction_t instruction=
	{
		.registers_list = {0},
		.op3_type  = 'N',
		.op3_value = 0
	};
	char* split = (char*)malloc(strlen(instStr)+1);
	int num=0;
	
	strcpy(split, instStr);
	/* Obtiene el mnemonico de la instrucción */	
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);
	
	/* Separa los operandos */	
	while (split != NULL)
	{
		switch(num){
			case 1:
				if(split[0] == '{'){
					instruction.op1_type  = split[0];
					split++;
					do{
						if(split[0]=='L')
							instruction.registers_list[14] = 1;
						else if(split[0]=='P')
							instruction.registers_list[15] = 1;
						else
							instruction.registers_list[(uint8_t)strtoll(split+1, NULL, 0)] = 1;
							
						split = strtok(NULL, ",");
					}while(split != NULL);
				}else{
					instruction.op1_type  = split[0];
					instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				}					
				break;
			
			case 2:
				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
			
			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);			
				break;
		}
		if(split != NULL){
			split = strtok(NULL, " ,.");
			num++;
		}	
	}	
	
	if(instruction.op1_type == 'L'){
		instruction.op1_value = 14;
		instruction.op1_type = 'R';
	}
	
	if(instruction.op1_type == '{'){
		instruction.op1_type = 'P';
	}

	free(split);	
	
	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	/* Puntero a un archivo  */
	int lines;	/* Cantidad de líneas del archivo */
	int line=0;	/* Línea leida */
	char buffer[50]; /* Almacena la cadena leida */
		
	fp = fopen(filename, "r");	/* Abrir el archivo como solo lectura */
	if( fp==NULL )
		return -1;	/* Error al abrir el archivo */
	
	lines = countLines(fp);	/* Cantidad de líneas*/
	
	/* Asignación dinámica de memoria para cada instrucción */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}
	
	fclose(fp);	/* Cierra el archivo */

	return lines;
}	


int countLines(FILE* fp)
{
	int lines=0;
	char buffer[50];
	
	while( fgets(buffer, 50, fp) != NULL )
		lines++;
	
	rewind(fp);
	
	return lines;
}