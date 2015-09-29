/** \fn int Bitcount(int *R_activos);
* \brief <center><b>Funcion Bitcount</b></center>
* \param *Registro_activos para visualizar los registros activos
*/
int Bitcount(int *R_activos);

/** \fn void PUSH(uint32_t *Registro,uint8_t *Memory,int *R_activos);
* \brief <center><b>Funcion PUSH</b></center>
* \param *Registro Puntero al registro
* \param *Memory puntero dirigido a la memoria
* \param *R_activos puntero a los resgistros activos
*/
void PUSH(uint32_t *Registro,uint8_t *Memory,int *R_activos);

/** \fn void POP(uint32_t *Registro,uint8_t *Memory,int *R_activos);
* \brief <center><b>Funcion POP</b></center>
* \param *Registro Puntero al registro
* \param *Memory puntero dirigido a la memoria
* \param *R_activos puntero a los resgistros activos
*/
void POP(uint32_t *Registro,uint8_t *Memory,int *R_activos);