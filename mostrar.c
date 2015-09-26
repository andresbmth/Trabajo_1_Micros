#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "curses.h"
#include "mostrar.h"
#include "ALU.h"

#define N 0
#define Z 1
#define C 2
#define V 3
#define LR 14
#define PC 15
#define TAM_MEMORY 60

void mostrar_valores(uint32_t *Registro,char *R_Banderas){
	int i;
	attron(COLOR_PAIR(1));  
	mvprintw(5,25,"Program Counter");
	mvprintw(5,1,"Registro");
	mvprintw(11,25,"Banderas");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
    for(i=0;i<13;i++){ // se realiza el ciclo para mostrar los registros que van de 1 a 12.
        mvprintw(6+i,1,"R%d: %u",i,Registro[i]);
    }
	mvprintw(6,25,"LR: %d",2*Registro[LR]);
	mvprintw(7,25,"PC: %u",2*Registro[PC]);	
	mvprintw(12,25,"N: %d",R_Banderas[N]);	
	mvprintw(13,25,"Z: %d",R_Banderas[Z]);
	mvprintw(14,25,"C: %d",R_Banderas[C]);
	mvprintw(15,25,"V: %d",R_Banderas[V]);
	attroff(COLOR_PAIR(2));
}

void mostrar_memoria(uint8_t *Memory){
	erase();
	int i;
	attron(COLOR_PAIR(1));
	mvprintw(2,30,"RAM");
	mvprintw(24,60,"Continuar:");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	mvprintw(24,71,"P");
	for(i=0;i<=TAM_MEMORY;i++){
		if(i<=20){
			mvprintw(3+i,0,"%d",Memory[i]);
		}
		if((i>20)&&(i<=40)){
			mvprintw(3+i-20,25,"%d",Memory[i]);
		}
		if(i>40){
			mvprintw(3+i-40,50,"%d",Memory[i]);
		}
	}
	attroff(COLOR_PAIR(2));   //imprime en pantalla la memoria que se realiza con los ciclos 
}