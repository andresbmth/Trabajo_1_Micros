#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"

void mostrar_valores(long int valores[]){
    int i;
    printf("\n");
    for(i=0;i<12;i++){
        printf("R%d:%d\t",i,&valores[i]);
        if(i==3||i==7){
            printf("\n");
        }
    }
}
