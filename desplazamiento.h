#include <stdint.h>

/**
* \brief <center><b>Funcion LSL Desplazamiento logico a la izquierda</b></center>
* \param Rd Primer registro
* \param Rn Segundoegundo registro
* \param Rm Tercer registro o valor inmediato
*/ 
void LSL(uint32_t *Rd, uint32_t Rn,uint32_t Rm);

/**
* \brief <center><b>Funcion LSR Desplazamiento logico a la derecha</b></center>
* \param Rd Primer registro
* \param Rn Segundoegundo registro
* \param Rm Tercer registro o valor inmediato
*/ 
void LSR(uint32_t *Rd, uint32_t Rn, uint32_t Rm);

/**
* \brief <center><b>Funcion ROR Para el rotamiento a la derecha</b></center>
* \param Rd Primer registro
* \param Rn Segundoegundo registro
* \param Rm Tercer registro o valor inmediato
*/ 
void ROR(uint32_t *Rd, uint32_t Rn, uint32_t Rm);

/**
* \brief <center><b>Funcion ASR  Desplazamiento aritmetico a la derecha</b></center>
* \param Rd Primer registro
* \param Rn Segundoegundo registro
* \param Rm Tercer registro o valor inmediato
*/ 
void ASR(uint32_t *Rd, uint32_t Rn, uint32_t Rm);


/**
* \brief <center><b>Funcion BIC La cual niega bit a bit un registro y los multiplica</b></center> 
* \param Rd Primer registro
* \param Rm segundo registro
*/ 
void BIC(uint32_t *Rd, uint32_t Rm);

/**
* \brief <center><b>Funcion MUN Niega un para metro bbit a bit y lo gurada en otro</b></center> 
* \param Rd Primer registro
* \param Rm Segundo registro 
*/ 
void MUN(uint32_t *Rd, uint32_t Rm);

/**
* \brief <center><b>Funcion RSB Niega un para metro</b></center>  
* \param Rd Primer registro
* \param Rn segundo registro o valor inmediato
* \param t para dar la condicion y negar el registro
*/ 
void RSB(uint32_t *Rd, uint32_t Rn, int t);


/**
* \brief <center><b>Funcion NOP No hace nada en un tiempo o flanco de relojo</b></center>  
* \param Rd Primer registro
* \param Rn Segudo registro o valor inmediato
*/
void NOP(uint32_t *Rd, uint32_t Rn, int t);


/**
* \brief <center><b>Funcion REV realiza grupos de 8 bits y los rota</b></center>  
* \param Rd Primer registro
* \param Rn Segudo registro o valor inmediato
*/
void REV(uint32_t *Rd, uint32_t Rn);

/**
* \brief <center><b>Funcion REVIG realiza grupos de 16 bits y los rota</b></center>  
* \param Rd Primer registro
* \param Rn Segudo registro o valor inmediato
*/
void REVIG(uint32_t *Rd, uint32_t Rn);


/**
* \brief <center><b>Funcion REVSH realiza extension de signo</b></center>
* \param Rd Primer registro
* \param Rn Segudo registro o valor inmediato
*/
void REVSH(uint32_t *Rd, uint32_t Rn);