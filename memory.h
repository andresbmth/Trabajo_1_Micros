/** \fn int Bitcount(int *R_activos);
* \brief <center><b>Funcion Bitcount</b></center>
* \param *Registro_activos para visualizar los registros activos
*/
int Bitcount(int *R_activos);

/** \fn void PUSH(uint32_t *Registro,int R1,int R2,int R3);
* \brief <center><b>Funcion PUSH</b></center>
* \param *Registro Puntero al registro
* \param Rn Valor del registro
* \param Rm valor del registro
* \param *R_Banderas registro de las banderas
*/
void PUSH(uint32_t *Registro,uint8_t *Memory,int *R_activos);

void POP(uint32_t *Registro,uint8_t *Memory,int *R_activos);