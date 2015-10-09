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

void LDRH(uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);
void LDRSB(uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);
void LDRSH(uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);
void STR(uint8_t *Memory,uint32_t *Registro,uint32_t *Rt,uint32_t Rn,uint32_t Rm);