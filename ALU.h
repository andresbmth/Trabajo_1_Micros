#include <stdint.h>

/**
* \brief Funcion para las banderas
* \param Rd valor resultante de la operacion realizada anteriormente
* \param Rn primer valor de la operacion realizara anteriormente
* \param Rm segundo valor de la operacion realizada anteriormente
* \param *R_Banderas registro donde se almacenan las banderas
*/ 
void Banderas(uint32_t Rd, uint32_t Rn, uint32_t Rm, char *R_Banderas);


/**
* \brief Funcion ADD
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void ADD(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/**
* \brief Funcion AND
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void AND(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/**
* \brief Funcion EOR
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void EOR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/**
* \brief Funcion MOV
* \param *Rd puntero del registro de destino
* \param Rn valor de registro orgien
* \param *R_Banderas registro de las banderas
*/
void MOV(uint32_t *Rd,uint32_t Rn);

/**
* \brief Funcion ORR
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void ORR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/**
* \brief Funcion SUB
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void SUB(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/**
* \brief Funcion CMN
* \param Rn valor del primer registro
* \param Rm valor del segundo registro
* \param *R_Banderas registro de las banderas
*/
void CMN(uint32_t Rn, uint32_t Rm,char *R_Banderas);

/**
* \brief Funcion CMN
* \param Rn valor del primer registro
* \param Rm valor del segundo registro
* \param *R_Banderas registro de las banderas
*/
void CMP(uint32_t Rn, uint32_t Rm,char *R_Banderas);

/**
* \brief Funcion MUL
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void MUL(uint32_t *Rd,uint32_t Rn, uint32_t Rm,char *R_Banderas);

/**
* \brief Funcion TST
* \param Rn valor del primer registro
* \param Rm valor del segundo registro
* \param *R_Banderas registro de las banderas
*/
void TST(uint32_t Rn, uint32_t Rm,char *R_Banderas);