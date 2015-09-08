#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mostrar.h"
#include "ALU.h"

int main()
{
	int op,v;
	uint32_t registro[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	char banderas[4];
	printf("seleccione la opcion 1 para mostrar los valores de los registros\n");
	printf("seleccione la opcion 2 para sumar registros \n");
	printf("seleccione la opcion 3 para multiplicar registros \n");
	printf("seleccione la opcion 4 para Eor a nivel de bits \n");
	printf("seleccione la opcion 5 para desplazar de un registro a otro \n");
	printf("seleccione la opcion 6 para ORR a nivel de bits \n");
	printf("seleccione la opcion 7 para ADN sin almacenar, solo modifica banderas \n");
	printf("seleccione la opcion 8 para comparar (SUB sin almacenar), solo modifica banderas\n");
	printf("seleccione la opcion 9 Multiplicacion de registros, solo se alacenan 32 bits menos significativos\n");
	printf("seleccione la opcion 10 AND sin almacenacmiento, solo modifica banderas\n");
	printf("seleccione la opcion 11 para  LSL desplazamiento logico a la izquierda \n");
	printf("seleccione la opcion 12 para  LSR desplazamiento logico a la derecha \n");
	printf("seleccione la opcion 13 para  ROR rotacion a la derecha \n");
	printf("seleccione la opcion 14 para  ASR desplazamiento aritmetico a la derecha \n");
	printf("seleccione la opcion 15 para  BIC guarda la multiplicacion de dos registros negados \n");
	printf("seleccione la opcion 16 para  MUN guarda la multiplicacion de dos registros negados algo asi\n");
	printf("seleccione la opcion 17 para  RSB niega una direccion \n");
	printf("seleccione la opcion 18 para  NOP da un retardo pero no hace nada \n");
	printf("seleccione la opcion 19 para  REV toma grupos de 8 bits y los desplaza \n");
	printf("seleccione la opcion 20 para  REVIG toma grupos de 16 bits y los agrupa en grupos de dos bytes\n");
	printf("seleccione la opcion 21 para  REVSH extencion con signo\n");
	
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
	
	case 3:
		
	printf("ingrese dos valores enteros de registros \n");
	scanf("%d",&registro[1]);
	scanf("%d",&registro[2]);
		
	AND(&registro[0],registro[1],registro[2],&banderas[0]);
	printf("%d valor del resultado \n",registro[0]);
	printf("%d valor del resultado bandera n \n",banderas[0]);
	printf("%d valor del resultado bandera z \n",banderas[1]);
	printf("%d valor del resultado bandera c \n",banderas[2]);
	printf("%d valor del resultado bandera v \n",banderas[3]);
	
	break;
	
	case 4:
	
	printf("ingrese dos valores enteros de registros \n");
	scanf("%d",&registro[1]);
	scanf("%d",&registro[2]);
	
	EOR(&registro[0],registro[1],registro[2],&banderas[0]);
	printf("%d valor del resultado \n",registro[0]);
	printf("%d valor del resultado bandera n \n",banderas[0]);
	printf("%d valor del resultado bandera z \n",banderas[1]);
	printf("%d valor del resultado bandera c \n",banderas[2]);
	printf("%d valor del resultado bandera v \n",banderas[3]);
	
	
	break;
	
	case 5:
	
	printf("ingrese dos valores enteros de registros \n");
	scanf("%d",&registro[0]);
	scanf("%d",&registro[1]);
	
	MOV(&registro[0],registro[1]);
	
	printf("%d valor del resultado \n",registro[0]);
	printf("%d valor del resultado bandera n \n",banderas[0]);
	printf("%d valor del resultado bandera z \n",banderas[1]);
	printf("%d valor del resultado bandera c \n",banderas[2]);
	printf("%d valor del resultado bandera v \n",banderas[3]);
	
	break;
	
	
	
	case 7:
	
	printf("ingrese dos valores enteros de registros \n");
	scanf("%d",&registro[1]);
	scanf("%d",&registro[2]);
	
	CMN(registro[1],registro[2],&banderas[0]);
	printf("%d valor del resultado \n",registro[0]);
	printf("%d valor del resultado bandera n \n",banderas[0]);
	printf("%d valor del resultado bandera z \n",banderas[1]);
	printf("%d valor del resultado bandera c \n",banderas[2]);
	printf("%d valor del resultado bandera v \n",banderas[3]);

	break;
	
	case 8:
	
	printf("ingrese dos valores enteros de registros \n");
	scanf("%d",&registro[1]);
	scanf("%d",&registro[2]);
	
	CMP(registro[1],registro[2],&banderas[0]);
	printf("%d valor del resultado \n",registro[0]);
	printf("%d valor del resultado bandera n \n",banderas[0]);
	printf("%d valor del resultado bandera z \n",banderas[1]);
	printf("%d valor del resultado bandera c \n",banderas[2]);
	printf("%d valor del resultado bandera v \n",banderas[3]);

	break;
	
	case 9:
	
	printf("ingrese dos valores enteros de registros \n");
	scanf("%d",&registro[1]);
	scanf("%d",&registro[2]);
	
	MUL(&registro[0],registro[1],registro[2],&banderas[0]);
	printf("%d valor del resultado \n",registro[0]);
	printf("%d valor del resultado bandera n \n",banderas[0]);
	printf("%d valor del resultado bandera z \n",banderas[1]);
	printf("%d valor del resultado bandera c \n",banderas[2]);
	printf("%d valor del resultado bandera v \n",banderas[3]);

	break;
	
	case 10:
	
	printf("ingrese dos valores enteros de registros \n");
	scanf("%d",&registro[1]);
	scanf("%d",&registro[2]);
	
	TST(registro[1],registro[2],&banderas[0]);
	printf("%d valor del resultado \n",registro[0]);
	printf("%d valor del resultado bandera n \n",banderas[0]);
	printf("%d valor del resultado bandera z \n",banderas[1]);
	printf("%d valor del resultado bandera c \n",banderas[2]);
	printf("%d valor del resultado bandera v \n",banderas[3]);

	break;
	
	case 11:
	
	printf("ingrese dos valores enteros de registros \n");
	scanf("%d",&registro[1]);
	scanf("%d",&registro[2]);
	
	LSL(&registro[0],registro[1],registro[2]);
	printf("%d valor del resultado \n",registro[0]);


	break;
	
	case 12:
	
	printf("ingrese dos valores enteros de registros \n");
	scanf("%d",&registro[1]);
	scanf("%d",&registro[2]);
	
	LSR(&registro[0],registro[1],registro[2]);
	printf("%d valor del resultado \n",registro[0]);


	break;
	
	
	case 13:
	
	printf("ingrese dos valores enteros de registros \n");
	scanf("%d",&registro[1]);
	scanf("%d",&registro[2]);
	
	ROR(&registro[0],registro[1],registro[2]);
	printf("%d valor del resultado \n",registro[0]);


	break;
	
	case 14:
	
	printf("ingrese dos valores enteros de registros \n");
	scanf("%d",&registro[1]);
	scanf("%d",&registro[2]);
	
	ASR(&registro[0],registro[1],registro[2]);
	printf("%d valor del resultado \n",registro[0]);


	break;

	case 15:
	
	printf("ingrese un valor entero de registro \n");
	scanf("%d",&registro[1]);
	
	BIC(&registro[0],registro[1]);
	printf("%d valor del resultado \n",registro[0]);


	break;
	
	case 16:
	
	printf("ingrese un valor entero de registro \n");
	scanf("%d",&registro[1]);
	
	MUN(&registro[0],registro[1]);
	printf("%d valor del resultado \n",registro[0]);


	break;
	
	case 17:
	
	printf("ingrese un valor entero de registro y un entero v \n");
	scanf("%d",&registro[1]);
	scanf("%d",&v);
	
	RSB(&registro[0],registro[1],v);
	printf("%d valor del resultado \n",registro[0]);


	break;
	
	case 18:
	
	printf("ingrese dos valores enteros de registros \n");
	scanf("%d",&registro[1]);
	scanf("%d",&v);
	
	NOP(&registro[0],registro[1],v);


	break;
	
	case 19:
	
	printf("ingrese un valor entero de registro \n");
	scanf("%d",&registro[1]);
	
	REV(&registro[0],registro[1]);
	printf("%d valor del resultado \n",registro[0]);


	break;
	
	case 20:
	
	printf("ingrese un valor enteros de registro \n");
	scanf("%d",&registro[1]);
	
	REVIG(&registro[0],registro[1]);
	printf("%d valor del resultado \n",registro[0]);


	break;
	
	case 21:
	
	printf("ingrese un valor enteros de registro \n");
	scanf("%d",&registro[1]);
	
	REVSH(&registro[0],registro[1]);
	printf("%d valor del resultado \n",registro[0]);


	break;
	
	
	break;
	}
    
}
