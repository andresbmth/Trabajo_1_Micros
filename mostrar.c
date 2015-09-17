#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "curses.h"
#include "mostrar.h"
#include "ALU.h"

void mostrar_valores(uint32_t registro[]){
    int i;
    printf("\n");
    for(i=0;i<16;i++){ // se realiza el ciclo para mostrar los registros que van de 1 a 12.
        printf("R%d:%d\t",i,registro[i]); // imprime los registros ordenadamentete en 3 filas de 4 registros cada una
        if(i==3||i==7||i==11){    // la condición para que cumpla la estetica de las 3 filas y 4 registros en cada una
            printf("\n");
        }
    }
}
//
