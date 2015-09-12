#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mostrar.h"
#include "ALU.h"
#include "curses.h"
#include "desplazamiento.h"
#include "branch.h"



int main()
{
	uint32_t registro[16]={2,4,5,0,0,0,0,0,0,0,0,0,0,0,0};
	char R_bandera[4];
	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */
    start_color();	/* Permite manejar colores */
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);	/* Pair 1 -> Texto verde fondo Negro */
    init_pair(2,COLOR_YELLOW,COLOR_BLACK);


    attron(COLOR_PAIR(1));  /* Activa el color morado para el texto y negro para el fondo Pair 1*/
    mostrar_valores(registro);

    ADD(&registro[0],registro[1],registro[2],R_bandera);
	move(6,17);
    attron(COLOR_PAIR(2));
    printw("Resultados obtenidos de las operaciones ADD=\n %d",registro[0]);
    refresh();
    getch();
    endwin();

    mostrar_valores(registro);
	return 0;
}
