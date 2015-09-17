#include <stdint.h>

/**
* \brief <center><b>Funcion LSL Desplazamiento logico a la izquierda</b></center>
* \param *Registro Puntero al registro
* \param Rd Primer registro
* \param Rn Segundoegundo registro
* \param Rm Tercer registro o valor inmediato
* \param *R_Banderas Puntero al registro de las banderas
*/ 
void LSL(uint32_t *Registro,uint32_t *Rd, uint32_t Rn,uint32_t Rm,char *R_Banderas);

/**
* \brief <center><b>Funcion LSR Desplazamiento logico a la derecha</b></center>
* \param *Registro Puntero al registro
* \param Rd Primer registro
* \param Rn Segundoegundo registro
* \param Rm Tercer registro o valor inmediato
* \param *R_Banderas Puntero al registro de las banderas
*/ 
void LSR(uint32_t *Registro,uint32_t *Rd, uint32_t Rn, uint32_t Rm,char *R_Banderas);

/**
* \brief <center><b>Funcion ROR Para el rotamiento a la derecha</b></center>
* \param *Registro Puntero al registro
* \param Rd Primer registro
* \param Rn Segundoegundo registro
* \param Rm Tercer registro o valor inmediato
* \param *R_Banderas Puntero al registro de las banderas
*/ 
void ROR(uint32_t *Registro,uint32_t *Rd, uint32_t Rn, uint32_t Rm,char *R_Banderas);

/**
* \brief <center><b>Funcion ASR  Desplazamiento aritmetico a la derecha</b></center>
* \param *Registro Puntero al registro
* \param Rd Primer registro
* \param Rn Segundoegundo registro
* \param Rm Tercer registro o valor inmediato
* \param *R_Banderas Puntero al registro de las banderas
*/ 
void ASR(uint32_t *Registro,uint32_t *Rd, uint32_t Rn, uint32_t Rm,char *R_Banderas);


/**
* \brief <center><b>Funcion BIC La cual niega bit a bit un registro y los multiplica</b></center> 
* \param *Registro Puntero al registro
* \param Rd Primer registro
* \param Rm segundo registro
* \param *R_Banderas Puntero al registro de las banderas
*/ 
void BIC(uint32_t *Registro,uint32_t *Rd, uint32_t Rm,char *R_Banderas);

/**
* \brief <center><b>Funcion MUN Niega un para metro bit a bit y lo guarda en otro</b></center> 
* \param *Registro Puntero al registro
* \param Rd Primer registro
* \param Rm Segundo registro 
* \param *R_Banderas Puntero al registro de las banderas
*/ 
void MVN(uint32_t *Registro,uint32_t *Rd, uint32_t Rm,char *R_Banderas);

/**
* \brief <center><b>Funcion RSB Niega un parametro</b></center>  
* \param *Registro Puntero al registro
* \param Rd Primer registro
* \param Rn segundo registro o valor inmediato
* \param t para dar la condicion y negar el registro
* \param *R_Banderas Puntero al registro de las banderas
*/ 
void RSB(uint32_t *Registro,uint32_t *Rd, uint32_t Rn, int inmediato,char *R_Banderas);


/**
* \brief <center><b>Funcion NOP No hace nada en un tiempo o flanco de relojo</b></center>  
* \param *Registro Puntero al registro
*/
void NOP(uint32_t *Registro);


/**
* \brief <center><b>Funcion REV realiza grupos de 8 bits y los rota</b></center>  
* \param *Registro Puntero al registro
* \param Rd Primer registro
* \param Rn Segudo registro o valor inmediato
*/
void REV(uint32_t *Registro,uint32_t *Rd, uint32_t Rn);

/**
* \brief <center><b>Funcion REVIG realiza grupos de 16 bits y los rota</b></center>  
* \param *Registro Puntero al registro
* \param Rd Primer registro
* \param Rn Segudo registro o valor inmediato
*/
void REVIG(uint32_t *Registro,uint32_t *Rd, uint32_t Rn);


/**
* \brief <center><b>Funcion REVSH realiza extension de signo</b></center>
* \param *Registro Puntero al registro
* \param Rd Primer registro
* \param Rn Segudo registro o valor inmediato
*/
void REVSH(uint32_t *Registro,uint32_t *Rd, uint32_t Rn);