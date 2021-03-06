#ifndef _IO_H_
#define	_IO_H_

#include <stdint.h>
#include <curses.h>

#define XINIT 10
#define YINIT 5

/*===================================================*/

#define HIGH	1
#define LOW		0	

#define Read	1
#define Write	0

#define BLUEBLACK	10	/*Text Blue Background Black*/
#define REDBLACK	20	/*Text Red Background Black*/
#define WHITEBLACK	30  /*Text White Background White*/

uint8_t irq[16];

typedef struct{
	uint8_t DDR;
	uint8_t PORT;
	uint8_t PIN;
	uint8_t Pins;
	uint8_t Interrupts;
}port_t;

void IOAccess(uint8_t address, uint8_t* data, uint8_t r_w);
void changePinPortA(uint8_t pin, uint8_t value);
void changePinPortB(uint8_t pin, uint8_t value);
void initIO(void);
void showPorts(void);
void showFrame(int x,int y,int w,int h);

#endif /*_IO_H_*/


/** \fn void initIO(void);
* \brief <center><b>Funcion initIO Inicia los puertos de entrada y salida</b></center>
*/
void initIO(void);

/** \fn void changePinPortA(uint8_t pin, uint8_t value);
* \brief <center><b>Funcion changePinPortA realiza los cambios para el pin A</b></center>  
* \param pin puerto de E/S	
* \param value valor del puerto
*/
void changePinPortA(uint8_t pin, uint8_t value);

/** \fn void changePinPortB(uint8_t pin, uint8_t value);
* \brief <center><b>Funcion changePinPortB realiza los cambios para el pin B</b></center>  
* \param pin puerto de E/S	
* \param value valor del puerto
*/
void changePinPortB(uint8_t pin, uint8_t value);

/** \fn void IOAccess(uint8_t address, uint8_t* data, uint8_t r_w);
* \brief <center><b>Funcion IOAccess Escribe en el registro de interrupciones</b></center>  
* \param address direccion de memoria a aceder	
* \param *data direecion de memoria de un registro
* \param r_w parametro de carga o almacenamiento
*/
void IOAccess(uint8_t address, uint8_t* data, uint8_t r_w);

/** \fn void showPorts(void);
* \brief <center><b>Funcion showPorts Muestra en pantalla el estado del puerto</b></center>
*/
void showPorts(void);

/** \fn void showFrame(void);
* \brief <center><b>Funcion showFrame sirve como soporte para showPorts</b></center>
*/
void showFrame(int x,int y,int w,int h);
