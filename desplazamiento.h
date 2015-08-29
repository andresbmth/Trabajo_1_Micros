#include <stdint.h>

/**
* \brief Funcion LSL Desplazamiento logico a la izquierda
* \param Rd Primer registro
* \param Rn Segundoegundo registro
* \param Rm Tercer registro o valor inmediato
*/ 
void LSL(uint32_t *Rd, uint32_t Rn,uint32_t Rm);

/**
* \brief Funcion LSR Desplazamiento logico a la derecha
* \param Rd Primer registro
* \param Rn Segundoegundo registro
* \param Rm Tercer registro o valor inmediato
*/ 
void LSR(uint32_t *Rd, uint32_t Rn, uint32_t Rm);

/**
* \brief Funcion ROR Para el rotamiento a la derecha
* \param Rd Primer registro
* \param Rn Segundoegundo registro
* \param Rm Tercer registro o valor inmediato
*/ 
void ROR(uint32_t *Rd, uint32_t Rn, uint32_t Rm);

/**
* \brief Funcion ASR  Desplazamiento aritmetico a la derecha
* \param Rd Primer registro
* \param Rn Segundoegundo registro
* \param Rm Tercer registro o valor inmediato
*/ 
void ASR(uint32_t *Rd, uint32_t Rn, uint32_t Rm);


/**
* \brief Funcion BIC La cual niega bit a bit un registro y los multiplica 
* \param Rd Primer registro
* \param Rm segundo registro
*/ 
void BIC(uint32_t *Rd, uint32_t Rm);

/**
* \brief Funcion MUN Niega un para metro bbit a bit y lo gurada en otro 
* \param Rd Primer registro
* \param Rm Segundo registro 
*/ 
void MUN(uint32_t *Rd, uint32_t Rm);

/**
* \brief Funcion RSB Niega un para metro  
* \param Rd Primer registro
* \param Rn segundo registro o valor inmediato
* \param t para dar la condicion y negar el registro
*/ 
void RSB(uint32_t *Rd, uint32_t Rn, int t);


/**
* \brief Funcion NOP No hace nada en un tiempo o flanco de relojo  
* \param Rd Primer registro
* \param Rn Segudo registro o valor inmediato
*/
void NOP(uint32_t *Rd, uint32_t Rn, int t);


/**
* \brief Funcion REV realiza grupos de 8 bits y los rota  
* \param Rd Primer registro
* \param Rn Segudo registro o valor inmediato
*/
void REV(uint32_t *Rd, uint32_t Rn);

/**
* \brief Funcion REVIG realiza grupos de 16 bits y los rota  
* \param Rd Primer registro
* \param Rn Segudo registro o valor inmediato
*/
void REVIG(uint32_t *Rd, uint32_t Rn);


/**
* \brief Funcion REVSH realiza extension de signo
* \param Rd Primer registro
* \param Rn Segudo registro o valor inmediato
*/
void REVSH(uint32_t *Rd, uint32_t Rn);

