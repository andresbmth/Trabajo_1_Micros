#include <stdint.h>

/**
* \brief <center><b>Funcion para las banderas</b></center>
* \param Rd valor resultante de la operacion realizada anteriormente
* \param Rn primer valor de la operacion realizara anteriormente
* \param Rm segundo valor de la operacion realizada anteriormente
* \param *R_Banderas registro donde se almacenan las banderas
*/ 
void Banderas(uint32_t Rd, uint32_t Rn, uint32_t Rm, char *R_Banderas);


/**
* \brief <center><b>Funcion ADD</b></center>
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void ADD(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/**
* \brief <center><b>Funcion AND</b></center>
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void AND(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/**
* \brief <center><b>Funcion EOR</b><center>
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void EOR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/**
* \brief <center><b>Funcion MOV</b></center>
* \param *Rd puntero del registro de destino
* \param Rn valor de registro orgien
* \param *R_Banderas registro de las banderas
*/
void MOV(uint32_t *Rd,uint32_t Rn);

/**
* \brief <center><b>Funcion ORR</b></center>
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void ORR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/**
* \brief <center><b>Funcion SUB</b></center>
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void SUB(uint32_t *Rd,uint32_t Rn,uint32_t Rm,char *R_Banderas);

/**
* \brief <center><b>Funcion CMN</b></center>
* \param Rn valor del primer registro
* \param Rm valor del segundo registro
* \param *R_Banderas registro de las banderas
*/
void CMN(uint32_t Rn, uint32_t Rm,char *R_Banderas);

/**
* \brief <center><b>Funcion CMN</b></center>
* \param Rn valor del primer registro
* \param Rm valor del segundo registro
* \param *R_Banderas registro de las banderas
*/
void CMP(uint32_t Rn, uint32_t Rm,char *R_Banderas);

/**
* \brief <center><b>Funcion MUL</b></center>
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
* \param *R_Banderas registro de las banderas
*/
void MUL(uint32_t *Rd,uint32_t Rn, uint32_t Rm,char *R_Banderas);

/**
* \brief <center><b>Funcion TST</b></center>
* \param Rn valor del primer registro
* \param Rm valor del segundo registro
* \param *R_Banderas registro de las banderas
*/
void TST(uint32_t Rn, uint32_t Rm,char *R_Banderas);