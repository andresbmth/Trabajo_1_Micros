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