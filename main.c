#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mostrar.h"
#include "ALU.h"
#include "curses.h"
#include "desplazamiento.h"
#include "branch.h"
#include "decoder.h"

#define PC 15

int main()
{
	uint32_t Registro[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};	
	char R_Banderas[4]={0,0,0,0};
	int i, num_instructions;
	ins_t read;
	char** instructions;
	instruction_t instruction;
	char ch=0;
	char op=1;
	int v=500;
	
	num_instructions = readFile("code.txt", &read);
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
	border( ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	do{
		attron(COLOR_PAIR(1));
		mvprintw(2,30,"EMULADOR CORTEX-M0");
		mvprintw(5,50,"Instruccion actual");
		mvprintw(21,3,"Paso a paso:");
		mvprintw(21,25,"Automatico:");
		mvprintw(21,47,"Salir:");
		mvprintw(21,63,"Reiniciar:");
		mvprintw(23,13,"Disminuir velocidad:");
		mvprintw(23,43,"Aumentar velocidad:");
		attroff(COLOR_PAIR(1));	
		attron(COLOR_PAIR(2));
		mvprintw(21,16,"P");
		mvprintw(21,37,"A");
		mvprintw(21,54,"E");
		mvprintw(21,74,"R");
		mvprintw(23,34,"V");
		mvprintw(23,63,"B");
		attroff(COLOR_PAIR(2));
		mostrar_valores(Registro,R_Banderas);
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
			v=500;
			timeout(-1);
			op=1;
			erase();
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
			instruction = getInstruction(instructions[Registro[PC]]);
			decodeInstruction(instruction,Registro,R_Banderas);	
		}
	}while(ch!='e');
	
	for(i=0; i<num_instructions; i++){
		free(read.array[i]);
	}	
	free(read.array); 
    endwin();
	return 0;
}