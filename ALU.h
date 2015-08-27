/**
* \brief Funcion ADD
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
*/
void ADD(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
* \brief Funcion AND
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
*/
void AND(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
* \brief Funcion EOR
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
*/
void EOR(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
* \brief Funcion MOV
* \param *Rd puntero del registro de destino
* \param Rn valor de registro orgien
*/
void MOV(uint32_t *Rd,uint32_t Rn);

/**
* \brief Funcion ORR
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
*/
void ORR(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
* \brief Funcion SUB
* \param *Rd puntero del primer registro
* \param Rn valor del segundo registro
* \param Rm valor del tercer registro
*/
void SUB(uint32_t *Rd,uint32_t Rn,uint32_t Rm);