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
#include "io.h"

#define SP 13
#define LR 14
#define PC 15
#define TAM_MEMORY 256

int main()
{
	uint32_t Registro[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	uint8_t Memory[TAM_MEMORY];
	uint32_t PCAux=0;
	char R_Banderas[4]={0,0,0,0};
	int i, num_instructions;
	ins_t read;
	char** instructions;
	instruction_t instruction;
	char ch=0;
	char op=1;
	int v=500;
	uint8_t data;
	uint16_t Ins_Decode=0;
	Registro[SP]=TAM_MEMORY;
	for(i=0;i<TAM_MEMORY;i++){
		Memory[i]=255;
	}
	
	num_instructions = readFile("code6.txt", &read);
	if(num_instructions==-1)
		return 0;

	if(read.array==NULL)
		return 0;	

	instructions = read.array;   // Arreglo con las instrucciones 
	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */
    start_color();	/* Permite manejar colores */
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);	/* Pair 1 -> Texto verde fondo Negro */
    init_pair(2,COLOR_WHITE,COLOR_BLACK);
	initIO();	// Inicializa los puertos de E/S
	do{
		init_pair(1, COLOR_YELLOW, COLOR_BLACK);
		init_pair(2,COLOR_WHITE,COLOR_BLACK);
		attron(COLOR_PAIR(1));
		mvprintw(2,30,"EMULADOR CORTEX-M0");
		mvprintw(5,50,"Instruccion actual");
		mvprintw(8,50,"Codificacion hexadesimal");
		mvprintw(21,3,"Paso a paso:");
		mvprintw(21,25,"Automatico:");
		mvprintw(21,47,"Salir:");
		mvprintw(21,63,"Reiniciar:");
		mvprintw(23,1,"Disminuir velocidad:");
		mvprintw(23,30,"Aumentar velocidad:");
		mvprintw(23,58,"RAM:");
		mvprintw(23,68,"E/S:");
		attroff(COLOR_PAIR(1));	
		attron(COLOR_PAIR(2));
		mvprintw(21,16,"P");
		mvprintw(21,37,"A");
		mvprintw(21,54,"E");
		mvprintw(21,74,"R");
		mvprintw(23,22,"V");
		mvprintw(23,50,"B");
		mvprintw(23,63,"M");
		mvprintw(23,73,"N");
		mvprintw(9,50,"%.4X",Ins_Decode);
		attroff(COLOR_PAIR(2));
		mostrar_valores(Registro,R_Banderas);
		mvprintw(6,50,"%s",instructions[PCAux]);
		ch=getch();
		if((ch=='v')&&(v<=3000)){
			v+=100;
		}
		if((ch=='b')&&(v>200)){
			v-=100;
		}
		if((ch=='a')||(op==0)){
			timeout(v);
			op=0;
		}
		if(ch=='p'){
			timeout(-1);
			op=1;
		}
		if(ch=='r'){
			for(i=0;i<16;i++){
				Registro[i]=0;
			}
			for(i=0;i<4;i++){
				R_Banderas[i]=0;
			}
			for(i=0;i<TAM_MEMORY;i++){
				Memory[i]=255;
			}
			v=500;
			timeout(-1);
			op=1;
			Ins_Decode=0;
			erase();
			Registro[SP]=TAM_MEMORY;
			PCAux=Registro[PC];
		}
		while(ch=='m'){
			mostrar_memoria(Memory);
			ch=getch();
			if(ch=='s'){
				erase();
				break;
			}else{
				ch='m';
			}
		}
		while(ch=='n'){
			erase();
			showPorts();
			ch=getch();
			if(ch=='s'){
				erase();
				break;
			}else{
				ch='n';
			}
		}
		if(ch=='1'){		//prueba 1 para modulos E/S para los puertos A
			data=0x3C;
			IOAccess(0, &data, Write);
			data=0x0F;
			IOAccess(1, &data, Write);	
			data=0xF0;
			IOAccess(2, &data, Write);			
			changePinPortA(0,1);
			changePinPortA(2,1);
			changePinPortA(4,1);
			changePinPortA(6,1);
		}
		if(ch=='2'){		//Prueba 2 para modulos E/S para los puertos B
			data=0xAA;
			IOAccess(10, &data, Write);
			data=0xCC;
			IOAccess(11, &data, Write);	
			data=0xC3;
			IOAccess(12, &data, Write);			
			changePinPortB(1,1);
			changePinPortB(3,1);
			changePinPortB(5,1);
			changePinPortB(7,1);
		}
		if((ch=='p')||(op==0)){
			attron(COLOR_PAIR(1));
			mvprintw(2,30,"EMULADOR CORTEX-M0");
			mvprintw(5,50,"Instruccion actual");
			mvprintw(21,3,"Paso a paso:");
			mvprintw(21,25,"Automatico:");
			mvprintw(21,47,"Salir:");
			mvprintw(21,63,"Reiniciar:");
			attroff(COLOR_PAIR(1));	
			attron(COLOR_PAIR(2));
			mvprintw(21,16,"P");
			mvprintw(21,37,"A");
			mvprintw(21,54,"E");
			mvprintw(21,74,"R");
			attroff(COLOR_PAIR(2));
			erase();
			NVIC(irq,Memory,Registro,R_Banderas);
			instruction = getInstruction(instructions[Registro[PC]]);
			mvprintw(6,50,"%s",instructions[Registro[PC]]);
			PCAux=Registro[PC];
			decodeInstruction(instruction,Registro,R_Banderas,Memory,&Ins_Decode);
			mvprintw(9,50,"%.4X",Ins_Decode);
		}		
	}while(ch!='e');
	for(i=0; i<num_instructions; i++){
		free(read.array[i]);
	}	
	free(read.array); 
    endwin();
	return 0;
}