#include <stdint.h>

/** \fn void Banderas(uint32_t Rd, uint32_t Rn, uint32_t Rm, char *R_Banderas)
* \brief <center><b>Funcion para las banderas</b></center>
* \param Rd valor resultante de la operacion realizada anteriormente
* \param Rn primer valor de la operacion realizara anteriormente
* \param Rm segundo valor de la operacion realizada anteriormente
* \param *R_Banderas registro donde se almacenan las banderas
*/ 
void Banderas(uint32_t Rd, uint32_t Rn, uint32_t Rm, char *R_Banderas);

/** \fn void Bandera_N(uint32_t Rd, char *R_Banderas)
* \brief <center><b>Funcion para la bandera N de negativo</b></center>
* \param Rd valor resultante de la operacion realizada anteriormente
* \param *R_Banderas registro donde se almacenan las banderas
*/ 
void Bandera_N(uint32_t Rd, char *R_Banderas);

/** \fn void Bandera_Z(uint32_t Rd, char *R_Banderas)
* \brief <center><b>Funcion para la bandera Z de cero</b></center>
* \param Rd valor resultante de la operacion realizada anteriormente
* \param *R_Banderas registro donde se almacenan las banderas
*/ 
void Bandera_Z(uint32_t Rd, char *R_Banderas);

/** \fn void Bandera_C(uint32_t Rd, uint32_t Rn, uint32_t Rm, char *R_Banderas)
* \brief <center><b>Funcion para la bandera C de carry</b></center>
* \param Rd valor resultante de la operacion realizada anteriormente
* \param Rn primer valor de la operacion realizara anteriormente
* \param Rm segundo valor de la operacion realizada anteriormente
* \param *R_Banderas registro donde se almacenan las banderas
*/ 
void Bandera_C(uint32_t Rd, uint32_t Rn, uint32_t Rm, char *R_Banderas);

/** \fn void Bandera_V(uint32_t Rd, uint32_t Rn, uint32_t Rm, char *R_Banderas)
* \brief <center><b>Funcion para la bandera V de sobreflujo</b></center>
* \param Rd valor resultante de la operacion realizada anteriormente
* \param Rn primer valor de la operacion realizara anteriormente
* \param Rm segundo valor de la operacion realizada anteriormente
* \param *R_Banderas registro donde se almacenan las banderas
*/ 
void Bandera_V(uint32_t Rd, uint32_t Rn, uint32_t Rm, char *R_Banderas);

/** \fn void ADC(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas)
* \brief <center><b>Funcion ADC Suma con carry</b></center>
* \param *Registro Puntero al registro
* \param *Rd puntero del primer registro
* \param Rn valor de registro 
* \param Rm valor de registro
* \param *R_Banderas registro de las banderas
*/
void ADC(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);  // Suma con carry

/** \fn void ADD(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas)
* \brief <center><b>Funcion ADD Suma</b></center>
* \param *Registro Puntero al registro
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void ADD(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/** \fn void AND(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas)
* \brief <center><b>Funcion AND Multiplicacion logica</b></center>
* \param *Registro Puntero al registro
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void AND(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/** \fn void EOR(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas)
* \brief <center><b>Funcion EOR Exor</b></center>
* \param *Registro Puntero al registro
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void EOR(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/** \fn void MOV(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,char *R_Banderas);
* \brief <center><b>Funcion MOV Mover un valor de registro a otro</b></center>
* \param *Registro Puntero al registro
* \param *Rd puntero del registro de destino
* \param Rn valor de registro orgien
* \param *R_Banderas registro de las banderas
*/
void MOV(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,char *R_Banderas);

/** \fn void ORR(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas)
* \brief <center><b>Funcion ORR Suma logica</b></center>
* \param *Registro Puntero al registro
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void ORR(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/** \fn void SUB(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas)
* \brief <center><b>Funcion SUB Resta </b></center>
* \param *Registro Puntero al registro
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void SUB(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/** \fn void SBC(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas)
* \brief <center><b>Funcion SBC Resta con carry</b></center>
* \param *Registro Puntero al registro
* \param *Rd puntero del registro
* \param Rn valor de registro 
* \param Rm valor de registro
* \param *R_Banderas registro de las banderas
*/
void SBC(uint32_t *Registro,uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);  // Resta con carry

/** \fn void CMN(uint32_t *Registro,uint32_t Rn, uint32_t Rm,char *R_Banderas)
* \brief <center><b>Funcion CMN Suma sin resultado, solo modifica banderas</b></center>
* \param *Registro Puntero al registro
* \param Rn Valor del primer registro
* \param Rm valor del segundo registro
* \param *R_Banderas registro de las banderas
*/
void CMN(uint32_t *Registro,uint32_t Rn, uint32_t Rm,char *R_Banderas);

/** \fn void CMP(uint32_t *Registro,uint32_t Rn, uint32_t Rm,char *R_Banderas)
* \brief <center><b>Funcion CMP Resta sin resultado, solo modifica banderas</b></center>
* \param *Registro Puntero al registro
* \param Rn Valor del primer registro
* \param Rm valor del segundo registro
* \param *R_Banderas registro de las banderas
*/
void CMP(uint32_t *Registro,uint32_t Rn, uint32_t Rm,char *R_Banderas);

/** \fn void MUL(uint32_t *Registro,uint32_t *Rd,uint32_t Rn, uint32_t Rm,char *R_Banderas)
* \brief <center><b>Funcion MUL Multiplicacion de registros</b></center>
* \param *Registro Puntero al registro
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void MUL(uint32_t *Registro,uint32_t *Rd,uint32_t Rn, uint32_t Rm,char *R_Banderas);

/** \fn void TST(uint32_t *Registro,uint32_t Rn, uint32_t Rm,char *R_Banderas);
* \brief <center><b>Funcion TST Multiplicacion logica sin resultado, solo modifica registros</b></center>
* \param *Registro Puntero al registro
* \param Rn Valor del registro
* \param Rm valor del registro
* \param *R_Banderas registro de las banderas
*/
void TST(uint32_t *Registro,uint32_t Rn, uint32_t Rm,char *R_Banderas);

int Bitcount(int *R_activos);
void PUSH(uint32_t *Registros,int R1,int R2,int R3);