/**
* \brief Funcion MOV
* \param *Rd puntero del registro de destino
* \param Rn valor de registro orgien
* \param *R_Banderas registro de las banderas
*/ 
void Banderas(uint32_t *Rd, uint32_t Rn, uint32_t Rm, uint32_t,char R_Banderas);


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
void MOV(uint32_t *Rd,uint32_t Rn,char *R_Banderas);

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