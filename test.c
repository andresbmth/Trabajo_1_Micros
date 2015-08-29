#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mostrar.h"
#include "ALU.h"

int main()
{
	int op;
	uint32_t registro[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	char banderas[4];
	printf("seleccione la opcion a probar 1,2,2,4,5  \n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			mostrar_valores(registro);
		break;
	
	    case 2:
			printf("ingrese dos valores enteros de registros \n");
			scanf("%d",&registro[1]);
			scanf("%d",&registro[2]);
			
			ADD(&registro[0],registro[1],registro[2],&banderas[0]);
			printf("%d valor del resultado \n",registro[0]);
			printf("%d valor del resultado bandera n \n",banderas[0]);
			printf("%d valor del resultado bandera z \n",banderas[1]);
			printf("%d valor del resultado bandera c \n",banderas[2]);
			printf("%d valor del resultado bandera v \n",banderas[3]);
		break;		
	}
    return 0;
}