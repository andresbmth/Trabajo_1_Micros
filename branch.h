#include <stdint.h>

/** \fn void BEQ(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BEQ Salto si es igual</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BEQ(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** \fn void BNE(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BNE Salto si no es igual</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BNE(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** \fn void BCS(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BCS Salto si es mayor o igual (sin signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BCS(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** \fn void BCC(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BCC salto si es menor (sin signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BCC(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** \fn void BMI(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BMI Salto si es negativo</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BMI(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** /fn void BPL(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BPL Salto si es positivo</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BPL(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** \fn void BVS(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BVS Salto si hay sobreflujo</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BVS(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** \fn void BVC(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BVC Salto si no hay sobreflujo</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BVC(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** \fn void BHI(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BHI Salto si es mayor (sin signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BHI(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** \fn void BLS(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BLS Salto si es menor o igual (sin signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BLS(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** \fn void BGE(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BGE Salto si es mayor o igual (con signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BGE(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** \fn void BLT(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BLT Salto si es menor (con signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BLT(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** \fn void BGT(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BGT Salto si es mayor (con signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BGT(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** \fn void BLE(char *R_Banderas,uint32_t *Registro,uint32_t Label)
* \brief <center><b>BLE Salto si es menor o igual (con signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BLE(char *R_Banderas,uint32_t *Registro,uint32_t Label);

/** \fn void BAL(uint32_t *Registro,uint32_t Label)
* \brief <center><b>BAL Salto sin condicion, de cualquier forma</b></center>
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void BAL(uint32_t *Registro,uint32_t Label);

/** \fn void BL(uint32_t *Registro,uint32_t Label)
* \brief <center><b>BL Salto guardando posicion instruccion siguiente en LR</b></center>
* \param *Registro Puntero a el registro 
* \param Label Posicion de salto
*/ 
void BL(uint32_t *Registro,uint32_t Label); 

/** \fn void BX(uint32_t *Registro)
* \brief <center><b>BX Salta a la posicion guardada en LR</b></center>
* \param *Registro Puntero a el registro
*/ 
void BX(uint32_t *Registro);

/** \fn void B(uint32_t *Registro,uint32_t Label)
* \brief <center><b>B Salto sin condicion, de cualquier forma</b></center>
* \param *Registro Puntero a el registro
* \param Label Posicion de salto
*/ 
void B(uint32_t *Registro,uint32_t Label);