/** \fn int Bitcount(int *R_activos);
* \brief <center><b>Funcion Bitcount</b></center>
* \param *Registro_activos para visualizar los registros activos
*/
int Bitcount(uint8_t *R_activos);

/** \fn void PUSH(uint32_t *Registro,uint8_t *Memory,int *R_activos);
* \brief <center><b>Funcion PUSH</b></center>
* \param *Registro Puntero al registro
* \param *Memory puntero dirigido a la memoria
* \param *R_activos puntero a los resgistros activos
*/
void PUSH(uint32_t *Registro,uint8_t *Memory,uint8_t *R_activos);

/** \fn void POP(uint32_t *Registro,uint8_t *Memory,int *R_activos);
* \brief <center><b>Funcion POP</b></center>
* \param *Registro Puntero al registro
* \param *Memory puntero dirigido a la memoria
* \param *R_activos puntero a los resgistros activos
*/
void POP(uint32_t *Registro,uint8_t *Memory,uint8_t *R_activos);

/** \fn void LDR(uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);
* \brief <center><b>Funcion LDR</b></center>
* \param *Registro Puntero al registro
* \param *Rt Puntero en el que se almacenara el resultado de la funcion
* \param Rn Valor primer del registro
* \param Rm Valor del segundo registro, puede ser un inmediato convertido en 32 bits
*/
void LDR(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);

/** \fn void LDRB(uint32_t *registros,uint32_t *Rt,uint32_t Rn,uint32_t Rm);
* \brief <center><b>Funcion LDRB</b></center>
* \param *Registro Puntero al registro
* \param *Rt Puntero en el que se almacenara el resultado de la funcion
* \param Rn Valor del primer registro
* \param Rm Valor del segundo registro, puede ser un inmediato convertido en 32 bits
*/
void LDRB(uint8_t *Memory,uint32_t *registros,uint32_t *Rt,uint32_t Rn,uint32_t Rm);

/** \fn void LDRH(uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);
* \brief <center><b>Funcion LDRH</b></center>
* \param *Registro Puntero al registro
* \param *Rt Puntero en el que se almacenara el resultado de la funcion
* \param Rn Valor del primer registro
* \param Rm Valor del segundo registro, puede ser un inmediato convertido en 32 bits
*/
void LDRH(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);

/** \fn void LDRSB(uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);
* \brief <center><b>Funcion LDRSB</b></center>
* \param *Registro Puntero al registro
* \param *Rt Puntero en el que se almacenara el resultado de la funcion
* \param Rn Valor del primer registro
* \param Rm Valor del segundo registro
*/
void LDRSB(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);

/** \fn void LDRSH(uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);
* \brief <center><b>Funcion LDRSH</b></center>
* \param *Registro Puntero al registro
* \param *Rt Puntero en el que se almacenara el resultado de la funcion
* \param Rn Valor del primer registro
* \param Rm Valor del segundo registro
*/
void LDRSH(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);

/** \fn void STR(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);
* \brief <center><b>Funcion STR</b></center>
* \param *Memory puntero dirigido a la memoria
* \param *Registro Puntero al registro
* \param *Rt Puntero en el que se almacenara el resultado de la funcion
* \param Rn Valor del primer registro
* \param Rm Valor del segundo registro, puede ser un inmediato convertido en 32 bits
*/
void STR(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);

/** \fn void void STRB(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);
* \brief <center><b>Funcion STRB</b></center>
* \param *Memory puntero dirigido a la memoria
* \param *Registro Puntero al registro
* \param *Rt Puntero en el que se almacenara el resultado de la funcion
* \param Rn Valor del primer registro
* \param Rm Valor del segundo registro, puede ser un inmediato convertido en 32 bits
*/
void STRB(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);

/** \fn void void STRH(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);
* \brief <center><b>Funcion STRH</b></center>
* \param *Memory puntero dirigido a la memoria
* \param *Registro Puntero al registro
* \param *Rt Puntero en el que se almacenara el resultado de la funcion
* \param Rn Valor del primer registro
* \param Rm Valor del segundo registro, puede ser un inmediato convertido en 32 bits
*/
void STRH(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);

/** \fn void PUSH_INTER(uint8_t *Memory,uint32_t *Registro,char *R_Banderas);
* \brief <center><b>Funcion PUSH_INTER</b></center>
* \param *Memory Puntero dirigido a la memoria
* \param *Registro Puntero al registro
* \param *R_Banderas Puntero al registro de las banderas 
*/
void PUSH_INTER(uint8_t *Memory,uint32_t *Registro,char *R_Banderas);

/** \fn void POP_INTER(uint8_t *Memory,uint32_t *Registro,char *R_Banderas);
* \brief <center><b>Funcion POP_INTER</b></center>
* \param *Memory Puntero dirigido a la memoria
* \param *Registro Puntero al registro
* \param *R_Banderas Puntero al registro de las banderas 
*/
void POP_INTER(uint8_t *Memory,uint32_t *Registro,char *R_Banderas);

/** \fn void NVIC(uint8_t *irq,uint8_t *Memory,uint32_t *Registro,char *R_Banderas);
* \brief <center><b>Funcion NVIC</b></center>
* \param *irq Puntero dirigido a el arreglo que indica las instruciones
* \param *Memory Puntero dirigido a la memoria
* \param *Registro Puntero al registro
* \param *R_Banderas Puntero al registro de las banderas 
*/
void NVIC(uint8_t *irq,uint8_t *Memory,uint32_t *Registro,char *R_Banderas);
